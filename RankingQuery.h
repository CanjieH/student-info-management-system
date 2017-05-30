#ifndef RANKINGQUERY_H_INCLUDED
#define RANKINGQUERY_H_INCLUDED

/*********************************************
 * �ļ�����RankingQuery.h
 * ��  ����ʵ����ѧ���ɼ����а�Ĳ鿴�������ܳɼ����а񡢵��Ƴɼ����а�
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-5-30
 *********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
#include "ReadInfo.h"

/* ѡ�������С��������н��� */
void RankingShowOne();
/* ����ѡ���ʵ�� */
void ProcessRankingQuery(char);
/* �ܳɼ����а� */
void RankingTotal();
/* �ָ��ߡ���Ŀ���ƵȵĽ���Ԫ�� */
void RankingShowTwo();
/* ��ѧ������Ӣ������ѡ�� */
void RankingPart();
/* ����ѡ���ʵ�� */
void ProcessRankingPart(char choice);
/* ��ѧ�ɼ����а� */
void RankingMath();
/* Ӣ��ɼ����а� */
void RankingEng();


#endif // RANKINGQUERY_H_INCLUDED
