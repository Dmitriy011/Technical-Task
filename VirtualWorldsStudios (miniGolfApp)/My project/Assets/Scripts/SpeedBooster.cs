using UnityEngine;
using System.Collections;

public class SpeedBooster : MonoBehaviour
{
    public float boostAmount = 10f;  // �������� ���������
    public float boostDuration = 2f; // ����������������� ���������

    private void OnTriggerEnter(Collider other)
    {
        // Debug.Log("Speed booster activated!");

        Rigidbody rb = other.GetComponent<Rigidbody>();     // ���������� ��������� `Rigidbody` �� �������, � ������� ��������� ������������, ��� ����������� ���������� ��� ����������� ����������.
        if (rb != null)                                     // �����������, ������� �� ������� �������� ��������� `Rigidbody`
        {
            StartCoroutine(ApplySpeedBoost(rb));            // ��������� �������� ApplySpeedBoost, ������� �������� �������� ������� �� boostAmount � ����� ���� boostDuration ������� ����� ������������ ����������.
        }
    }

    IEnumerator ApplySpeedBoost(Rigidbody rb)
    {
        rb.velocity *= boostAmount;                         // ������������� ��������

        yield return new WaitForSeconds(boostDuration);     // ������������ ���������� ���� �� 2 ������� (��������� ������� ��������� � ���������� �� ���������� ������������� �������.)
    }
}
