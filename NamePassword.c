#include "NamePassword.h"

/*********************************************
 * �ļ�����NamePassword.c
 * ��  ������������ѧ����Ϣ����ϵͳ�û���½
 * �����ˣ�CANJIE
 * ��  �ڣ�2017-4-27
 *********************************************/
int ok;
void ShowLogin()  //��½����
{
    int i;
    SetPosition(MARGIN_X + 21, 5);
    printf("-------------------------------------");
    SetPosition(MARGIN_X + 20, 6);
    printf("|");
    SetPosition(MARGIN_X + 58, 6);
    printf("|");
    SetPosition(MARGIN_X + 22, 6);
    printf("************* ��½���� ************");
    SetPosition(MARGIN_X + 21, 7);
    printf("-------------------------------------");
    for(i = 0; i < 5; i++)
    {
        SetPosition(MARGIN_X + 20, 7 + i);
        printf("|");
        SetPosition(MARGIN_X + 58, 7 + i);
        printf("|");
    }
    SetPosition(MARGIN_X + 20, 12);
    printf("---------------------------------------");
}

int Login()  //�û��������������
{
    int x = 0;
    char c;
    int i = 0;
    char name[20];
    char password1[20];

    ClearTotal();
    ShowLogin();

    SetPosition(MARGIN_X + 25, 9);
    printf("�û�����");
    SetPosition(MARGIN_X + 25, 10);
    printf("��  �룺");
    SetPosition(MARGIN_X + 33, 9);

    fflush(stdin);
    MyFgets(name, 20);

    fflush(stdin);
    SetPosition(MARGIN_X + 33, 10);
    while ((c=getch())!='\r')
    {
        if (i<19 && isprint(c))
        {
            password1[i++] = c;
            putchar('*');
        }
        else if (i>0 && c=='\b')
        {
            --i;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
    }
    password1[i] = '\0';
    fflush(stdin);

    if(veriLogin(name, password1) == 1)  //�û�����������֤
    {
        SetPosition(MARGIN_X + 26, 9);
        printf("����������ȷ����½�ɹ���");
        SetPosition(MARGIN_X + 26, 10);
        printf("���ڽ���ϵͳ�����Ժ�...");
        Sleep(1000);

        for(i = 0; i < 8; i++)
        {
            SetPosition(MARGIN_X + 20, 5 + i);
            printf("                                             ");
        }
        ok = 1;

        //return veriLogin(name, password1);

    }

    else
    {
        SetPosition(MARGIN_X + 25, 9);
        printf("                         ");  //�����Ļ
        SetPosition(MARGIN_X + 25, 10);
        printf("                         ");  //�����Ļ
        SetPosition(MARGIN_X + 26, 9);
        printf("�û���������������������룡");
        Sleep(1000);
        ok = 0;

       //return veriLogin(name, password1);

    }

}

int veriLogin(char name[], char password1[])  //�û���������������֤
{
    ReadPass();
    Password *p = password;
    int result = 0;
    int i;
    int index = -1;
    for(i = 0; i < countpass; i++, p++)
    {
        if(strcmp(name, p->account) == 0 && strcmp(password1, p->password) == 0)
        {
            index = i;
            break;
        }
    }


    if(index != -1)
    {
        result = 1;  //����������ȷ����1
    }
    return result;  //����������󷵻�0
}

void MyFgets(char *name, int maxLen)  //����������û���������
{
    int i;

    fgets(name, maxLen, stdin);
    for(i = 0; name[i] != '\0'; i++)
    {
        if(name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }
}


int ShowMenu()
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

        ok = 0;
        for(i = 0; i < 13; i++)
        {
            SetPosition(MARGIN_X + 19, 4 + i);
            printf("                                                    ");
        }
        SetPosition(MARGIN_X + 34, 9);
        printf("1.��½");
        SetPosition(MARGIN_X + 34, 10);
        printf("2.ע���˻�");
        SetPosition(MARGIN_X + 34, 11);
        printf("3.�˳�ϵͳ");
        if((choice = getch()) == '3')
           {
            ClearTotal();
            system("cls");
            exit(1);

           }
        InputChoice(choice);
        if(ok == 1)
        return ok;


    }
}

void InputChoice(char choice)
{
    int i;
    switch(choice)
    {
    case '1':
        Login();

        break;
    case '2':
        PassMenu();
        break;
    case '3':
        break;
        default:  //������֤
        for(i = 0; i < 5; i++)
        {
            SetPosition(MARGIN_X + 27, 8 + i);
            printf("                       ");
        }
        SetPosition(MARGIN_X + 20, 9);
        printf("�Բ���ֻ������1~3֮������֣������������룡");
        Sleep(1500);
    }
}


