#ifndef READINFO_H_INCLUDED
#define READINFO_H_INCLUDED

/*********************************************
 * �ļ�����ReadInfo.h
 * ��  ������������ϵͳ���ļ��Ķ�ȡ��д�룬��������ѧ����Ϣ�ṹ��StuInfo������student����ΪN����50����
 * �Լ���¼ѧ����Ч������ȫ�ֱ���count��
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-5-17
 *
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#define N 100  //ѧ����50��

typedef struct _stuinfo{
    char prof[50];  //רҵ
    char name[50];  //����
    char sex[10];   //�Ա�
    int clas;       //�༶
    long int num;        //ѧ��
    int math_score; //��ѧ�ɼ�
    int Eng_score;  //Ӣ��ɼ�
}StuInfo;

/* д��ѧ����Ϣ�����ļ����� */
void WriteInfo();
/* ���ļ�¼��ѧ����Ϣ���� */
void ReadInfo();


#endif // READINFO_H_INCLUDED
