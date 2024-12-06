//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<easyx.h>
//
//struct Button
//{
//	//左，右，上，下
//	int x = 0;
//	int y = 0;
//	int w = 0;
//	int h = 0;
//	COLORREF curcolor = BLACK;
//	COLORREF incolor = BLACK;
//	COLORREF outcolor = BLACK;
//	COLORREF ClickColor;
//	char* text;
//};
//
//
//
////debug函数
//void DeBug(ExMessage m)
//{
//	setfillcolor(BLACK);
//	solidcircle(m.x, m.y, 5);
//	printf("被点击了");
//}
//
//
//
//
////初始化按钮
//Button* MakeButton(int x, int y, int w, int h,
//	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor)
//{
//	Button(*btn) = (Button*)malloc(sizeof(Button));
//
//	//设置按钮
//	btn->x = x;
//	btn->y = y;
//	btn->w = w;
//	btn->h = h;
//	btn->incolor = incolor;
//	btn->outcolor = outcolor;
//	btn->ClickColor = ClickColor;
//	btn->curcolor = btn->outcolor;
//	int text_length = strlen(Text) + 1;
//	btn->text = (char*)malloc(sizeof(char) * text_length);
//	strcpy_s(btn->text, text_length, Text);
//	return btn;
//}
////绘制按钮
//void DrawButton(Button* bn)
//{
//	//按钮设置
//	setlinecolor(BLACK);
//	setfillcolor(bn->curcolor);
//	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h,25,25);
//	//文字设置
//	settextcolor(BLACK);
//	setbkmode(TRANSPARENT);
//	settextstyle(15, 0, "宋体");
//	//文字居中
//	int textw = textwidth(bn->text);
//	int texth = textheight(bn->text);
//	int xx = bn->x + (bn->w - textw) / 2;
//	int yy = bn->y + (bn->h - texth) / 2;
//	outtextxy(xx, yy, bn->text);
//}
//
////判断是否在按钮内部
//bool IsInButton(Button* bn, ExMessage m) {
//	if (bn->x< m.x && bn->x + bn->w >m.x && bn->y <m.y && bn->y + bn->h >m.y)
//	{
//		bn->curcolor = bn->incolor;
//		return true;
//	}
//	bn->curcolor = bn->outcolor;
//	return false;
//}
//
////判断点击
//bool IsClickButton(Button* bn, ExMessage m) {
//	if (IsInButton(bn, m) && m.message == WM_LBUTTONDOWN)
//	{
//		bn->curcolor = bn->ClickColor;
//		FlushBatchDraw();
//		if (m.message == WM_LBUTTONUP)
//		{
//			bn->curcolor = bn->incolor;
//		}
//		return true;
//	}
//
//	return false;
//}
//
//
//
//
//
//int main() {
//
//
//	//	//创建主窗口
//	HWND MainCamera = initgraph(1024, 1024);
//
//
//
//
//	Button* Adventure = MakeButton(512 - 275, 924, 100, 50, "修炼", RGB(137, 207, 240), RGB(255, 255, 255), RGB(30, 144, 255));
//
//
//
//	ExMessage m;
//	BeginBatchDraw();
//	while (1)
//	{
//		DrawButton(Adventure);
//
//		peekmessage(&m, EX_MOUSE);
//		//判断是否去修炼
//	
//		//判断是否去历练
//		if (IsClickButton(Adventure, m))
//		{
//		}
//
//	
//	
//	
//	
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//
//
//
//
//
//	return 0;
//}
//
