/*********************************************
 * �ļ�����RankingQuery.c
 * ��  ����ʵ����ѧ���ɼ����а�Ĳ鿴�������ܳɼ����а񡢵��Ƴɼ����а�
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-5-30
 *********************************************/

#include "RankingQuery.h"

extern StuInfo student[N];
extern int count;

/* ѡ�������С��������н��� */
void RankingShowOne()
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
        ClearPart();
        SetPosition(MARGIN_X + 27, 8);
        printf("��ѡ����Ҫ�鿴�����ݣ�");
        SetPosition(MARGIN_X + 27, 10);
        printf("1���ܳɼ����а�");
        SetPosition(MARGIN_X + 27, 11);
        printf("2�����Ƴɼ����а�");
        SetPosition(MARGIN_X + 27, 12);
        printf("3���������˵�");
        if((choice = getch()) == '3')
            break;
        ProcessRankingQuery(choice);
    }
}

/* ����ѡ���ʵ�� */
void ProcessRankingQuery(char choice)
{
    switch(choice)
    {
    case '1':  //�ܳɼ����а�
        RankingTotal();
        break;
    case '2':  //���Ƴɼ����а�
        RankingPart();
        break;
    case '3':  //�������˵�
        break;
    default:  //������֤
        ClearPart();
        SetPosition(MARGIN_X + 25, 9);
        printf("�Բ���ֻ������1~3֮������֣�");
        SetPosition(MARGIN_X + 32, 10);
        printf("�밴���������...");
        getch();
    }
}

/* �ܳɼ����а��ʵ�� */
void RankingTotal()
{
    int i, j;
    int rank = 1;  //����
    int page = 1;  //ҳ��
    int page_max = count / 28 + 1;  //���ҳ��
    char key;  //�û��������Ұ���

    ReadInfo();  //��ȡѧ����Ϣ��������
    StuInfo *p = student;
    StuInfo temp;

    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                       ");
    }
    for(i = 0; i < count - 1; i++)  //ð������
    {
        p = student;
        for(j = 0; j < count - 1 - i; j++, p++)
        {
            if(((p->Eng_score)+(p->math_score)) < (((p+1)->Eng_score)+((p+1)->math_score)))
            {
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
    p = student;  //��pָ��������ʼ

    while(1)
    {
        RankingShowTwo();  //��ʾ�ָ��ߡ���Ŀ���ƵȵĽ���Ԫ��
        rank = 1 + (page-1) * 28;  //����ÿһҳ����ʼ����
        if(page != page_max)  //��Ϊ���һҳ�����
        {
            for(i = 0, j = 1; i < 28; i++, p++, j++)
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);  //ǰ�벿��
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);  //��벿��
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            p = student + (page-1) * 28;  //�û�ָ��p��ָ��
        }
        else  //���Ϊ���һҳ
        {
            for(i = 0, j = 1; i < count - (page-1) * 28; i++, p++, j++)  //i����Ϊֻ�ܴ�ӡ�����е�ѧ������
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            for( ; i < 28; i++, j++)  //��ǰһҳ���µ�������Ϣ���
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("                                   ");
            }
            p = student + (page-1) * 28;  //�û�ָ��p��ָ��
        }
        SetPosition(MARGIN_X + 72, 21);
        printf("ҳ����%d/%d\n", page, page_max);
        SetPosition(MARGIN_X + 67, 22);
        printf("(��z�����ز˵�)");
        //printf("ѧ��������%d", count);
        key = getch();
        if(key == 75)  //���
        {
            page--;
            if(page < 1)
            {
                page = 1;  //����ڵ�һҳ���������Ч
            }
            p = student + (page-1) * 28;
        }
        else if(key == 77)  //�Ҽ�
        {
            page++;
            if(page > page_max)
            {
                page = page_max;  //��������һҳ���Ҽ�����Ч
            }
            p = student + (page-1) * 28;
        }
        else if(key == 'z')
        {
            ClearTotal();
            break;
        }
        ClearTotal();
    }
    for(i = 0; i < 2; i++)
    {
        SetPosition(MARGIN_X + 64, 21 + i);
        printf("                  ");
    }
}

/* �ָ��ߡ���Ŀ���ƵȵĽ���Ԫ����ʾ */
void RankingShowTwo()
{
    int i;

    for(i = 0; i < 17; i++)
    {
        SetPosition(MARGIN_X + 40, 3 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 4, 3);
    printf("����   ����\tӢ��  ��ѧ  �ܳɼ�");
    SetPosition(MARGIN_X + 45, 3);
    printf("����   ����\tӢ��  ��ѧ  �ܳɼ�");
}

/* ѡ��Ӣ�����С���ѧ���н��� */
void RankingPart()
{
    char choice;

    while(1)
    {
        ClearPart();
        SetPosition(MARGIN_X + 27, 8);
        printf("��ѡ����Ҫ�鿴�����ݣ�");
        SetPosition(MARGIN_X + 27, 10);
        printf("1����ѧ�ɼ����а�");
        SetPosition(MARGIN_X + 27, 11);
        printf("2��Ӣ��ɼ����а�");
        SetPosition(MARGIN_X + 27, 12);
        printf("3�������ϼ��˵�");
        if((choice = getch()) == '3')
            break;
        ProcessRankingPart(choice);
    }
}

/* ����ѡ���ʵ�� */
void ProcessRankingPart(char choice)
{
    switch(choice)
    {
    case '1':  //��ѧ�ɼ����а�
        RankingMath();
        break;
    case '2':  //Ӣ��ɼ����а�
        RankingEng();
        break;
    case '3':  //�������˵�
        break;
    default:  //������֤
        ClearPart();
        SetPosition(MARGIN_X + 25, 9);
        printf("�Բ���ֻ������1~3֮������֣�");
        SetPosition(MARGIN_X + 32, 10);
        printf("�밴���������...");
        getch();
    }
}

/* ��ѧ�ɼ����а��ʵ�� */
void RankingMath()
{
    int i, j;
    int rank = 1;  //����
    int page = 1;  //ҳ��
    int page_max = count / 28 + 1;  //���ҳ��
    char key;  //�û��������Ұ���

    ReadInfo();  //��ȡѧ����Ϣ��������
    StuInfo *p = student;
    StuInfo temp;

    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                       ");
    }
    for(i = 0; i < count - 1; i++)  //ð������
    {
        p = student;
        for(j = 0; j < count - 1 - i; j++, p++)
        {
            if(p->math_score < (p+1)->math_score)
            {
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
    p = student;  //��pָ��������ʼ

    while(1)
    {
        RankingShowTwo();  //��ʾ�ָ��ߡ���Ŀ���ƵȵĽ���Ԫ��
        rank = 1 + (page-1) * 28;  //����ÿһҳ����ʼ����
        if(page != page_max)  //��Ϊ���һҳ�����
        {
            for(i = 0, j = 1; i < 28; i++, p++, j++)
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);  //ǰ�벿��
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);  //��벿��
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            p = student + (page-1) * 28;  //�û�ָ��p��ָ��
        }
        else  //���Ϊ���һҳ
        {
            for(i = 0, j = 1; i < count - (page-1) * 28; i++, p++, j++)  //i����Ϊֻ�ܴ�ӡ�����е�ѧ������
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            for( ; i < 28; i++, j++)  //��ǰһҳ���µ�������Ϣ���
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("                                   ");
            }
            p = student + (page-1) * 28;  //�û�ָ��p��ָ��
        }
        SetPosition(MARGIN_X + 72, 21);
        printf("ҳ����%d/%d\n", page, page_max);
        SetPosition(MARGIN_X + 67, 22);
        printf("(��z�����ز˵�)");
        //printf("ѧ��������%d", count);
        key = getch();
        if(key == 75)  //���
        {
            page--;
            if(page < 1)
            {
                page = 1;  //����ڵ�һҳ���������Ч
            }
            p = student + (page-1) * 28;
        }
        else if(key == 77)  //�Ҽ�
        {
            page++;
            if(page > page_max)
            {
                page = page_max;  //��������һҳ���Ҽ�����Ч
            }
            p = student + (page-1) * 28;
        }
        else if(key == 'z')
        {
            ClearTotal();
            break;
        }
        ClearTotal();
    }
    for(i = 0; i < 2; i++)
    {
        SetPosition(MARGIN_X + 64, 21 + i);
        printf("                  ");
    }
}

/* Ӣ��ɼ����а��ʵ�� */
void RankingEng()
{
    int i, j;
    int rank = 1;  //����
    int page = 1;  //ҳ��
    int page_max = count / 28 + 1;  //���ҳ��
    char key;  //�û��������Ұ���

    ReadInfo();  //��ȡѧ����Ϣ��������
    StuInfo *p = student;
    StuInfo temp;

    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 27, 8 + i);
        printf("                       ");
    }
    for(i = 0; i < count - 1; i++)  //ð������
    {
        p = student;
        for(j = 0; j < count - 1 - i; j++, p++)
        {
            if(p->Eng_score < (p+1)->Eng_score)
            {
                temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
    p = student;  //��pָ��������ʼ

    while(1)
    {
        RankingShowTwo();  //��ʾ�ָ��ߡ���Ŀ���ƵȵĽ���Ԫ��
        rank = 1 + (page-1) * 28;  //����ÿһҳ����ʼ����
        if(page != page_max)  //��Ϊ���һҳ�����
        {
            for(i = 0, j = 1; i < 28; i++, p++, j++)
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);  //ǰ�벿��
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);  //��벿��
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            p = student + (page-1) * 28;  //�û�ָ��p��ָ��
        }
        else  //���Ϊ���һҳ
        {
            for(i = 0, j = 1; i < count - (page-1) * 28; i++, p++, j++)  //i����Ϊֻ�ܴ�ӡ�����е�ѧ������
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("%-6d%-10s%-6d%-7d%-6d", rank++, p->name, p->Eng_score, p->math_score, (p->Eng_score) + (p->math_score));
            }
            for( ; i < 28; i++, j++)  //��ǰһҳ���µ�������Ϣ���
            {
                if(i < 14)
                {
                    SetPosition(MARGIN_X + 4, 4 + j);
                }
                else
                {
                    if(i == 14)
                        j = 1;
                    SetPosition(MARGIN_X + 45, 4 + j);
                }
                printf("                                   ");
            }
            p = student + (page-1) * 28;  //�û�ָ��p��ָ��
        }
        SetPosition(MARGIN_X + 72, 21);
        printf("ҳ����%d/%d\n", page, page_max);
        SetPosition(MARGIN_X + 67, 22);
        printf("(��z�����ز˵�)");
        //printf("ѧ��������%d", count);
        key = getch();
        if(key == 75)  //���
        {
            page--;
            if(page < 1)
            {
                page = 1;  //����ڵ�һҳ���������Ч
            }
            p = student + (page-1) * 28;
        }
        else if(key == 77)  //�Ҽ�
        {
            page++;
            if(page > page_max)
            {
                page = page_max;  //��������һҳ���Ҽ�����Ч
            }
            p = student + (page-1) * 28;
        }
        else if(key == 'z')
        {
            ClearTotal();
            break;
        }
        ClearTotal();
    }
    for(i = 0; i < 2; i++)
    {
        SetPosition(MARGIN_X + 64, 21 + i);
        printf("                  ");
    }
}


