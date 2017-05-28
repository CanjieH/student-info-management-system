#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED

/*********************************************
 * �ļ�����GameLib.h
 * ��  ������������ѧ����Ϣ����ϵͳ�г��õ�ϵͳ����������������ɫ�������ȣ�
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-4-27
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SEP "-----------------------------------------------------------------------------------"
#define MARGIN_X 20  //��߾�

/* ���ÿ���̨���ڵı��� */
void SetTitle(char *title);
/* �������ֵ�ǰ��ɫ�ͱ���ɫ */
void SetColor(int foreColor, int backColor);
/* ���ù���λ�� */
void SetPosition(int x, int y);
/* ��ʾϵͳ�Ļ�ӭ��Ϣ */
void ShowWelcome();
/* ��ʾ��ӭ�����·���Ϣ */
void ShowInfomation();
/* ��ʾ�û��˵� */
void ShowMainMenu();
/* �������� */
void ClearTotal();
/* �������� */
void ClearPart();

#endif // GAMELIB_H_INCLUDED
