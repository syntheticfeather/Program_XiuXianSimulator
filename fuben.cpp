﻿//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<easyx.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<stdbool.h>
//#include<time.h>
//#include<pthread.h>
//
//
//
//
//
//#define NUM 4
//
////按钮结构体，记录按钮四个角的位置
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
//	bool Canclick = true;
//
//};
//
//
//
//
//void GetName();
//Button* MakeButton(int x, int y, int w, int h,
//	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor);
//void DrawButton(Button*);
//void DrawButton(Button*, COLORREF);
//bool IsInButton(Button*, ExMessage);
//bool IsClickButton(Button*, ExMessage);
//void CanLvlUp(Button*, int CurExp, int MaxExp);
//void UpdateData(Button*, float HP, float ATK, float DF, int Lvl, char* Name);
//void UpdateCoin_Age(Button*, int Age, int Coin);
//void UpdateExp_Lvl(int CurExp, int MaxExp);
//void Instruction(ExMessage, IMAGE);
//void LvlUpScreen(int);
//void Click(ExMessage, IMAGE);
//void OpenBag(IMAGE);
////待完成
//void ShowItemInBag();
//void ShowMall(IMAGE);
//void ShowitemInMall();
//void GoAdventure(IMAGE);
//void TuPo(int rate, IMAGE imgBK);
////待完成
//void Save_All();
//void Load_All();
//
//
//bool IsBeginner = true;
//float HP = 1.0;
//float ATK = 1.0;
//float DF = 1.0;
//int rate = 80;
//int Lvl = 0;
//int CurExp = 8;
//int MaxExp = 10;
//int Age = 1000;
//int Coin = 4;
//char Name[10];
//char NameList[20][20] = {
//
//	"鲁墨尘","祈墨珏","苗墨北","祈诺昱","湫静安",
//	"鲁君麟","司寇顾尧","顼淮德","阳子明","太叔离洛",
//	"苗权震","面千尘","南宫灼光","肜洛意","面修文",
//	"荆苍何","越松南","越炎冥","华明泽","面非寒",
//};
//
////等级
//const char LvlList[71][20] = {
//	"练气期一阶","练气期二阶","练气期三阶","练气期四阶","练气期五阶","练气期六阶","练气期七阶","练气期八阶","练气期九阶","练气期圆满",
//	"筑基期一阶","筑基期二阶","筑基期三阶","筑基期四阶","筑基期五阶","筑基期六阶","筑基期七阶","筑基期八阶","筑基期九阶","筑基期圆满",
//	"金丹期一阶","金丹期二阶","金丹期三阶","金丹期四阶","金丹期五阶","金丹期六阶","金丹期七阶","金丹期八阶","金丹期九阶","金丹期圆满",
//	"元婴期一阶","元婴期二阶","元婴期三阶","元婴期四阶","元婴期五阶","元婴期六阶","元婴期七阶","元婴期八阶","元婴期九阶","元婴期圆满",
//	"化神期一阶","化神期二阶","化神期三阶","化神期四阶","化神期五阶","化神期六阶","化神期七阶","化神期八阶","化神期九阶","化神期圆满",
//	"合体期一阶","合体期二阶","合体期三阶","合体期四阶","合体期五阶","合体期六阶","合体期七阶","合体期八阶","合体期九阶","合体期圆满",
//	"飞升期一阶","飞升期二阶","飞升期三阶","飞升期四阶","飞升期五阶","飞升期六阶","飞升期七阶","飞升期八阶","飞升期九阶","飞升期圆满",
//	"仙"
//};
//
////新手教程句子数组
//const char BeginText[10][100] = {
//	"红尘三千小世界，修真历练成真仙。欢迎来到修仙模拟器。",
//	"上一世的你在成仙渡劫时不幸被兄弟老婆背叛，阴差阳错回到了18岁那年。",
//	"重活一世你决定不再颓废，誓要夺回曾经属于你的一切。",
//	"点击画面加快修炼。",
//	"经验值满了点击突破案件进行突破",
//	"达到一定修为可以外出历练，探索机遇",
//	"灵石可以在商城中购买装备以及灵丹妙药,或者出售不需要的装备",
//	"在背包界面中可以更换装备.查看已有的丹药",
//	"你的境界和三维属性会显示在左上。",
//	"灵石数量以及修炼时长会显示在右上。",
//
//};
////主点击按钮
//Button* XiuXing = MakeButton(128 - 50, 929, 100, 50, "修炼", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//Button* BagButton = MakeButton(384 - 50, 929, 100, 50, "背包", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//Button* Adventure = MakeButton(640 - 50, 929, 100, 50, "历练", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//Button* ShoppingMall = MakeButton(1024 - 128 - 50, 929, 100, 50, "商城", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//Button* LvlUpButton = MakeButton(512 - 50, 700, 100, 50, "突破", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//
////显示
//Button* DataButton = MakeButton(50, 50, 100, 125, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));
//Button* AgeCoinButton = MakeButton(1024 - 150, 50, 100, 125, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));
//Button* NameButton = MakeButton(1024 - 150, 50, 100, 125, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));
//
////关闭界面按钮
//Button* CloseButton_Bag = MakeButton(720, 50, 35, 35, "关闭", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//Button* CloseButton_Adven = MakeButton(512 - 50, 600, 100, 40, "关闭", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//Button* CloseButton_Shop = MakeButton(512 - 50, 600, 100, 40, "关闭", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//
////结束按钮
//Button* CloseButton_All = MakeButton(1024 - 90, 10, 70, 35, "保存并退出", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
//
////putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
//Button* MallItem[NUM] = { 
//	MakeButton(512 - 100, 200, 80, 45, "1", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
//	MakeButton(1024 - 90, 10, 70, 35, "2", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
//	MakeButton(1024 - 90, 10, 70, 35, "3", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
//	MakeButton(1024 - 90, 10, 70, 35, "4", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
//};
//
//Button* BagItem[100] = {
//
//};
//
////初始化姓名
//void GetName() {
//	if (Name == NULL)
//	{
//		srand((unsigned int)time(NULL));
//		strcpy(Name, NameList[rand() % 20]);
//	}
//}
//
////初始化按钮
//Button* MakeButton(int x, int y, int w, int h,
//	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor)
//{
//	Button(*btn) = (Button*)malloc(sizeof(Button));
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
//
////绘制按钮
//void DrawButton(Button* bn)
//{
//	//按钮设置
//	setlinecolor(RGB(32, 44, 57));
//	setfillcolor(bn->curcolor);
//	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h, 25, 25);
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
////指定颜色绘制按钮
//void DrawButton(Button* bn, COLORREF Color)
//{
//	//按钮设置
//	setlinecolor(RGB(32, 44, 57));
//	setfillcolor(Color);
//	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h, 25, 25);
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
////判断是否在按钮内部，鼠标悬浮颜色变化
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
////按钮点击判断，点击颜色变化
//bool IsClickButton(Button* bn, ExMessage m) {
//	if (IsInButton(bn, m) && m.message == WM_LBUTTONDOWN)
//	{
//		if (bn->Canclick == false)
//		{
//			return false;
//		}
//		bn->curcolor = bn->ClickColor;
//		FlushBatchDraw();
//		if (m.message == WM_LBUTTONUP)
//		{
//			bn->curcolor = bn->incolor;
//		}
//		return true;
//	}
//	return false;
//}
//
////突破按钮在经验不足时不亮
//void CanLvlUp(Button* btn, int CurExp, int MaxExp) {
//	if (CurExp < MaxExp)
//	{
//		DrawButton(btn, RGB(139, 134, 130));
//		btn->Canclick = false;
//	}
//	else
//	{
//		btn->Canclick = true;
//		setfillcolor(btn->outcolor);
//		DrawButton(btn);
//	}
//}
//
////实现三维数据的显示4
//void UpdateData(Button* btn, float HP, float ATK, float DF, int Lvl, char* Name) {
//	//文字设置
//	settextcolor(BLACK);
//	setbkmode(TRANSPARENT);
//	settextstyle(15, 0, "宋体");
//	//文字居中
//	char HPText[10], ATKText[10], DFText[10];
//	sprintf(HPText, "%d", (int)HP);
//	sprintf(ATKText, "%d", (int)ATK);
//	sprintf(DFText, "%d", (int)DF);
//
//	int textw = textwidth(HPText);
//	int texth = textheight(HPText);
//	int xx = btn->x + (btn->w - textw) / 2;
//	int yy = btn->y + btn->h / 2 - 5;
//
//	outtextxy(btn->x + 15, btn->y + btn->h / 6, Name);
//	outtextxy(btn->x + 15, btn->y + btn->h / 3, LvlList[Lvl]);
//	outtextxy(xx - 25, yy + btn->h / 8, "生命:");
//	outtextxy(xx + 25, yy + btn->h / 8, HPText);
//	outtextxy(xx - 25, yy + btn->h / 4, "攻击:");
//	outtextxy(xx + 25, yy + btn->h / 4, ATKText);
//	outtextxy(xx - 25, yy + btn->h / 8 * 3, "防御:");
//	outtextxy(xx + 25, yy + btn->h / 8 * 3, DFText);
//}
//
////实现金币以及年龄的显示
//void UpdateCoin_Age(Button* btn, int Age, int Coin) {
//	char AgeText[10], CoinText[10];
//	sprintf(AgeText, "%d", Age);
//	sprintf(CoinText, "%d", Coin);
//
//	settextcolor(BLACK);
//	setbkmode(TRANSPARENT);
//	settextstyle(15, 0, "宋体");
//	int textw = textwidth(AgeText);
//	int texth = textheight(AgeText);
//	int xx = btn->x + (btn->w - textw) / 2;
//
//	outtextxy(xx - 30, btn->y + btn->h / 3 - 5, "修炼:");
//	outtextxy(xx + 10, btn->y + btn->h / 3 - 5, AgeText);
//	outtextxy(xx + textw + 10, btn->y + btn->h / 3 - 5, "年");
//
//	outtextxy(xx - 30, btn->y + btn->h / 3 * 2 - 5, "灵石:");
//	outtextxy(xx + 10, btn->y + btn->h / 3 * 2 - 5, CoinText);
//	outtextxy(xx + textw + 10, btn->y + btn->h / 3 * 2 - 5, "枚");
//}
//
////经验即经验条的显示
//void UpdateExp_Lvl(int CurExp, int MaxExp) {
//	//文字
//	settextcolor(BLACK);
//	settextstyle(30, 0, "宋体");
//	char textCur[10], textMax[10];
//	sprintf(textCur, "%d", CurExp);
//	sprintf(textMax, "%d", MaxExp);
//	outtextxy(512 - textwidth(textCur) / 2 - 100, 800, "经验值:");
//	settextcolor(BLACK);
//	outtextxy(512 - textwidth(textCur) / 2 + 30, 800, textCur);
//	outtextxy(512 - textwidth(textCur) / 2 + 70, 800, "/");
//	outtextxy(512 - textwidth(textCur) / 2 + 110, 800, textMax);
//	//经验条
//	setfillcolor(RGB(255, 222, 146));
//	float rate = (CurExp + 0.001) / MaxExp;
//	//解决超出问题
//	if (rate > 1)
//	{
//		rate = 1.0;
//	}
//	int right = 200 + (rate * 622);
//	//int right = 512;
//	fillroundrect(202, 767, right, 783, 20, 10);
//}
//
////新手教程指导
//void Instruction(ExMessage m, IMAGE imgbk) {
//	if (IsBeginner)
//	{
//		setbkmode(TRANSPARENT);
//		settextcolor(BLACK);
//		outtextxy(200, 150, BeginText[0]);
//		for (int i = 1; i < 11;)
//		{
//			peekmessage(&m, EX_MOUSE);
//			if (m.message == WM_LBUTTONDOWN)
//			{
//				peekmessage(&m, EX_MOUSE);
//				if (m.message == WM_LBUTTONUP)
//				{
//					outtextxy(200, 150 + (50 * i), BeginText[i]);
//					if (i < 4 || i == 10)
//					{
//						i++;
//					}
//					//教用户点击
//					else if (i == 3)
//					{
//						i++;
//						DrawButton(XiuXing);
//					}
//					//突破按钮
//					else if (i == 4)
//					{
//						DrawButton(LvlUpButton);
//						i++;
//					}
//					//历练按钮
//					else if (i == 5)
//					{
//						DrawButton(Adventure);
//						i++;
//					}
//					//商城按钮
//					else if (i == 6)
//					{
//						DrawButton(ShoppingMall);
//						i++;
//					}
//					//背包按钮
//					else if (i == 7)
//					{
//						DrawButton(BagButton);
//						i++;
//					}
//					//左上
//					else if (i == 8)
//					{
//						DrawButton(DataButton);
//						UpdateData(DataButton, HP, ATK, DF, Lvl, Name);
//						i++;
//					}
//					//右上
//					else if (i == 9)
//					{
//						DrawButton(AgeCoinButton);
//						UpdateCoin_Age(AgeCoinButton, Age, Coin);
//						i++;
//					}
//
//				}
//			}
//		}
//		IsBeginner = false;
//		putimage(0, 0, &imgbk);
//	}
//	return;
//}
//
////突破界面显示
//void LvlUpScreen(int rate) {
//	IMAGE LvlUpUI;
//	loadimage(&LvlUpUI, "LvlUpUI.png");
//	putimage(512 - LvlUpUI.getwidth() / 2, 650, &LvlUpUI);
//	settextcolor(RGB(0, 0, 0));
//	settextstyle(15, 0, "宋体");
//	char text[10];
//	sprintf(text, "%d", rate);
//	outtextxy(512 - 60, 650 + textheight(text), "突破概率:");
//	outtextxy(512 + 10, 650 + textheight(text), text);
//	outtextxy(512 + textwidth(text) + 10, 650 + textheight(text), "%");
//}
//
////点击增加经验
//void Click(ExMessage m, IMAGE imgBK) {
//	if (m.message == WM_LBUTTONDOWN)
//	{
//		peekmessage(&m, EX_MOUSE);
//		if (m.message == WM_LBUTTONUP)
//		{
//			CurExp += 1;
//			putimage(0, 0, &imgBK);
//		}
//	}
//}
//
////背包装备显示
//void OpenBag(IMAGE imgBag) {
//	//主体框架
//	int h = imgBag.getheight();
//	int w = imgBag.getwidth();
//	putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
//	DrawButton(CloseButton_Bag);
//	//文字
//	//1.标题
//	settextcolor(BLACK);
//	setbkmode(TRANSPARENT);
//	settextstyle(40, 0, "宋体");
//	const char* text = "背包";
//	int textw = textwidth(text);
//	int xx = 512 - (textw / 2);
//	outtextxy(xx, 512 - 470, text);
//	ShowItemInBag();
//}
//
////显示装备
//void ShowItemInBag() {
//	for (int i = 0; i < 100; i++)
//	{
//
//	}
//}
//
////商城界面
//void ShowMall(IMAGE imgBag) {
//	int h = imgBag.getheight();
//	int w = imgBag.getwidth();
//	putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
//	DrawButton(CloseButton_Shop);
//	ShowitemInMall();
//
//}
//
//void ShowitemInMall() {
//	for (int i = 0; i < NUM; i++)
//	{
//		DrawButton(MallItem[i]);
//	}
//}
//
////历练框
//void GoAdventure(IMAGE imgBag) {
//	int h = imgBag.getheight();
//	int w = imgBag.getwidth();
//	putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
//	DrawButton(CloseButton_Adven);
//	//调用adven库
//}
//
////突破
//void TuPo(int rate,IMAGE imgBK) {
//	Lvl += 1;
//	CurExp -= MaxExp;
//	
//}
//
////保存
////保存是否是新手，三维，概率，等级，经验值，最大经验值，年龄，金币，姓名，
//// 装备信息
//void Save_All() {
//	FILE* file = fopen("data.txt", "w");
//	fprintf(file, "%d %f %f %f %d %d %d %d %d %d %s",
//		IsBeginner, HP, ATK, DF, rate, Lvl, CurExp, MaxExp, Age, Coin, Name);
//	fclose(file);
//	//以及装备背包保存
//}
//
////读取数据
////装备信息
//void Load_All(){
//	FILE* file = fopen("data.txt", "r");
//	fscanf(file, "%d %f %f %f %d %d %d %d %d %d %s",
//		&IsBeginner, &HP, &ATK, &DF, &rate, &Lvl, &CurExp, &MaxExp, &Age, &Coin, &Name);
//	fclose(file);
//	//以及装备背包读取
//}
//
//int main()
//{
//	//创建主窗口
//	HWND MainCamera = initgraph(1024, 1024);
//	//加载图片
//	IMAGE imgBK, imgBag, LvlUpUI;
//	loadimage(&imgBK, "beijintu.png");
//	loadimage(&imgBag, "BeiBao(1).png");
//	loadimage(&LvlUpUI, "LvlUpUI.png");
//	//添加背景图
//	putimage(0, 0, &imgBK);
//	setfillcolor(RGB(0, 0, 0));
//	fillroundrect(200, 765, 824, 785, 20, 10);
//	Load_All();
//
//
//	//生成随机名字
//	GetName();
//	//获取鼠标消息
//	ExMessage m;
//	peekmessage(&m, EX_MOUSE);
//	Instruction(m, imgBK);
//	//开始
//	BeginBatchDraw();
//	while (1)
//	{
//
//		DrawButton(XiuXing);
//		DrawButton(BagButton);
//		DrawButton(Adventure);
//		DrawButton(ShoppingMall);
//		DrawButton(LvlUpButton);
//		DrawButton(DataButton);
//		DrawButton(AgeCoinButton);
//		DrawButton(CloseButton_All);
//		//经验条
//		setfillcolor(RGB(0, 0, 0));
//		fillroundrect(200, 765, 824, 785, 20, 10);
//
//		UpdateExp_Lvl(CurExp, MaxExp);
//		UpdateData(DataButton, HP, ATK, DF, Lvl, Name);
//		CanLvlUp(LvlUpButton, CurExp, MaxExp);
//		UpdateCoin_Age(AgeCoinButton, Age, Coin);
//		LvlUpScreen(rate);
//		//判断是否去修炼
//
//		peekmessage(&m, EX_MOUSE);
//		Click(m,imgBK);
//		//判断是否去历练
//		if (IsClickButton(XiuXing, m))
//		{
//		}
//		if (IsClickButton(BagButton, m))
//		{
//			OpenBag(imgBag);
//			CloseButton_Bag->Canclick = true;
//		}
//		if (IsClickButton(CloseButton_Bag, m))
//		{
//			putimage(0, 0, &imgBK);
//			CloseButton_Bag->Canclick = false;
//		}
//
//
//		//历练
//		if (IsClickButton(Adventure, m))
//		{
//			GoAdventure(imgBag);
//			CloseButton_Adven->Canclick = true;		
//		}
//		//continue
//		if (1) 
//		{
//
//		}
//
//		if (IsClickButton(CloseButton_Adven, m))
//		{
//			putimage(0, 0, &imgBK);
//			CloseButton_Adven->Canclick = false;
//		}
//		//商城
//
//
//		if (IsClickButton(ShoppingMall, m))
//		{			
//			ShowMall(imgBag);
//			CloseButton_Shop->Canclick = true;
//		}
//		if (IsClickButton(CloseButton_Adven, m))
//		{
//			putimage(0, 0, &imgBK);
//			CloseButton_Adven->Canclick = true;
//		}
//
//		//突破
//		if (IsClickButton(LvlUpButton, m))
//		{
//			TuPo(rate,imgBK);
//		}
//		//退出并保存
//		if (IsClickButton(CloseButton_All, m))
//		{
//			Save_All();
//			break;
//		}
//		
//		FlushBatchDraw();
//	}
//	EndBatchDraw();
//	closegraph();
//
//	return 0;
//}
//
//
//
