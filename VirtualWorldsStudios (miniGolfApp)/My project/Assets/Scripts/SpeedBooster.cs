using UnityEngine;
using System.Collections;

public class SpeedBooster : MonoBehaviour
{
    public float boostAmount = 10f;  // Величина ускорения
    public float boostDuration = 2f; // Продолжительность ускорения

    private void OnTriggerEnter(Collider other)
    {
        // Debug.Log("Speed booster activated!");

        Rigidbody rb = other.GetComponent<Rigidbody>();     // Получается компонент `Rigidbody` из объекта, с которым произошло столкновение, для возможности управления его физическими свойствами.
        if (rb != null)                                     // Проверяется, успешно ли удалось получить компонент `Rigidbody`
        {
            StartCoroutine(ApplySpeedBoost(rb));            // Запускает корутину ApplySpeedBoost, которая изменяет скорость объекта на boostAmount и затем ждет boostDuration времени перед продолжением выполнения.
        }
    }

    IEnumerator ApplySpeedBoost(Rigidbody rb)
    {
        rb.velocity *= boostAmount;                         // Увеличивается скорость

        yield return new WaitForSeconds(boostDuration);     // Приостановит выполнение кода на 2 секунды (Позволяет объекту двигаться с ускорением на протяжении определенного времени.)
    }
}
