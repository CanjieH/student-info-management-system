#include "NamePassword.h"

/*********************************************
 * �ļ�����NamePassword.c
 * ��  ������������ѧ����Ϣ����ϵͳ�û���½
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-4-27
 *********************************************/

void ShowLogin()  //��½����
{
    int i;
    SetPosition(MARGIN_X + 21, 5);
    printf("-------------------------------------");
    SetPosition(MARGIN_X + 20, 6);
    printf("|");
    SetPosition(MARGIN_X + 58, 6);
    printf("|");
    SetPosition(MARGIN_X + 22, 6);
    printf("************* ��½���� ************");
    SetPosition(MARGIN_X + 21, 7);
    printf("-------------------------------------");
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 20, 7 + i);
        printf("|");
        SetPosition(MARGIN_X + 58, 7 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 12);
    printf("---------------------------------------");
}

int Login()  //�û��������������
{
    char name[50];
    char password[50];
    int i;

    ShowLogin();
    SetPosition(MARGIN_X + 21, 9);
    printf("                                    ");  //�����Ļ
    SetPosition(MARGIN_X + 21, 10);
    printf("                                    ");  //�����Ļ
    SetPosition(MARGIN_X + 25, 9);
    printf("�û�����");
    SetPosition(MARGIN_X + 25, 10);
    printf("��  �룺");
    SetPosition(MARGIN_X + 33, 9);

    fflush(stdin);
    MyFgets(name, 50);
    fflush(stdin);
    SetPosition(MARGIN_X + 33, 10);
    MyFgets(password, 50);
    fflush(stdin);

    if(veriLogin(name, password) == 1)  //�û�����������֤
    {
        SetPosition(MARGIN_X + 26, 9);
        printf("����������ȷ����½�ɹ���");
        SetPosition(MARGIN_X + 26, 10);
        printf("���ڽ���ϵͳ�����Ժ�...");
        Sleep(1000);
        for(i = 0; i < 8; i++)
        {
            SetPosition(MARGIN_X + 20, 5 + i);
            printf("                                             ");
        }
        return veriLogin(name, password);
    }
    else
    {
        SetPosition(MARGIN_X + 25, 9);
        printf("                         ");  //�����Ļ
        SetPosition(MARGIN_X + 25, 10);
        printf("                         ");  //�����Ļ
        SetPosition(MARGIN_X + 26, 9);
        printf("��������������������룡");
        Sleep(1000);
        return veriLogin(name, password);
    }
}

int veriLogin(char name[], char password[])  //�û���������������֤
{
    int result = 0;
    if(strcmp(name, USER_NAME) == 0 && strcmp(password, PASSWORD) == 0)
    {
        result = 1;  //����������ȷ����1
    }
    return result;  //����������󷵻�0
}

void MyFgets(char *name, int maxLen)  //����������û���������
{
    int i;

    fgets(name, maxLen, stdin);
    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }
}
