#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#include "ProcessMainMenu.h"
#include "NamePassword.h"
#include "ReadInfo.h"

extern int count;  //�����ⲿȫ�ֱ�������ѧ����Ч����

char key;  //�û��ڲ˵���ѡ��

int main()
{
    //system("mode con cols=500 lines=500");
    SetTitle("�Ͼ�ũҵ��ѧ��ѧԺѧ����Ϣ����ϵͳ");
    //system("color 8E");  //�ı䱳��ɫ
    ShowWelcome();
    ShowInfomation();
    while(Login() == 0);
    ShowMainMenu();
    while(1)
    {
        fflush(stdin);
        key = getch();
        fflush(stdin);
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7')
        {
            ProcessMainMenu(key);
        }
    }
}
