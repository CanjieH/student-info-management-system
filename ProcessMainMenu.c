#include "ProcessMainMenu.h"

/*********************************************
 * 文件名：ProcessMainMenu.c
 * 描  述：用来定义学生信息管理系统中的用户菜单选择进程
 * 创建人：CANJIE
 * 日  期：2017-4-27
 *********************************************/

void ProcessMainMenu(char key)
{
    int i;

    switch(key)
    {
    case '1'://学生信息录入
        ShowInfoInput();
        break;
    case '2'://学生成绩查询
        IDfind();
        break;
    case '3'://打印报表
        InputSearch();
        break;
    case '4'://排名查询
        RankingShowOne();
        break;
    case '5'://* 音乐播放
        music();
        break;
    case '6'://退出系统
        system("cls");
        exit(0);
    }

    for(i = 0; i < 17; i++)  //执行完一个函数后对整个信息界面清屏
    {
        SetPosition(MARGIN_X + 1, 3 + i);
        printf("                                                                                ");
    }
}
