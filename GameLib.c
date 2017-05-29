#include "GameLib.h"

/*********************************************
 * �ļ�����GameLib.c
 * ��  ����ʵ��Game.h�ж����ѧ����Ϣ����ϵͳ�г��õ�ϵͳ����������������ɫ�������ȣ�
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-4-27
 *********************************************/

 /* ���ÿ���̨���ڵı��� */
void SetTitle(char *title)
{
    SetConsoleTitle(title);
}
/*
 * �������ֱ���ɫ��ǰ��ɫ
 * 0-��ɫ��1-��ɫ��2-��ɫ��3-ǳ��ɫ��4-��ɫ��5-��ɫ��6-��ɫ��7-��ɫ
 * 8-��ɫ��9-ǳ��ɫ��10-ǳ��ɫ��11-��ǳ��ɫ��12-����ɫ��13-����ɫ��14-����ɫ
 * 15-����ɫ
 */
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;  //���
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //����������ɫ
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}
/* ���ù������� */
void SetPosition(int x, int y)
{
    HANDLE winHandle;  //���
    COORD pos = {x, y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù�������
    SetConsoleCursorPosition(winHandle, pos);
}

/************************************************************************************************/

/* ��ʾϵͳ��ӭ���� */
void ShowWelcome()
{
    SetPosition(MARGIN_X, 0);
    printf("%s", SEP);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 20, 1);
    printf("��ӭ�����Ͼ�ũҵ��ѧ��ѧԺѧ����Ϣ����ϵͳ��");
    SetPosition(MARGIN_X + 82, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf("%s", SEP);
}

/* ��ʾ��ӭ�����·���Ϣ */
void ShowInfomation()
{
    int i;
    for(i = 0; i < 17; i++)
    {
        SetPosition(MARGIN_X, 3 + i);
        printf("|");
        SetPosition(MARGIN_X + 82, 3 + i);
        printf("|");
    }
    SetPosition(MARGIN_X, 20);
    printf("%s", SEP);
}

/* ��ʾ�û��˵� */
void ShowMainMenu()
{
    SetPosition(MARGIN_X, 21);
    printf("1��ѧ����Ϣ¼��");
    SetPosition(MARGIN_X, 22);
    printf("2��ѧ���ɼ���ѯ");
    SetPosition(MARGIN_X, 23);
    printf("3����ӡ����");
    SetPosition(MARGIN_X, 24);
    printf("4��������ѯ");
    SetPosition(MARGIN_X, 25);
    printf("5��* �����˻��Ի�");
    SetPosition(MARGIN_X, 26);
    printf("6�����ֲ���");
    SetPosition(MARGIN_X, 27);
    printf("7���˳�ϵͳ");
}

/* �������� */
void ClearTotal()
{
    int i, j;  //������17��������81
    for(i = 0; i < 17; i++)
    {
        for(j = 0; j < 81; j++)
        {
            SetPosition(MARGIN_X + j + 1, 3 + i);
            printf(" ");
        }
    }
}

/* �������� */
void ClearPart()
{
    int i;
    for(i = 0; i < 13; i++)
    {
        SetPosition(MARGIN_X + 19, 4 + i);
        printf("                                                    ");
    }
}








