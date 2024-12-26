using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.UI;

public class LineForce : MonoBehaviour
{
    private Rigidbody rb;                                   // ������ �� ��������� Rigidbody ����

    [SerializeField] public GameObject backSide;            // "������� ���" ����� ����, ��� ��� ����������� � ����� ����� �������

    [SerializeField] private float stopVelocity = 0.05f;    // ��������� ��������, ��� ���������� ������� ������ ���������������
    [SerializeField] private float shotPower;               // �������� �����

    [SerializeField] LineRenderer lineRenderer;             // ��� ����������� ���������� ���� (������ �� ��������� LineRenderer)

    private bool isIdle;                // ��� �����? 
    private bool isAiming;              // ������������ ��� �����?
    private bool isInHole;              // ��� � �����?

    // �������� ���������� ������
    [SerializeField] private Text score_text;   
    private int score;

    [SerializeField] private Image[] stars;         // ����� ����������� (3 ������ �� ����������� ������)
    public GameObject EndGameMenu;                      // ���� ����� ������ (����� ��� � �����)

    [SerializeField] private GameObject[] walls;         // ����� ����

    private void Awake()
    {
        // ����������� ���������� `rb` ��������� `Rigidbody`, �������������� � ���� (������, �� ������� ��������� ������ ������)
        // ��� ��������� �������� ������ � ���������� ��������� � ������� �������.
        rb = GetComponent<Rigidbody>();

        isIdle = true;                  // ��� � ��������� �����
        isAiming = false;               // ��� �� ������������
        isInHole = false;               // ��� �� � �����
        lineRenderer.enabled = false;   // ���������� ���� �� ������������

        backSide.SetActive(true);       // "������� ���" ����� ����, ��� ��� ����� ������� - ������������

        // ����������� ����� � ����� ���� ��� (�� ���� ��������� ������ ����)
        stars[0].enabled = true;
        stars[1].enabled = true;
        stars[2].enabled = true;
        // ��������� ����������� �������� ����
        EndGameMenu.SetActive(false);

        score = 0;  // ���������� ������
    }

    private void FixedUpdate()
    {
        // ���� ���������� �������� �������� ������� ������ ���������� �������� `stopVelocity`
        // (������ �������� ����� �������� ��� ����������� �����������.)
        if (rb.velocity.magnitude < stopVelocity)
        {
            Stop();     // ��������, ��������� � ���������� �������� ����.
        }

        ProcessAim();   // ������� ��������� � ��������� ������������ �������.

        // ����������� ����������� ����� � ����.
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
        // ��������, ��� ��� ��� �� � �������� ������������ ��� ��� ����� �� �����
        if (!isAiming || !isIdle)
        {
            return;
        }

        for (int count_wall = 0; count_wall < walls.Length; ++count_wall)
        {
            walls[count_wall].GetComponent<BoxCollider>().enabled = false;
        }

        // ������� ������� � ������� �����������, �� ������� ��������� ��������� ����
        // Vector3? - "nullable" ��� ������ Vector3, �������� ������������ null, ���� ������� �� ���� �������.
        Vector3? worldPoint = CastMouseClickRay();

        // ��������, ��� worldPoint �� ����� �������� (null)
        if (!worldPoint.HasValue)
        {
            return;
        }

        // ���� ������ ���
        if (Input.GetMouseButton(0))
        {
            DrawLine(worldPoint.Value);     // ������ ����� �� ����� ���������
        }
        else
        {
            Shoot(worldPoint.Value);        // ���� ����
        }
    }

    private void Shoot(Vector3 worldPoint)
    {
        isAiming = false;                   // ������� ������������ ����������
        lineRenderer.enabled = false;       // ���� ����� ���������� ����
        backSide.SetActive(false);          // ���� "������� ���" ����� ����, ��� ��� ����������� (�.�. ������ ���� ��� �������)
        for (int count_wall = 0; count_wall < walls.Length; ++count_wall)
        {
            walls[count_wall].GetComponent<BoxCollider>().enabled = true;
        }

        Vector3 horizontalWorldPoint = new Vector3(worldPoint.x, transform.position.y, worldPoint.z);       // ������� ����� ����� � �������������� ��������� ������������ �������� �������.
        Vector3 direction = -(horizontalWorldPoint - transform.position).normalized;                        // ����������� ������� �� ������� ������� ������� � horizontalWorldPoint � ����������� ���
        float strenght = Vector3.Distance(transform.position, horizontalWorldPoint);                        // ���� �������� - ����������� ����� ����������� �� ������� ������� ������� �� horizontalWorldPoint

        rb.AddForce(direction * strenght * shotPower);  // ���������� ���� �������� � ��������� �����������.

        isIdle = false;     // ������ ������ �� ��������� � ������ �����.
        score++;            // ������������� ���-�� ������ �� 1
    }

    // ����������� ����� �� ������� ������� ������� � ��������� ������� worldPoint � ������� �����.
    private void DrawLine(Vector3 worldPoint)
    {
        // ��������� ������ positions, ���������� ��� �����: ������� ������� ������� (transform.position) � worldPoint, ������� ������ �. � ���. �����, ���� �������� �����
        Vector3[] positions = { transform.position, worldPoint };

        lineRenderer.SetPositions(positions);   // ������������� ������� ����� lineRenderer � ������������ � �������� ����� positions
        lineRenderer.enabled = true;            // �������� ����������� lineRenderer
    }

    // ������ ��������� �������� �������
    private void Stop()
    {
        rb.velocity = Vector3.zero;         // �������� �������� �� ���� ����.
        rb.angularVelocity = Vector3.zero;  // ��������� �������� ������� �� ���� ����.
        isIdle = true;                      // ������ ��������� � ��������� �����
        backSide.SetActive(true);
    }

    private Vector3? CastMouseClickRay()
    {
        // screenMousePosNear � screenMousePosFar ��������� �� ������� � ��������� ���������� ��������� ������.
        // ������������� ������� � ��������� ���������� � ��������� �������� ������ ��� � ����� �. ��� ����, ������� ����������� �� ������� ���� �� ������ � 3��-������ ��-�� ���� ��� ����������� �. ������� � ���������.
        Vector3 screenMousePosFar = new Vector3(Input.mousePosition.x, Input.mousePosition.y, Camera.main.farClipPlane);    // ������, �������������� ������� ���� �� ������ � ��������� �������       
        Vector3 screenMousePosNear = new Vector3(Input.mousePosition.x, Input.mousePosition.y, Camera.main.nearClipPlane);  // ������, �������������� ������� ���� �� ������ � ������� �������  
        Vector3 worldMousePosFar = Camera.main.ScreenToWorldPoint(screenMousePosFar);       //  ����������� ������� ���� �� ��������� ������ � ������� ���������� �� ��������� ���������.
        Vector3 worldMousePosNear = Camera.main.ScreenToWorldPoint(screenMousePosNear);     //  ����������� ������� ���� �� ��������� ������ � ������� ���������� �� ������� ���������.

        RaycastHit hit;     // ������� ���������� hit, ������� �������� ���-�� �������� �����������.

        // ���� ��� ���������� �����-���� ��������� � ������������, �� ���������� � ����� ����������� ������������ � ���������� hit.point � ������������
        // ���� ��� �� ���������� ���������, �� ������� ���������� null.
        if (Physics.Raycast(worldMousePosNear, worldMousePosFar - worldMousePosNear, out hit, float.PositiveInfinity))
        {
            return hit.point;
        }
        else
        {
            return null;
        }
    }

    // ������ ��������� � �����
    private void OnTriggerEnter(Collider other)
    {
        // ���� ������ ������, � ������� ��������� ��������������, ����� ��� "Hole" (�����)
        if (other.tag == "Hole")
        {
            if (isInHole)           // ���� ������ ��� ��������� � �����,  ������������ �� ������
            {
                return;
            }

            if (score > 8)          // ���� ���� ������ 8, �� ����������� ��� ������
            {
                stars[2].enabled = false;
                stars[1].enabled = false;
            }
            else
            {
                if (score > 5)      //���� ���� ������ 5, ����������� ���� ������
                {
                    stars[2].enabled = false;
                }
            }

            EndGameMenu.SetActive(true);    // ������������ ������� ���� EndGameMenu.
            isInHole = true;                // ������ ��������� � ���������.

            rb.velocity = Vector3.zero;     // ������������� ��� ��������.
            gameObject.SetActive(false);    // ����������� ������� ������� ������
        }
    }
}
