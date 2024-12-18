#define _CRT_SECURE_NO_WARNINGS 1

#include<easyx.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<pthread.h>

#include"ShoppingMall.h"



#define NUM 4

//��ť�ṹ�壬��¼��ť�ĸ��ǵ�λ��
struct Button
{
	//���ң��ϣ���
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	COLORREF curcolor = BLACK;
	COLORREF incolor = BLACK;
	COLORREF outcolor = BLACK;
	COLORREF ClickColor;
	char* text;
	bool Canclick = true;

};




void GetName();
Button* MakeButton(int x, int y, int w, int h,
	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor);
void DrawButton(Button*);
void DrawButton(Button*, COLORREF);
bool IsInButton(Button*, ExMessage);
bool IsClickButton(Button*, ExMessage);
void CanLvlUp(Button*, int CurExp, int MaxExp);
void UpdateData(Button*, float HP, float ATK, float DF, int Lvl, char* Name);
void UpdateCoin_Age(Button*, int Age, int Coin);
void UpdateExp_Lvl(int CurExp, int MaxExp);
void Instruction(ExMessage, IMAGE);
void LvlUpScreen(int);
void Click(ExMessage, IMAGE);
void OpenBag(IMAGE);
//�����
void ShowItemInBag();
void ShowMall(IMAGE);
void ShowitemInMall();
void GoAdventure(IMAGE);
void TuPo(int rate, IMAGE imgBK);
//�����
void Save_All();
void Load_All();


bool IsBeginner = true;
bool IsQuit = false;
float HP = 1.0;
float ATK = 1.0;
float DF = 1.0;
int rate = 80;
int Lvl = 0;
int CurExp = 8;
int MaxExp = 10;
int Age = 1000;
int Coin = 4;
char Name[10];
char NameList[20][20] = {

	"³ī��","��ī��","��ī��","��ŵ��","�о���",
	"³����","˾�ܹ�Ң","�ﻴ��","������","̫������",
	"��Ȩ��","��ǧ��","�Ϲ��ƹ�","������","������",
	"���Ժ�","Խ����","Խ��ڤ","������","��Ǻ�",
};

//�ȼ�
const char LvlList[71][20] = {
	"������һ��","�����ڶ���","����������","�������Ľ�","���������","����������","�������߽�","�����ڰ˽�","�����ھŽ�","������Բ��",
	"������һ��","�����ڶ���","����������","�������Ľ�","���������","����������","�������߽�","�����ڰ˽�","�����ھŽ�","������Բ��",
	"����һ��","���ڶ���","��������","�����Ľ�","�������","��������","�����߽�","���ڰ˽�","���ھŽ�","����Բ��",
	"ԪӤ��һ��","ԪӤ�ڶ���","ԪӤ������","ԪӤ���Ľ�","ԪӤ�����","ԪӤ������","ԪӤ���߽�","ԪӤ�ڰ˽�","ԪӤ�ھŽ�","ԪӤ��Բ��",
	"������һ��","�����ڶ���","����������","�������Ľ�","���������","����������","�������߽�","�����ڰ˽�","�����ھŽ�","������Բ��",
	"������һ��","�����ڶ���","����������","�������Ľ�","���������","����������","�������߽�","�����ڰ˽�","�����ھŽ�","������Բ��",
	"������һ��","�����ڶ���","����������","�������Ľ�","���������","����������","�������߽�","�����ڰ˽�","�����ھŽ�","������Բ��",
	"��"
};

//���ֽ̳̾�������
const char BeginText[10][100] = {
	"�쳾��ǧС���磬�������������ɡ���ӭ��������ģ������",
	"��һ�������ڳ��ɶɽ�ʱ���ұ��ֵ����ű��ѣ���������ص���18�����ꡣ",
	"�ػ�һ������������Ƿϣ���Ҫ��������������һ�С�",
	"�������ӿ�������",
	"����ֵ���˵��ͻ�ư�������ͻ��",
	"�ﵽһ����Ϊ�������������̽������",
	"��ʯ�������̳��й���װ���Լ��鵤��ҩ,���߳��۲���Ҫ��װ��",
	"�ڱ��������п��Ը���װ��.�鿴���еĵ�ҩ",
	"��ľ������ά���Ի���ʾ�����ϡ�",
	"��ʯ�����Լ�����ʱ������ʾ�����ϡ�",

};
//�������ť
Button* XiuXing = MakeButton(128 - 50, 929, 100, 50, "����", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
Button* BagButton = MakeButton(384 - 50, 929, 100, 50, "����", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
Button* Adventure = MakeButton(640 - 50, 929, 100, 50, "����", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
Button* ShoppingMall = MakeButton(1024 - 178, 929, 100, 50, "�̳�", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
Button* LvlUpButton = MakeButton(512 - 50, 700, 100, 50, "ͻ��", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));

//��ʾ
Button* DataButton = MakeButton(50, 50, 100, 125, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));
Button* AgeCoinButton = MakeButton(1024 - 150, 50, 100, 125, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));
Button* NameButton = MakeButton(1024 - 150, 50, 100, 125, "", RGB(137, 207, 240), RGB(255, 222, 146), RGB(30, 144, 255));

//�رս��水ť
Button* CloseButton_Bag = MakeButton(720, 50, 35, 35, "�ر�", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
Button* CloseButton_Adven = MakeButton(512 - 50, 600, 100, 40, "�ر�", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));
Button* CloseButton_Shop = MakeButton(512 - 50, 600, 100, 40, "�ر�", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));

//������ť
Button* CloseButton_All = MakeButton(1024 - 90, 10, 70, 35, "���沢�˳�", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255));

//putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
Button* MallItem[NUM] = {
	MakeButton(512 - 200, 200, 150, 60, "1", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
	MakeButton(512 + 50, 200, 150, 60, "2", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
	MakeButton(512 - 200, 300, 150, 60, "3", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
	MakeButton(512 + 50, 300, 150, 60, "4", RGB(137, 207, 240), RGB(255, 166, 87), RGB(30, 144, 255)),
};

//һ������ṹ�壬����ṹ���������outtextxy��ӡ����һ����ť����������ʹ��

//�̵����ָ������Ʒ����һ����ť
//��ʼ������
void GetName() {
	if (Name == NULL)
	{
		srand((unsigned int)time(NULL));
		strcpy(Name, NameList[rand() % 20]);
	}
}

//��ʼ����ť
Button* MakeButton(int x, int y, int w, int h,
	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor)
{
	Button(*btn) = (Button*)malloc(sizeof(Button));
	//���ð�ť
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

//���ư�ť
void DrawButton(Button* bn)
{
	//��ť����
	setlinecolor(RGB(32, 44, 57));
	setfillcolor(bn->curcolor);
	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h, 25, 25);
	//��������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "����");
	//���־���
	int textw = textwidth(bn->text);
	int texth = textheight(bn->text);
	int xx = bn->x + (bn->w - textw) / 2;
	int yy = bn->y + (bn->h - texth) / 2;
	outtextxy(xx, yy, bn->text);
}
//ָ����ɫ���ư�ť
void DrawButton(Button* bn, COLORREF Color)
{
	//��ť����
	setlinecolor(RGB(32, 44, 57));
	setfillcolor(Color);
	solidroundrect(bn->x, bn->y, bn->x + bn->w, bn->y + bn->h, 25, 25);
	//��������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "����");
	//���־���
	int textw = textwidth(bn->text);
	int texth = textheight(bn->text);
	int xx = bn->x + (bn->w - textw) / 2;
	int yy = bn->y + (bn->h - texth) / 2;
	outtextxy(xx, yy, bn->text);
}

//�ж��Ƿ��ڰ�ť�ڲ������������ɫ�仯
bool IsInButton(Button* bn, ExMessage m) {
	if (bn->x< m.x && bn->x + bn->w >m.x && bn->y <m.y && bn->y + bn->h >m.y)
	{
		bn->curcolor = bn->incolor;
		return true;
	}
	bn->curcolor = bn->outcolor;
	return false;
}

//��ť����жϣ������ɫ�仯
bool IsClickButton(Button* bn, ExMessage m) {
	if (IsInButton(bn, m) && m.message == WM_LBUTTONDOWN)
	{
		if (bn->Canclick == false)
		{
			return false;
		}
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

//ͻ�ư�ť�ھ��鲻��ʱ����
void CanLvlUp(Button* btn, int CurExp, int MaxExp) {
	if (CurExp < MaxExp or Lvl == 70)
	{
		DrawButton(btn, RGB(139, 134, 130));
		btn->Canclick = false;
	}
	else
	{
		btn->Canclick = true;
		setfillcolor(btn->outcolor);
		DrawButton(btn);
	}
}

//ʵ����ά���ݵ���ʾ4
void UpdateData(Button* btn, float HP, float ATK, float DF, int Lvl, char* Name) {
	//��������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "����");
	//���־���
	char HPText[10], ATKText[10], DFText[10];
	sprintf(HPText, "%d", (int)HP);
	sprintf(ATKText, "%d", (int)ATK);
	sprintf(DFText, "%d", (int)DF);

	int textw = textwidth(HPText);
	int texth = textheight(HPText);
	int xx = btn->x + (btn->w - textw) / 2;
	int yy = btn->y + btn->h / 2 - 5;

	outtextxy(btn->x + 15, btn->y + btn->h / 6, Name);
	outtextxy(btn->x + 15, btn->y + btn->h / 3, LvlList[Lvl]);
	outtextxy(xx - 25, yy + btn->h / 8, "����:");
	outtextxy(xx + 25, yy + btn->h / 8, HPText);
	outtextxy(xx - 25, yy + btn->h / 4, "����:");
	outtextxy(xx + 25, yy + btn->h / 4, ATKText);
	outtextxy(xx - 25, yy + btn->h / 8 * 3, "����:");
	outtextxy(xx + 25, yy + btn->h / 8 * 3, DFText);
}

//ʵ�ֽ���Լ��������ʾ
void UpdateCoin_Age(Button* btn, int Age, int Coin) {
	char AgeText[10], CoinText[10];
	sprintf(AgeText, "%d", Age);
	sprintf(CoinText, "%d", Coin);

	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "����");
	int textw = textwidth(AgeText);
	int texth = textheight(AgeText);
	int xx = btn->x + (btn->w - textw) / 2;

	outtextxy(xx - 30, btn->y + btn->h / 3 - 5, "����:");
	outtextxy(xx + 10, btn->y + btn->h / 3 - 5, AgeText);
	outtextxy(xx + textw + 10, btn->y + btn->h / 3 - 5, "��");

	outtextxy(xx - 30, btn->y + btn->h / 3 * 2 - 5, "��ʯ:");
	outtextxy(xx + 10, btn->y + btn->h / 3 * 2 - 5, CoinText);
	outtextxy(xx + textw + 10, btn->y + btn->h / 3 * 2 - 5, "ö");
}

//���鼴����������ʾ
void UpdateExp_Lvl(int CurExp, int MaxExp) {
	//����
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
	char textCur[10], textMax[10];
	sprintf(textCur, "%d", CurExp);
	sprintf(textMax, "%d", MaxExp);
	outtextxy(512 - (textwidth(textCur) / 2) - 70, 800, "����ֵ:");
	settextcolor(BLACK);
	outtextxy(512, 800, textCur);
	outtextxy(512 + (textwidth(textCur)) + 20, 800, "/");
	outtextxy(512 + (textwidth(textCur)) + 45, 800, textMax);
	//������
	setfillcolor(RGB(255, 222, 146));
	float rate = (CurExp + 0.001) / MaxExp;
	//�����������
	if (rate > 1)
	{
		rate = 1.0;
	}
	int right = 200 + (rate * 622);
	//int right = 512;
	fillroundrect(202, 767, right, 783, 20, 10);
}

//���ֽ̳�ָ��
void Instruction(ExMessage m, IMAGE imgbk) {
	if (IsBeginner)
	{
		settextcolor(WHITE);
		outtextxy(200, 150, BeginText[0]);
		for (int i = 1; i < 11;)
		{
			peekmessage(&m, EX_MOUSE);
			if (m.message == WM_LBUTTONDOWN)
			{
				peekmessage(&m, EX_MOUSE);
				if (m.message == WM_LBUTTONUP)
				{
					setbkmode(OPAQUE);
					setbkcolor(BLACK);
					settextcolor(WHITE);
					outtextxy(200, 150 + (50 * i), BeginText[i]);
					if (i < 4 || i == 10)
					{
						i++;
					}
					//���û����
					else if (i == 3)
					{
						i++;
						DrawButton(XiuXing);
					}
					//ͻ�ư�ť
					else if (i == 4)
					{
						DrawButton(LvlUpButton);
						i++;
					}
					//������ť
					else if (i == 5)
					{
						DrawButton(Adventure);
						i++;
					}
					//�̳ǰ�ť
					else if (i == 6)
					{
						DrawButton(ShoppingMall);
						i++;
					}
					//������ť
					else if (i == 7)
					{
						DrawButton(BagButton);
						i++;
					}
					//����
					else if (i == 8)
					{
						DrawButton(DataButton);
						UpdateData(DataButton, HP, ATK, DF, Lvl, Name);
						i++;
					}
					//����
					else if (i == 9)
					{
						DrawButton(AgeCoinButton);
						UpdateCoin_Age(AgeCoinButton, Age, Coin);
						i++;
					}

				}
			}
		}
		IsBeginner = false;
		putimage(0, 0, &imgbk);
	}
	return;
}

//ͻ�ƽ�����ʾ
void LvlUpScreen(int rate) {
	IMAGE LvlUpUI;
	loadimage(&LvlUpUI, "LvlUpUI.png");
	putimage(512 - LvlUpUI.getwidth() / 2, 650, &LvlUpUI);
	settextcolor(RGB(0, 0, 0));
	settextstyle(15, 0, "����");
	char text[10];
	sprintf(text, "%d", rate);
	outtextxy(512 - 60, 650 + textheight(text), "ͻ�Ƹ���:");
	outtextxy(512 + 10, 650 + textheight(text), text);
	outtextxy(512 + textwidth(text) + 10, 650 + textheight(text), "%");
}

//������Ӿ���
void Click(ExMessage m, IMAGE imgBK) {
	if (m.message == WM_LBUTTONDOWN)
	{		
		peekmessage(&m, EX_MOUSE);
		if (m.message == WM_LBUTTONUP)
		{
			CurExp += 1;
			putimage(0, 0, &imgBK);
		}
	}
}

//����װ����ʾ
void OpenBag(IMAGE imgBag) {
	//������
	int h = imgBag.getheight();
	int w = imgBag.getwidth();
	putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
	DrawButton(CloseButton_Bag);
	//����
	//1.����
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, "����");
	const char* text = "����";
	int textw = textwidth(text);
	int xx = 512 - (textw / 2);
	outtextxy(xx, 512 - 470, text);
	ShowItemInBag();
}

//��ʾװ��
void ShowItemInBag() {
	//while (Node != NULL)
	//{

	//}
}

//�̳ǽ���
void ShowMall(IMAGE imgBag) {
	int h = imgBag.getheight();
	int w = imgBag.getwidth();
	putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
	DrawButton(CloseButton_Shop);
	ShowitemInMall();

}

void ShowitemInMall() {
	for (int i = 0; i < NUM; i++)
	{
		DrawButton(MallItem[i]);
	}
}

//������
void GoAdventure(IMAGE imgBag) {
	int h = imgBag.getheight();
	int w = imgBag.getwidth();
	putimage(512 - (w / 2), 512 - (h / 2) - 170, &imgBag);
	DrawButton(CloseButton_Adven);
	//����adven��
}

//ͻ��
void TuPo(int rate,IMAGE imgBK) {
	if (Lvl < 70)
	{
		Lvl += 1;
		CurExp -= MaxExp;	
	}
	putimage(0, 0, &imgBK);
}

//����
//�����Ƿ������֣���ά�����ʣ��ȼ�������ֵ�������ֵ�����䣬��ң�������
// װ����Ϣ
void Save_All() {
	FILE* file = fopen("data.txt", "w");
	fprintf(file, "%d %f %f %f %d %d %d %d %d %d %s",
		IsBeginner, HP, ATK, DF, rate, Lvl, CurExp, MaxExp, Age, Coin, Name);
	fclose(file);
	//�Լ�װ����������
}

//��ȡ����
//װ����Ϣ
void Load_All() {
	FILE* file = fopen("data.txt", "r");
	fscanf(file, "%d %f %f %f %d %d %d %d %d %d %s",
		&IsBeginner, &HP, &ATK, &DF, &rate, &Lvl, &CurExp, &MaxExp, &Age, &Coin, &Name);
	fclose(file);
	//�Լ�װ��������ȡ
}


struct ThreadData {
	Button* button;
	ExMessage* message;
	IMAGE imgBK = NULL;
};

// �̻߳ص�����
void* handleButtonClick(void* arg) {
	ThreadData* data = (ThreadData*)arg;
	if (IsClickButton(data->button, *data->message)) {
		// ���ݰ�ť���ִ����Ӧ����
		if (data->button == XiuXing) {
			putimage(0, 0, &data->imgBK);
			CloseButton_Adven->Canclick = false;
			CloseButton_Shop->Canclick = false;
			CloseButton_Bag->Canclick = false;
		}
		else if (data->button == BagButton) {
			OpenBag(data->imgBK);
			CloseButton_Bag->Canclick = true;
		}
		else if (data->button == Adventure) {
			GoAdventure(data->imgBK);
			CloseButton_Adven->Canclick = true;
		}
		else if (data->button == ShoppingMall) {
			ShowMall(data->imgBK);
			CloseButton_Shop->Canclick = true;
		}
		else if (data->button == LvlUpButton) {
			TuPo(rate,data->imgBK);
		}
		else if (data->button == CloseButton_All) {
			Save_All();
			// ��������������һ����־λ���˳���ѭ��
			IsQuit = true;
		}		
	}
	return NULL;
}

int main()
{
	//����������
	HWND MainCamera = initgraph(1024, 1024);
	//����ͼƬ
	IMAGE imgBK, imgBag, LvlUpUI;
	loadimage(&imgBK, "beijintu.png");
	loadimage(&imgBag, "BeiBao(1).png");
	loadimage(&LvlUpUI, "LvlUpUI.png");
	//��ӱ���ͼ
	putimage(0, 0, &imgBK);
	setfillcolor(RGB(0, 0, 0));
	fillroundrect(200, 765, 824, 785, 20, 10);
	Load_All();


	//�����������
	GetName();
	//��ȡ�����Ϣ
	ExMessage m;
	peekmessage(&m, EX_MOUSE);
	Instruction(m, imgBK);
	//��ʼ
	BeginBatchDraw();
	while (1)
	{

		DrawButton(XiuXing);
		DrawButton(BagButton);
		DrawButton(Adventure);
		DrawButton(ShoppingMall);
		DrawButton(LvlUpButton);
		DrawButton(DataButton);
		DrawButton(AgeCoinButton);
		DrawButton(CloseButton_All);
		//������
		setfillcolor(RGB(0, 0, 0));
		fillroundrect(200, 765, 824, 785, 20, 10);
		//��������
		UpdateExp_Lvl(CurExp, MaxExp);
		UpdateData(DataButton, HP, ATK, DF, Lvl, Name);
		CanLvlUp(LvlUpButton, CurExp, MaxExp);
		UpdateCoin_Age(AgeCoinButton, Age, Coin);
		LvlUpScreen(rate);

		peekmessage(&m, EX_MOUSE);

		Click(m,imgBK);
		//����̷�ֹ����
		pthread_t threads[6]; // �߳�����
		ThreadData threadData[6]; // �߳�����

		// Ϊÿһ���߳����ò���
		threadData[0] = { XiuXing, &m, imgBK };
		threadData[1] = { BagButton, &m, imgBag };
		threadData[2] = { Adventure, &m, imgBag};
		threadData[3] = { ShoppingMall, &m, imgBag };
		threadData[4] = { LvlUpButton, &m};
		threadData[5] = { CloseButton_All, &m};

		//���̿�ʼ
		for (int i = 0; i < 6; i++) 
		{
			pthread_create(&threads[i], NULL, handleButtonClick, (void*)&threadData[i]);
		}

		//�����رհ�ť
		if (IsClickButton(CloseButton_Bag,m))
		{
			putimage(0, 0, &imgBK);
			CloseButton_Bag->Canclick = false;

		}
		if (IsClickButton(CloseButton_Adven, m))
		{
			putimage(0, 0, &imgBK);
			CloseButton_Adven->Canclick = false; 

		}
		if (IsClickButton(CloseButton_Shop, m))
		{
			putimage(0, 0, &imgBK);
			CloseButton_Shop->Canclick = false;

		}

		//ս��������continue
		if (CloseButton_Adven->Canclick == true)
		{
			//��һ���µİ�ť
			//������һ���¼�,��д��
			//next()
		}

		//�̵깺����
		if (CloseButton_Shop->Canclick == true)
		{
			for (int i = 0; i < NUM; i++)
			{
				if (IsClickButton(MallItem[i], m))
				{
					//��д����
					//Buy()
				}
			}
		}

		//��������/ʹ�ö���
		if (CloseButton_Bag->Canclick == true)
		{
			//�ж��Ƿ���
		}
		//for ( !=NULL)

		

		//�ռ����н���
		for (int i = 0; i < 6; i++) 
		{
			pthread_join(threads[i], NULL);
		}
		if (IsQuit == true)
		{
			break;
		}















		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();

	return 0;
}



