#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <easyx.h>
#include <string.h>
#include <stdbool.h>

// work with easyx.h

// ��ť�ṹ�壬��¼��ť�ĸ��ǵ�λ��
struct Button
{
	// ���ң��ϣ���
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	COLORREF curcolor = BLACK;
	COLORREF incolor = BLACK;
	COLORREF outcolor = BLACK;
	COLORREF ClickColor;
	char *text;
};

// debug����
void DeBug(ExMessage m)
{
	setfillcolor(BLACK);
	solidcircle(m.x, m.y, 5);
	printf("�������");
}

// ��ʼ����ť
Button *MakeButton(int x, int y, int w, int h,
				   const char *Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor)
{
	Button(*btn) = (Button *)malloc(sizeof(Button));

	// ���ð�ť
	btn->x = x;
	btn->y = y;
	btn->w = w;
	btn->h = h;
	btn->incolor = incolor;
	btn->outcolor = outcolor;
	btn->ClickColor = ClickColor;
	btn->curcolor = btn->outcolor;
	int text_length = strlen(Text) + 1;
	btn->text = (char *)malloc(sizeof(char) * text_length);
	strcpy_s(btn->text, text_length, Text);
	return btn;
}
// ���ư�ť
void DrawButton(Button *bn)
{
	// ��ť����
	setlinecolor(BLACK);
	setfillcolor(bn->curcolor);
	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h, 25, 25);
	// ��������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "����");
	// ���־���
	int textw = textwidth(bn->text);
	int texth = textheight(bn->text);
	int xx = bn->x + (bn->w - textw) / 2;
	int yy = bn->y + (bn->h - texth) / 2;
	outtextxy(xx, yy, bn->text);
}
// debugʵ��
// struct Button* bn = MakeButton(500, 200, 300, 100, "play",RGB(255,255,255),RGB(137, 207, 240));
// DrawButton(bn);

// �ж��Ƿ��ڰ�ť�ڲ�
bool IsInButton(Button *bn, ExMessage m)
{
	if (bn->x < m.x && bn->x + bn->w > m.x && bn->y < m.y && bn->y + bn->h > m.y)
	{
		bn->curcolor = bn->incolor;
		return true;
	}
	bn->curcolor = bn->outcolor;
	return false;
}

bool IsClickButton(Button *bn, ExMessage m)
{
	if (IsInButton(bn, m) && m.message == WM_LBUTTONDOWN)
	{
		bn->curcolor = bn->ClickColor;
		FlushBatchDraw();
		if (m.message == WM_LBUTTONUP)
		{
			bn->curcolor = bn->incolor;
		}
		return true;
	}

	return false;
}

int main()
{
	// ����������
	HWND MainCamera = initgraph(1024, 1024);
	// ���ӱ���ͼ
	IMAGE img;
	loadimage(&img, "beijintu.png");
	putimage(0, 0, &img);

	// ���ɰ�ť
	// ����1.5���ʣ�
	Button *Adventure = MakeButton(512 - 275, 924, 100, 50, "����", RGB(137, 207, 240), RGB(255, 255, 255), RGB(30, 144, 255));
	Button *Adventure1 = MakeButton(512 - 125, 924, 100, 50, "װ��", RGB(137, 207, 240), RGB(255, 255, 255), RGB(30, 144, 255));
	Button *Adventure2 = MakeButton(512 + 25, 924, 100, 50, "����", RGB(137, 207, 240), RGB(255, 255, 255), RGB(30, 144, 255));
	Button *Adventure3 = MakeButton(512 + 175, 924, 100, 50, "�̳�", RGB(137, 207, 240), RGB(255, 255, 255), RGB(30, 144, 255));
	Button *Adventure4 = MakeButton(512 - 50, 800, 100, 50, "ͻ��", RGB(137, 207, 240), RGB(255, 255, 255), RGB(30, 144, 255));
	// ���ư�ť
	DrawButton(Adventure);
	DrawButton(Adventure1);
	DrawButton(Adventure2);
	DrawButton(Adventure3);
	DrawButton(Adventure4);

	// ��ȡ�����Ϣ
	ExMessage m;
	BeginBatchDraw();
	while (1)
	{
		DrawButton(Adventure);
		DrawButton(Adventure1);
		DrawButton(Adventure2);
		DrawButton(Adventure3);
		DrawButton(Adventure4);
		peekmessage(&m, EX_MOUSE);
		// �ж��Ƿ�ȥ����

		// �ж��Ƿ�ȥ����
		if (IsClickButton(Adventure, m))
		{
		}
		if (IsClickButton(Adventure1, m))
		{
		}
		if (IsClickButton(Adventure2, m))
		{
		}
		if (IsClickButton(Adventure3, m))
		{
		}
		if (IsClickButton(Adventure4, m))
		{
		}

		FlushBatchDraw();
	}
	EndBatchDraw();

	getchar();
	closegraph();
	return 0;
}
