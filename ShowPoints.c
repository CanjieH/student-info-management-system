#include "ShowPoints.h"

extern StuInfo student[N];
extern int count;

//����
void IDfind()
{
    char choice;
	int i;
	for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }
    while(1)
    {
        ClearTotal();
        SetPosition(MARGIN_X + 27, 8);
        printf("��ѡ����Ҫ���еĲ�����");
        SetPosition(MARGIN_X + 27, 10);
        printf("1������ѧ��");
        SetPosition(MARGIN_X + 27, 11);
        printf("2���������˵�");
        if((choice = getch()) == '2')
            break;
        IDmenu(choice);//���ý���ѡ���ܵĺ���
    }
}

//���ҳɼ��ĺ���
void IDfind0()
{
    char choice;
    ReadInfo();
    int i, index = -1;
	int total;
    int num;
    StuInfo *p = student;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X  +6, 6 + i);
        printf("                                                 ");
    }
    SetPosition(MARGIN_X + 26, 9);
    printf("   ������ѧ��ѧ��:");
	scanf("%d", &num);
	for(i = 0; i < count; i++, p++)
    {
		if(num == p->num)
        {
			index = i;
			break;
		}

    }
	if(index<0)
    {
        SetPosition(MARGIN_X + 25, 9);
        printf("                   ");
        SetPosition(MARGIN_X + 25, 9);
        printf("    �Բ���û���ҵ���ѧ����Ϣ��               ");
        SetPosition(MARGIN_X + 35, 10);
        printf("�밴���������...");
        getch();

	}
	else
	{
        while(1)
        {


        ClearTotal();
		total = p->math_score + p->Eng_score;
        SetPosition(MARGIN_X + 6, 6);
		printf("-----------------------------------------------------------------------");
        SetPosition(MARGIN_X + 6,7);
		printf("רҵ:%s", p->prof);
        SetPosition(MARGIN_X + 6,8);
		printf("����:%s", p->name);
        SetPosition(MARGIN_X + 6,9);
        printf("�Ա�:%s", p->sex);
        SetPosition(MARGIN_X + 6,10);
        printf("�༶:%d", p->clas);
        SetPosition(MARGIN_X + 6,11);
        printf("ѧ��:%.0ld", p->num);
        SetPosition(MARGIN_X + 6,12);
        printf("��ѧ�ɼ�:%d", p->math_score);
        SetPosition(MARGIN_X + 6,13);
        printf("Ӣ��ɼ�:%d", p->Eng_score);
        SetPosition(MARGIN_X + 6,14);
        printf("�ܷ�:%d", total );
		SetPosition(MARGIN_X + 6,15);
		printf("-----------------------------------------------------------------------");
		SetPosition(MARGIN_X + 6,16);
		printf("��0���ز˵�");
		if((choice = getch()) == '0')
           {
             break;
           }

        IDfind();//���ý���ѡ���ܵĺ���

	}
	}


	for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X  +6, 6 + i);
        printf("                                                                          ");
    }
}


//����ѡ���ܺ���
void IDmenu(char choice)
{
    int i;

    switch(choice)
    {
    case '1':  //����ѧ���ĺ���
        IDfind0();
        break;
    case '2':
        break;
    default:
        for(i = 0; i < 5; i++)
        {
            SetPosition(MARGIN_X + 27, 8 + i);
            printf("                       ");
        }
        SetPosition(MARGIN_X + 20, 9);
        printf("�Բ���ֻ������1~2֮������֣������������룡");
        Sleep(1500);
    }
}

