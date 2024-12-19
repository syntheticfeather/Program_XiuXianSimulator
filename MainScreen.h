#pragma once
#ifndef TT
#define TT
#include<easyx.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<pthread.h>



struct Player_
{
	bool IsBeginner = false;
	float HP = 1.0;
	float ATK = 1.0;
	float DF = 1.0;
	int Recovery = 1;//�ָ�����(ս����Ѫ)
	int rate = 80;
	int Lvl = 0;
	int CurExp = 8;
	int MaxExp = 10;
	int Age = 1000;
	int Coin = 4;
	char Name[10] = "";
	struct Weapon* WearingWeapon;//������
	struct Armor* WearingArmor;//���߲�
	struct Decoration* WearingDecoration;//��Ʒ��

};
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



#endif // !TT
