#ifndef INFOINPUT_H_INCLUDED
#define INFOINPUT_H_INCLUDED

/*********************************************
 * �ļ�����InfoInput.h
 * ��  ��������ʵ����ѧ����Ϣ¼��ģ�飨����ѧ����Ϣ��¼�롢ɾ���Լ��������˵���
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-5-22
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "GameLib.h"
#include "NamePassword.h"
#include "ReadInfo.h"
#define A "----------------------------------------------"
#define B "--------------------------------------------"

/* ��ʾ¼����Ϣ���ܽ��沢����ѡ�� */
void ShowInfoInput();
/* ����ѡ���ʵ�� */
void ProcessInfoInput(char);
/* ѧ����Ϣ¼�뺯�� */
void InfoInput();
/* ѡ��1�Ľ��� */
void ShowOne();
/* ѧ����Ϣɾ������ */
void InfoDel();
/* ѡ��2�Ľ��� */
void ShowTwo();

#endif // INFOINPUT_H_INCLUDED
