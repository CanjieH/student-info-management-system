#include "ProcessMainMenu.h"

/*********************************************
 * �ļ�����ProcessMainMenu.c
 * ��  ������������ѧ����Ϣ����ϵͳ�е��û��˵�ѡ�����
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-4-27
 *********************************************/

void ProcessMainMenu(char key)
{
    switch(key)
    {
    case '1'://ѧ����Ϣ¼��
        printf("����1");
        break;
    case '2'://ѧ���ɼ���ѯ
        printf("����2");
        break;
    case '3'://��ӡ����
        printf("����3");
        break;
    case '4'://������ѯ
        printf("����4");
        break;
    case '5'://* �����˻��Ի�
        printf("����5");
        break;
    case '6'://* ���ֲ���
        printf("����6");
        break;
    case '7'://�˳�ϵͳ
        system("cls");
        exit(0);
    }
}
