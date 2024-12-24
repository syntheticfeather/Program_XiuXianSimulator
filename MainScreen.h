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
#include"Shop.h"
#include"Adven.h"
#include"XiuXian.h"

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
	bool Canclick = true;
};
struct Player_
{
	int IsBeginner = 0;
	float HP = 10.0;
	float ATK = 5.0;
	float DF = 1.0;
	int Recovery = 1;//恢复能力(战斗回血)
	int rate = 80;
	int Lvl = 0;
	int CurExp = 8;
	int MaxExp = 10;
	int ExpSpeed = 1;
	int Age = 1000;
	int Coin = 4;
	char Name[10] = "";
	struct Weapon* WearingWeapon = NULL;//武器槽
	struct Armor* WearingArmor = NULL;//防具槽
	struct Decoration* WearingDecoration = NULL;//饰品槽
};
void GetName(Player_*);
Button* MakeButton(int x, int y, int w, int h,
	const char* Text, COLORREF incolor, COLORREF outcolor, COLORREF ClickColor, bool);
void DrawButton(Button*);
void DrawButton(Button*, COLORREF);
bool IsInButton(Button*, ExMessage);
bool IsClickButton(Button*, ExMessage);
void CanLvlUp(Button*, int CurExp, int MaxExp, Player_*);
void UpdateData(Button*, float HP, float ATK, float DF, int Lvl, char* Name);
void UpdateCoin_Age(Button*, int Age, int Coin);
void UpdateExp_Lvl(int CurExp, int MaxExp);
void Instruction(ExMessage, IMAGE);
void LvlUpScreen(int);
//void Click(ExMessage, IMAGE);
void OpenBag(IMAGE, Node* HeadNode);
//待完成
void ShowItemInBag(Node* HeadNode);
void ShowMall(IMAGE);
void ShowitemInMall();
void GoAdventure(IMAGE, Player_*);
void TuPo(int rate, IMAGE imgBK, Player_*);
//待完成
void initMall();
void Save_All(Player_*,Node*);
void Load_All(Player_*,Node**);
void Update(Player_*);
void buyItem(Player_* player, int Type);
Node* TurnToNode(Node* HeadNode, int num);

#endif // !TT
