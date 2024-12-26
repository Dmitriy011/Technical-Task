using UnityEngine;
using UnityEngine.SceneManagement;

public class PauseMenu : MonoBehaviour
{
    public bool pauseGame_isActive;     // ������������ ��������� ��������� ���� �����
    public GameObject pauseGameMenu;    // ��������� �� ������ ���� �����
    public void Resume()
    {
        pauseGameMenu.SetActive(false); // �������� ���� �����
        pauseGame_isActive = false;     // ����� � ���� �� �������
        Time.timeScale = 1f;            // �������������� ��������� ����� ����
    }
    public void Pause()
    {
        pauseGameMenu.SetActive(true);  // ����������� ���� �����
        pauseGame_isActive = true;      // ����� � ����  �������
        Time.timeScale = 0f;            // ��������� ��������� ����� ����
    }
    public void Restart()
    {
        SceneManager.LoadScene("SampleScene");  // ��������� ����� "SampleScene" ����� SceneManager
        pauseGameMenu.SetActive(false);         // �������� ���� �����
        pauseGame_isActive = false;             // ����� �� ������� �
        Time.timeScale = 1f;                    // �������������� ��������� ����� ����
    }
}
