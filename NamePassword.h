#ifndef NAMEPASSWORD_H_INCLUDED
#define NAMEPASSWORD_H_INCLUDED

/*********************************************
 * �ļ�����NamePassword.h
 * ��  ������������ѧ����Ϣ����ϵͳ�û���½
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-4-27
 *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameLib.h"

#define USER_NAME "powerful"
#define PASSWORD "00000000"

void ShowLogin();  //��½����
int Login();  //�û��������������
int veriLogin(char [], char []);  //�û���������������֤
void MyFgets(char *, int);  //�����û���������

#endif // NAMEPASSWORD_H_INCLUDED
