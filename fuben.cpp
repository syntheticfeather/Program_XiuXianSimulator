#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<easyx.h>
#include<string.h>
#include<stdbool.h>

//按钮结构体，记录按钮四个角的位置
struct Button
{
	//左，右，上，下
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	COLORREF curcolor = BLACK;
	COLORREF incolor = BLACK;
	COLORREF outcolor = BLACK;
	COLORREF ClickColor;
	char* text;
};

//debug函数
void DeBug(ExMessage m)
{
	setfillcolor(BLACK);
	solidcircle(m.x, m.y, 5);
	printf("被点击了");
}

//debug实例
	//struct Button* bn = MakeButton(500, 200, 300, 100, "play",RGB(255,255,255),RGB(137, 207, 240));
	//DrawButton(bn);

//初始化按钮
Button* MakeButton(int x, int y, int w, int h,
	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor)
{
	Button(*btn) = (Button*)malloc(sizeof(Button));

	//设置按钮
	btn->x = x;
	btn->y = y;
	btn->w = w;
	btn->h = h;
	btn->incolor = incolor;
	btn->outcolor = outcolor;
	btn->ClickColor = ClickColor;
	btn->curcolor = btn->outcolor;
	int text_length = strlen(Text) + 1;
	btn->text = (char*)malloc(sizeof(char) * text_length);
	strcpy_s(btn->text, text_length, Text);
	return btn;
}

//绘制按钮
void DrawButton(Button* bn)
{
	//按钮设置
	setlinecolor(BLACK);
	setfillcolor(bn->curcolor);
	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h, 25, 25);
	//文字设置
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "宋体");
	//文字居中
	int textw = textwidth(bn->text);
	int texth = textheight(bn->text);
	int xx = bn->x + (bn->w - textw) / 2;
	int yy = bn->y + (bn->h - texth) / 2;
	outtextxy(xx, yy, bn->text);
}

//判断是否在按钮内部，鼠标悬浮颜色变化
bool IsInButton(Button* bn, ExMessage m) {
	if (bn->x< m.x && bn->x + bn->w >m.x && bn->y <m.y && bn->y + bn->h >m.y)
	{
		bn->curcolor = bn->incolor;
		return true;
	}
	bn->curcolor = bn->outcolor;
	return false;
}

//按钮点击判断，点击颜色变化
bool IsClickButton(Button* bn, ExMessage m) {
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

//实现三维数据的显示
void UpdateData(Button* btn, float HP, float ATK, float DF) {
	//文字设置
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "宋体");
	//文字居中
	char HPText[10], ATKText[10], DFText[10];
	sprintf(HPText, "%d", (int)HP);
	sprintf(ATKText, "%d", (int)ATK);
	sprintf(DFText, "%d", (int)DF);

	int textw = textwidth(HPText);
	int texth = textheight(HPText);
	int xx = btn->x + (btn->w - textw) / 2;
	int yy = btn->y + 30;

	outtextxy(xx - 20, yy, "生命:");
	outtextxy(xx + 30, yy, HPText);
	outtextxy(xx - 20, yy + 37.5, "攻击:");
	outtextxy(xx + 30, yy + 37.5, ATKText);
	outtextxy(xx - 20, yy + 75, "防御:");
	outtextxy(xx + 30, yy + 75, DFText);
}

float HP = 1.0;
float ATK = 1.0;
float DF = 1.0;

int main()
{
	//创建主窗口
	HWND MainCamera = initgraph(1024, 1024);
	//添加背景图
	IMAGE img;
	loadimage(&img, "beijintu.png");
	putimage(0, 0, &img);



	//生成按钮
	//本机1.5倍率，
	Button* Adventure = MakeButton(512 - 275, 924, 100, 50, "修炼", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
	Button* Adventure1 = MakeButton(512 - 125, 924, 100, 50, "装备", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
	Button* Adventure2 = MakeButton(512 + 25, 924, 100, 50, "历练", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
	Button* Adventure3 = MakeButton(512 + 175, 924, 100, 50, "商城", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
	Button* Adventure4 = MakeButton(512 - 50, 800, 100, 50, "突破", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
	Button* DataButton = MakeButton(50, 50, 100, 150, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));
	//绘制按钮
	DrawButton(Adventure);
	DrawButton(Adventure1);
	DrawButton(Adventure2);
	DrawButton(Adventure3);
	DrawButton(Adventure4);
	DrawButton(DataButton);



	//获取鼠标消息
	ExMessage m;
	BeginBatchDraw();
	while (1)
	{
		DrawButton(Adventure);
		DrawButton(Adventure1);
		DrawButton(Adventure2);
		DrawButton(Adventure3);
		DrawButton(Adventure4);
		DrawButton(DataButton);

		UpdateData(DataButton,HP, ATK, DF);
		//判断是否去修炼

		peekmessage(&m, EX_MOUSE);
		//判断是否去历练
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
		if (IsClickButton(DataButton, m))
		{
			HP++;
		}





		FlushBatchDraw();
	}
	EndBatchDraw();

	getchar();
	closegraph();

	return 0;
}



