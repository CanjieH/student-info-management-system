
/*********************************************
 * �ļ�����InfoInput.c
 * ��  ��������ʵ����ѧ����Ϣ¼��ģ�飨����ѧ����Ϣ��¼�롢ɾ���Լ��������˵���
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-5-22
 *********************************************/

#include "InfoInput.h"

extern StuInfo student[N];
extern int count;


/* ��ʾ¼����Ϣ���ܽ��沢����ѡ�� */
void ShowInfoInput()
{
    int i;
    char choice;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }
    while(1)
    {
        for(i = 0; i < 13; i++)
        {
            SetPosition(MARGIN_X + 19, 4 + i);
            printf("                                                    ");
        }
        SetPosition(MARGIN_X + 27, 8);
        printf("��ѡ����Ҫ���еĲ�����");
        SetPosition(MARGIN_X + 27, 10);
        printf("1��ѧ����Ϣ¼��");
        SetPosition(MARGIN_X + 27, 11);
        printf("2��ѧ����Ϣɾ��");
        SetPosition(MARGIN_X + 27, 12);
        printf("3���������˵�");
        if((choice = getch()) == '3')
            break;
        ProcessInfoInput(choice);
    }
}

/* ѧ����Ϣ¼�뺯�� */
void InfoInput()
{
    int i;
    ReadInfo();
    StuInfo *p = student + count;  //ָ��ָ������ĩβ������������Ϣ��ӵ��������һ��ѧ����Ϣ�ĺ���
    ShowOne();

    fflush(stdin);
    SetPosition(MARGIN_X + 35, 8);
    MyFgets(p->prof, 50);                  //רҵ����
    SetPosition(MARGIN_X + 35, 9);
    MyFgets(p->name, 50);                  //��������
    SetPosition(MARGIN_X + 35, 10);
    MyFgets(p->sex, 50);                   //�Ա�����
    SetPosition(MARGIN_X + 35, 11);
    scanf("%d", &(p->clas));               //�༶����
    SetPosition(MARGIN_X + 35, 12);
    scanf("%ld", &(p->num));                //ѧ������
    SetPosition(MARGIN_X + 37, 13);
    scanf("%d", &(p->math_score));         //��ѧ�ɼ�����
    SetPosition(MARGIN_X + 37, 14);
    scanf("%d", &(p->Eng_score));          //Ӣ��ɼ�����
    fflush(stdin);

    for(i = 0; i < 8; i++)
    {
        SetPosition(MARGIN_X + 28, 8 + i);
        printf("                              ");
    }
    SetPosition(MARGIN_X + 24, 10);
    printf("��ϲ����%s��ͬѧ�ĸ�����Ϣ¼��ɹ���", p->name);
    count++;  //ѧ����Ч����+1
    WriteInfo();  //��ѧ����Ϣд���ļ���
    SetPosition(MARGIN_X + 26, 11);
    printf("    Ŀǰ���ݿ�����%dλѧ������Ϣ", count);  //���Դ���
    p = student;
    Sleep(1000);
}

/* ѧ����Ϣɾ������ */
void InfoDel()
{
    int i, j, k;
    ReadInfo();
    ShowTwo();
    StuInfo *p = student;  //ָ��ָ�������е�һ��ѧ������Ϣ
    int num;  //Ҫɾ����ѧ��
    char name[50];  //Ҫɾ��������

    SetPosition(MARGIN_X + 38, 11);
    fflush(stdin);
    scanf("%ld", &num);  //ѧ�ŵ�����
    fflush(stdin);  //�������ջ��棬��ֹ�س���¼���ַ���
    SetPosition(MARGIN_X + 38, 12);
    MyFgets(name, 50);    //����������
    fflush(stdin);

    for(i = 0; i < count; i++, p++)
    {
        if((num == p->num) && (strcmp(name, p->name) == 0))  //���������ѧ�Ŷ�������ȷ
        {
            if(i == count - 1)  //Ҫɾ����ѧ��Ϊ���һλ
            {
                break;
            }
            else  //Ҫɾ����ѧ����Ϊ���һλ���򽫺�һλȡ��ǰһλ
            {
                for(j = i; j < count - 1; j++)
                {
                    student[j] = student[j + 1];
                }
                break;
            }
        }
    }
    for(k = 0; k < 8; k++)  //����
    {
        SetPosition(MARGIN_X + 28, 8 + k);
        printf("                              ");
    }

    if(i == count)  //û���ҵ������
    {
        //printf("%d", count);  //���Դ���
        SetPosition(MARGIN_X + 32, 11);
        printf("ɾ��ʧ�ܣ�û���ҵ�����ˣ�");
    }
    else  //�ҵ���
    {
        SetPosition(MARGIN_X + 36, 11);
        printf("��ϲ��ɾ���ɹ���");
        count--;  //ѧ����Ч����-1
        //printf("%d", count);  //���Դ���
    }
    WriteInfo();  //��ɾ�����ѧ����Ϣд���ļ���
    p = student;
    Sleep(1000);
}

/* ����ѡ���ʵ�� */
void ProcessInfoInput(char choice)
{
    int i;

    switch(choice)
    {
    case '1':  //ѧ����Ϣ��¼��
        InfoInput();
        break;
    case '2':  //ѧ����Ϣɾ��
        InfoDel();
        break;
    case '3':  //�������˵�
        break;
    default:  //������֤
        for(i = 0; i < 5; i++)
        {
            SetPosition(MARGIN_X + 27, 8 + i);
            printf("                       ");
        }
        SetPosition(MARGIN_X + 25, 9);
        printf("�Բ���ֻ������1~3֮������֣�");
        SetPosition(MARGIN_X + 32, 10);
        printf("�밴���������...");
        getch();
    }
}

/* ѡ��1�Ľ��� */
void ShowOne()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                      ");
    }
    SetPosition(MARGIN_X + 20, 4);
    printf("%s", A);
    SetPosition(MARGIN_X + 20, 6);
    printf("%s", A);
    for(i = 0; i < 12; i++)
    {
        SetPosition(MARGIN_X + 20, 5 + i);
        printf("|");
        SetPosition(MARGIN_X + 65, 5 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 16);
    printf("%s", A);
    SetPosition(MARGIN_X + 36, 5);
    printf("ѧ����Ϣ¼��");
    SetPosition(MARGIN_X + 27, 8);
    printf("ר  ҵ��");
    SetPosition(MARGIN_X + 27, 9);
    printf("��  ����");
    SetPosition(MARGIN_X + 27, 10);
    printf("��  ��");
    SetPosition(MARGIN_X + 27, 11);
    printf("��  ����");
    SetPosition(MARGIN_X + 27, 12);
    printf("ѧ  �ţ�");
    SetPosition(MARGIN_X + 27, 13);
    printf("��ѧ�ɼ���");
    SetPosition(MARGIN_X + 27, 14);
    printf("Ӣ��ɼ���");
}

/* ѡ��2�Ľ��� */
void ShowTwo()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                      ");
    }
    SetPosition(MARGIN_X + 20, 4);
    printf("%s", A);
    SetPosition(MARGIN_X + 20, 6);
    printf("%s", A);
    for(i = 0; i < 12; i++)
    {
        SetPosition(MARGIN_X + 20, 5 + i);
        printf("|");
        SetPosition(MARGIN_X + 65, 5 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 16);
    printf("%s", A);
    SetPosition(MARGIN_X + 36, 5);
    printf("ѧ����Ϣɾ��");
    SetPosition(MARGIN_X + 30, 8);
    printf("��������Ҫɾ����������ѧ��");
    SetPosition(MARGIN_X + 32, 11);
    printf("ѧ�ţ�");
    SetPosition(MARGIN_X + 32, 12);
    printf("������");
}

