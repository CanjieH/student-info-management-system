#include "PlayMusic.h"

/* �������� */
void music()
{
    int i;
    char key;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 21 + i);
        printf("                             ");
    }

    PlaySound(TEXT("music\\��ũУ��.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    Lyrics();
    while(1)
    {
        if((key = getch()) == 'z')
        {
            PlaySound(NULL, NULL, NULL);
            ClearTotal();
            break;
        }
    }
}

/* ��� */
void Lyrics()
{
    SetPosition(MARGIN_X + 22, 4);
    printf("��ɽͦ������ķ�� ������Ȼ������ۻ�");
    SetPosition(MARGIN_X + 22, 5);
    printf("������ǧ�껪������ �Ƴ�һ������ũ����");
    SetPosition(MARGIN_X + 24, 6);
    printf("�����Ͼ�ũҵ��ѧ �����Ͼ�ũҵ��ѧ");
    SetPosition(MARGIN_X + 22, 7);
    printf("�������ʳ�������� �����ǿʢ������");
    SetPosition(MARGIN_X + 29, 8);
    printf("����ǻ�����ϣ������Ұ");
    SetPosition(MARGIN_X + 27, 9);
    printf("�ÿ�ѧ�߶��߶� �ִ�������");

    SetPosition(MARGIN_X + 22, 11);
    printf("��ɽͦ������ķ�� ������Ȼ������ۻ�");
    SetPosition(MARGIN_X + 22, 12);
    printf("������ǧ�껪������ �Ƴ�һ������ũ����");
    SetPosition(MARGIN_X + 24, 13);
    printf("�����Ͼ�ũҵ��ѧ �����Ͼ�ũҵ��ѧ");
    SetPosition(MARGIN_X + 22, 14);
    printf("��Ե������Ž��ڷ� ������Уѵ��ʵ����");
    SetPosition(MARGIN_X + 29, 15);
    printf("�ڿ����������ӭ����ս");
    SetPosition(MARGIN_X + 27, 16);
    printf("Ϊ�л��ڷ��ڷ� ƴ���ܽ� �ܽ�");

    SetPosition(MARGIN_X + 30, 18);
    printf("(��z����ͣ���Ų�����)");
}

