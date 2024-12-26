using UnityEngine;
using UnityEngine.SceneManagement;

public class PauseMenu : MonoBehaviour
{
    public bool pauseGame_isActive;     // Отслеживание состояния активации меню паузы
    public GameObject pauseGameMenu;    // Ссылается на объект меню паузы
    public void Resume()
    {
        pauseGameMenu.SetActive(false); // Скрывает меню паузы
        pauseGame_isActive = false;     // Пауза в игре не активна
        Time.timeScale = 1f;            // Восстановление временной шкалы игры
    }
    public void Pause()
    {
        pauseGameMenu.SetActive(true);  // Открывается меню паузы
        pauseGame_isActive = true;      // Пауза в игре  активна
        Time.timeScale = 0f;            // Остановка временной шкалы игры
    }
    public void Restart()
    {
        SceneManager.LoadScene("SampleScene");  // Загружает сцену "SampleScene" через SceneManager
        pauseGameMenu.SetActive(false);         // Скрывает меню паузы
        pauseGame_isActive = false;             // Пауза не активна п
        Time.timeScale = 1f;                    // Восстановление временной шкалы игры
    }
}
