#include "PrintForm.h"
/*********************************************
 * �ļ�����PrintForm.h
 * ��  ����������ʾѧ������ӡ�ı�������Ϣ
 * �����ˣ�ZHOU
 * ��  �ڣ�2017-5-22
 *********************************************/


 extern StuInfo student[N] ;
 extern int count;
 int n ; //��¼����ѧ����Ϣ

 /* ��������ӡѧ�������ѧ�Ų���ѯ��ѧ����Ϣ*/
void  InputSearch()
{
   int i, j, num, a , b, c ;
   char name[50] ,choice;
   ReadInfo();
   StuInfo *p = student;
   StuInfo temp;
   for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }

        while(1)
        {
            for(i = 0; i < 13; i++)
            {
                SetPosition(MARGIN_X + 19, 4 + i);
                printf("                                                    ");//����
            }
            SetPosition(MARGIN_X + 31, 9);
            printf("����������������ѧ��");
            SetPosition(MARGIN_X + 31, 11);
            printf("������");
            SetPosition(MARGIN_X + 31, 13);
            printf("ѧ�ţ�");
            SetPosition(MARGIN_X + 37, 11);
            fflush(stdin);
            gets( name );
            SetPosition(MARGIN_X + 37, 13);
            fflush(stdin);
            scanf( "%d" , & num );
            for( i = 0 ; i < count ; i++)
            {
                if(student[i].num == num && strcmp(student[i].name,name)==0 )
                {
                   n = i ;
                   a = student[n].math_score ;
                   b = student[n].Eng_score  ;
                   c = student[n].math_score + student[n].Eng_score ;
                   SetPosition(MARGIN_X + 28, 9);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 11);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 13);
                   printf("                                     ");//����
                   Sleep(100);
                   SetPosition(MARGIN_X + 27, 5);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 6);
                   printf("�� �� ��ѧ�ɼ� Ϊ ��");
                   SetPosition(MARGIN_X + 27, 7);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 8);
                   printf("�� �� Ӣ��ɼ� Ϊ �� ");
                   SetPosition(MARGIN_X + 27, 9);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 10);
                   printf("�� �� �� �� �� Ϊ �� ");
                   SetPosition(MARGIN_X + 27, 11);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 12);
                   printf("������ѧ�ɼ�����Ϊ�� ");
                   SetPosition(MARGIN_X + 27, 13);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 14);
                   printf("���Ӣ��ɼ�����Ϊ�� ");
                   SetPosition(MARGIN_X + 27, 15);
                   printf("***************************");
                   SetPosition(MARGIN_X + 29, 16);
                   printf("��� �ܳɼ� ����Ϊ��");
                   SetPosition(MARGIN_X + 27, 17);
                   printf("***************************");
                   fflush(stdin);
                   SetPosition(MARGIN_X + 49, 6);
                   printf("%d",student[n].math_score);
                   SetPosition(MARGIN_X + 49, 8);
                   printf("%d",student[n].Eng_score);
                   SetPosition(MARGIN_X + 49, 10);
                   printf("%d",(student[n].math_score + student[n].Eng_score));

                   SetPosition(MARGIN_X + 49, 12);
                   for(i = 0; i < count - 1; i++)  //ð������
                   {
                      p = student;
                      for(j = 0; j < count - 1 - i; j++, p++)
                      {
                         if((p->math_score) < ((p+1)->math_score))
                         {
                           temp = *p;
                           *p = *(p+1);
                           *(p+1) = temp;
                         }
                      }
                   }
                   p = student;  //��pָ��������ʼ
                   printf("%d",Search(num));

                   SetPosition(MARGIN_X + 49, 14);
                    for(i = 0; i < count - 1; i++)  //ð������
                   {
                      p = student;
                      for(j = 0; j < count - 1 - i; j++, p++)
                      {
                         if((p->Eng_score) < ((p+1)->Eng_score))
                         {
                           temp = *p;
                           *p = *(p+1);
                           *(p+1) = temp;
                         }
                      }
                   }
                   p = student;  //��pָ��������ʼ
                   printf("%d",Search(num));

                   SetPosition(MARGIN_X + 49, 16);
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
                   printf("%d",Search(num));

                   SetPosition(MARGIN_X + 50, 19);
                   printf("��z�������˵�");
                   choice = getch();
                   while(1)//��z�˳�ϵͳ
                   {
                       if(choice=='z')
                      {
                          for(j = 0; j < 13; j++)
                         {
                             SetPosition(MARGIN_X + 19, 4 + i);
                             printf("                                                     ");
                         }
                          break;
                      }
                      else
                      {
                          SetPosition(MARGIN_X + 63, 19);
                          printf("         ");
                          SetPosition(MARGIN_X + 63, 19);
                          choice = getch();
                      }

                  } break;
                }
            }
            if ( i >= count )//ѧ����Ϣ����������·���������档
                {
                   SetPosition(MARGIN_X + 28, 9);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 11);
                   printf("                                     ");
                   SetPosition(MARGIN_X + 28, 13);
                   printf("                                     ");//����
                   Sleep(300);
                   SetPosition(MARGIN_X + 24, 11);
                   printf("�������ҵ���Ϣ�������������룡");
                   Sleep(1000);
                   SetPosition(MARGIN_X + 20, 11);
                   printf("                                              ");
            }
            break;


        }
}



int Search(int a)//��������
{
    int i ;
    for(i=0 ; i < count ;i++)
      if(student[i].num == a)
        return (i+1);
}














