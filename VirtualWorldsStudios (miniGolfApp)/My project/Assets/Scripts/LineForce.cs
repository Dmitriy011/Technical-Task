using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.UI;

public class LineForce : MonoBehaviour
{
    private Rigidbody rb;                                   // Ссылка на компонент Rigidbody мяча

    [SerializeField] public GameObject backSide;            // "Красный куб" сзади мяча, что мяч остановился и можно снова ударить

    [SerializeField] private float stopVelocity = 0.05f;    // Пороговая скорость, при достижении которой объект останавливается
    [SerializeField] private float shotPower;               // Мощность удара

    [SerializeField] LineRenderer lineRenderer;             // Для отображения индикатора силы (ссылка на компонент LineRenderer)

    private bool isIdle;                // Мяч стоит? 
    private bool isAiming;              // Прицеливание для удара?
    private bool isInHole;              // Мяч в лунке?

    // Счетсчик количества ударов
    [SerializeField] private Text score_text;   
    private int score;

    [SerializeField] private Image[] stars;         // Масив изображений (3 звезды за прохождение уровня)
    public GameObject EndGameMenu;                      // Меню конца уровня (когда мяч в лунке)

    [SerializeField] private GameObject[] walls;         // Масив стен

    private void Awake()
    {
        // Присваивает переменной `rb` компонент `Rigidbody`, присоединенный к иячу (объект, на котором находится данный скрипт)
        // Это позволяет получить доступ к физическим свойствам и методам объекта.
        rb = GetComponent<Rigidbody>();

        isIdle = true;                  // Мяч в состоянии покоя
        isAiming = false;               // Мяч не нацеливается
        isInHole = false;               // Мяч не в лунке
        lineRenderer.enabled = false;   // Инидкактор силы не отображается

        backSide.SetActive(true);       // "Красный куб" сзади мяча, что мяч можно ударить - отображается

        // Изображения звезд в конце игры вкл (но окно окончания уровня выкл)
        stars[0].enabled = true;
        stars[1].enabled = true;
        stars[2].enabled = true;
        // Отключает отображение игрового меню
        EndGameMenu.SetActive(false);

        score = 0;  // Количество ударов
    }

    private void FixedUpdate()
    {
        // Если абсолютное значение скорости объекта меньше порогового значения `stopVelocity`
        // (объект движется очень медленно или практически остановился.)
        if (rb.velocity.magnitude < stopVelocity)
        {
            Stop();     // Действия, связанные с остановкой движения мяча.
        }

        ProcessAim();   // Процесс связанный с механикой прицеливания объекта.

        // Обновляется отображение счета в игре.
        score_text.text = "";
        score_text.text += score.ToString();
    }

    private void OnMouseDown()
    {
        if (isIdle == true)
        {
            isAiming = true;
        }
    }
    private void ProcessAim()
    {
        // Проверка, что мяч уже не в процессе прицеливания или мяч стоит на месте
        if (!isAiming || !isIdle)
        {
            return;
        }

        for (int count_wall = 0; count_wall < walls.Length; ++count_wall)
        {
            walls[count_wall].GetComponent<BoxCollider>().enabled = false;
        }

        // Получим позицию в мировых координатах, на которую указывает указатель мыши
        // Vector3? - "nullable" тип данных Vector3, позволяя использовать null, если позиция не была найдена.
        Vector3? worldPoint = CastMouseClickRay();

        // Проверка, что worldPoint не имеет значения (null)
        if (!worldPoint.HasValue)
        {
            return;
        }

        // Если нажата ЛКМ
        if (Input.GetMouseButton(0))
        {
            DrawLine(worldPoint.Value);     // Рисует линию от текущ положения
        }
        else
        {
            Shoot(worldPoint.Value);        // Удар мяча
        }
    }

    private void Shoot(Vector3 worldPoint)
    {
        isAiming = false;                   // Процесс прицеливания закончился
        lineRenderer.enabled = false;       // Откл линии индикатора силы
        backSide.SetActive(false);          // Откл "красный куб" сзади мяча, что мяч остановился (т.е. нельзя пока что ударить)
        for (int count_wall = 0; count_wall < walls.Length; ++count_wall)
        {
            walls[count_wall].GetComponent<BoxCollider>().enabled = true;
        }

        Vector3 horizontalWorldPoint = new Vector3(worldPoint.x, transform.position.y, worldPoint.z);       // Создаем новую точку в горизонтальной плоскости относительно текущего объекта.
        Vector3 direction = -(horizontalWorldPoint - transform.position).normalized;                        // Направление вектора из текущей позиции объекта к horizontalWorldPoint и нормализует его
        float strenght = Vector3.Distance(transform.position, horizontalWorldPoint);                        // Сила выстрела - вычисляется длина направления от текущей позиции объекта до horizontalWorldPoint

        rb.AddForce(direction * strenght * shotPower);  // Добавление силы выстрела в указанное направление.

        isIdle = false;     // Объект больше не находится в режиме покоя.
        score++;            // Увеличивается кол-во ударов на 1
    }

    // Отображения линии от текущей позиции объекта к указанной позиции worldPoint в игровой сцене.
    private void DrawLine(Vector3 worldPoint)
    {
        // Создается массив positions, содержащий две точки: текущую позицию объекта (transform.position) и worldPoint, который задает т. в мир. коорд, куда нацелена линия
        Vector3[] positions = { transform.position, worldPoint };

        lineRenderer.SetPositions(positions);   // Устанавливает позиции линии lineRenderer в соответствии с массивом точек positions
        lineRenderer.enabled = true;            // Включает отображение lineRenderer
    }

    // Полная остановка движения объекта
    private void Stop()
    {
        rb.velocity = Vector3.zero;         // Обнуляет скорость по всем осям.
        rb.angularVelocity = Vector3.zero;  // Остановка вращения объекта по всем осям.
        isIdle = true;                      // Объект переходит в состояние покоя
        backSide.SetActive(true);
    }

    private Vector3? CastMouseClickRay()
    {
        // screenMousePosNear и screenMousePosFar создаются на ближней и удаленной плоскостях клиппинга камеры.
        // Использование ближней и удаленной плоскостей в рассчетах помогает задать нач и конеч т. для луча, который выпускается от позиции мыши на экране в 3ех-мерное пр-во игры для определения т. пересеч с объектами.
        Vector3 screenMousePosFar = new Vector3(Input.mousePosition.x, Input.mousePosition.y, Camera.main.farClipPlane);    // Вектор, представляющий позицию мыши на экране с удаленным плоским       
        Vector3 screenMousePosNear = new Vector3(Input.mousePosition.x, Input.mousePosition.y, Camera.main.nearClipPlane);  // Вектор, представляющий позицию мыши на экране с ближним плоским  
        Vector3 worldMousePosFar = Camera.main.ScreenToWorldPoint(screenMousePosFar);       //  Преобразует позицию мыши из координат экрана в мировые координаты на удаленной плоскости.
        Vector3 worldMousePosNear = Camera.main.ScreenToWorldPoint(screenMousePosNear);     //  Преобразует позицию мыши из координат экрана в мировые координаты на ближней плоскости.

        RaycastHit hit;     // Создает переменную hit, которая содержит рез-ат лучевого пересечения.

        // Если луч пересекает какой-либо коллайдер в пространстве, то информация о точке пересечения записывается в переменную hit.point и возвращается
        // Если луч не пересекает коллайдер, то функция возвращает null.
        if (Physics.Raycast(worldMousePosNear, worldMousePosFar - worldMousePosNear, out hit, float.PositiveInfinity))
        {
            return hit.point;
        }
        else
        {
            return null;
        }
    }

    // Логика попадания в лунку
    private void OnTriggerEnter(Collider other)
    {
        // Если другой объект, с которым произошло взаимодействие, имеет тег "Hole" (лунка)
        if (other.tag == "Hole")
        {
            if (isInHole)           // Если объект уже находится в лунке,  возвращаемся из метода
            {
                return;
            }

            if (score > 8)          // Если счет больше 8, то отключаются две звезды
            {
                stars[2].enabled = false;
                stars[1].enabled = false;
            }
            else
            {
                if (score > 5)      //Если счет больше 5, отключается одна звезда
                {
                    stars[2].enabled = false;
                }
            }

            EndGameMenu.SetActive(true);    // Активируется игровое меню EndGameMenu.
            isInHole = true;                // Объект находится в отверстии.

            rb.velocity = Vector3.zero;     // Останавливает его движение.
            gameObject.SetActive(false);    // Выключается текущий игровой объект
        }
    }
}
