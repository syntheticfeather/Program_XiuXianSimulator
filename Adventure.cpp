#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include<easyx.h>
#include"Adven.h"
#include"MainScreen.h"

//刷屏标识符，不动
int FF;
extern IMAGE imgBag;
extern Button* CloseButton_Adven;
extern Button* ContinueButton;

//--------------------------------------------------//--------------------------------------------------//
//struct Player_
//{
//    bool IsBeginner = false;
//    float HP = 1.0;
//    float ATK = 1.0;
//    float DF = 1.0;
//    int Recovery = 1;//恢复能力(战斗回血)
//    int rate = 80;
//    int Lvl = 0;
//    int CurExp = 8;
//    int MaxExp = 10;
//    int Age = 1000;
//    int Coin = 4;
//    char Name[10] = "";
//    struct Weapon* WearingWeapon;//武器槽
//    struct Armor* WearingArmor;//防具槽
//    struct Decoration* WearingDecoration;//饰品槽
//
//};
struct Weapon {
	int Attack;
	int Money;
};
struct Armor {
	int HP;
	int Defence;
	int Money;
};
struct Decoration {
	int Attack;
	int HP;
	int Defence;
	int Money;
	int Recovery;
};
//伤害公式:造成伤害=攻击者的攻击×(1-护甲/100000+护甲)
//免伤率=护甲/100000+护甲

//--------------------------------------------------//--------------------------------------------------//


int RandomDigit(int Range, int Start) {
	time_t NowTime;
	NowTime = time(NULL);//获取当前时间
	srand((unsigned)NowTime);
	if (Range == 0) { Range++; }
	return((rand() % Range) + Start);
}

//随机数函数产生一个范围为Range,从Start开始的随机数
//--------------------------------------------------//--------------------------------------------------//

int FightModel(struct Player_* Player, struct Player_* Enemy)//注意此处传入的是结构指针!
{
	int flag = 1;//标识是否处于战斗状态
	int Attacker = 0;//用来标识攻击者是谁,'0'即Player,'1'即Enemy
	int Winner = 0;//默认玩家0胜利,若敌人胜利,则标记为1
	int EnemyHp = Enemy->HP;
	int PlayerHp = Player->HP;

	int i = 0;
	while (flag) {
		if (i == 2)
		{
			putimage(262, 42, &imgBag);//34			
			if (FF == 3)	
			{
				outtextxy(262 + 250 - textwidth("你御剑准备前往山脚下的坊市感受人间烟火,")/2, 42 + 100, "你御剑准备前往山脚下的坊市感受人间烟火,");
				outtextxy(262 + 250 - textwidth("突然一道法术袭来,你游云般躲开后,发现来人正是你的仇敌!") / 2, 42 + 140, "突然一道法术袭来,你游云般躲开后,发现来人正是你的仇敌!");
			}
			DrawButton(CloseButton_Adven);
			DrawButton(ContinueButton);	
			i = 0;
		}
		switch (Attacker) {
		case 0:EnemyHp -= (Player->ATK) * (1 - (Enemy->DF) / (100000 + (Enemy->DF)));
			//printf("敌人受到了攻击!本次攻击造成%d点伤害,敌人还剩血量%.2f!\n", (Player->ATK) * (1 - (Enemy->DF) / (100000 + (Enemy->DF))), EnemyHp);
			//outtextxy(262, 42 + 100, ("敌人受到了攻击!本次攻击造成%d点伤害,敌人还剩血量%.2f!\n", (Player->ATK) * (1 - (Enemy->DF) / (100000 + (Enemy->DF))), EnemyHp));
			//sprintf(DFText, "%d", (int)DF);
			char text1[100], text2[100];
			sprintf(text1, "%d", (int)((Player->ATK) * (1 - (2, Enemy->DF) / (100000 + (Enemy->DF)))));
			sprintf(text2, "%d", (int)EnemyHp);
			outtextxy(512 - (textwidth("敌人受到了攻击!本次攻击造成") + textwidth(text1) + textwidth("点伤害,")) / 2, 42 + 200, "敌人受到了攻击!本次攻击造成");
			outtextxy(512 - (textwidth("敌人受到了攻击!本次攻击造成") + textwidth(text1) + textwidth("点伤害,")) / 2 + textwidth("敌人受到了攻击!本次攻击造成"), 42 + 200, text1);
			outtextxy(512- (textwidth("敌人受到了攻击!本次攻击造成") + textwidth(text1) + textwidth("点伤害,")) / 2 + textwidth("敌人受到了攻击!本次攻击造成") + textwidth(text1), 42 + 200, "点伤害,");
			outtextxy(512- (textwidth("敌人还剩血量") + textwidth(text2)) / 2, 42 + 240, "敌人还剩血量");
			outtextxy(512- (textwidth("敌人还剩血量") + textwidth(text2)) / 2 + textwidth("敌人还剩血量"), 42 + 240, text2);
			i++;
			//此处注意需要更改为操作端显示!!!!!

			Attacker = 1;//转换攻击者
			if (EnemyHp <= 0) { flag = 0; Winner = 0; }//判断是否死亡 死亡时循环结束
			break;//无论是否死亡 跳出switch

		case 1:PlayerHp -= (Enemy->ATK) * (1 - (Player->DF) / (100000 + (Player->DF)));
			//printf("您受到了攻击!本次攻击造成%d点伤害,您还剩血量%.2f!\n", (Enemy->ATK) * (1 - (Player->DF) / (100000 + (Player->DF))), PlayerHp);
			//outtextxy(262, 42 + 280, "您受到了攻击!本次攻击造成%d点伤害,您还剩血量%.2f!\n");
			//此处注意需要更改为操作端显示!!!!!
			char text3[100], text4[100];
			sprintf(text3, "%d", (int)((Enemy->ATK) * (1 - (Player->DF) / (100000 + (Player->DF)))));
			sprintf(text4, "%d", (int)PlayerHp);
			outtextxy(512 - (textwidth("您受到了攻击!本次攻击造成") +  textwidth(text3) + textwidth("点伤害,")) / 2, 42 + 320, "您受到了攻击!本次攻击造成");
			outtextxy(512- (textwidth("您受到了攻击!本次攻击造成") + textwidth(text3) + textwidth("点伤害,")) / 2 + textwidth("您受到了攻击!本次攻击造成"), 42 + 320, text3);
			outtextxy(512- (textwidth("您受到了攻击!本次攻击造成") + textwidth(text3) + textwidth("点伤害,")) / 2 + textwidth("您受到了攻击!本次攻击造成") + textwidth(text3), 42 + 320, "点伤害,");
			outtextxy(512 - (textwidth("您还剩血量") + textwidth(text4)) / 2, 42 + 360, "您还剩血量");
			outtextxy(512- (textwidth("您还剩血量") + textwidth(text4)) / 2 + textwidth("您还剩血量"), 42 + 360, text4);
			i++;
			Attacker = 0;//转换攻击者
			if (PlayerHp <= 0) { flag = 0; Winner = 1; }//判断是否死亡 死亡时循环结束
			break;//无论是否死亡 跳出switch
		}
		BeginBatchDraw();
		Sleep(1000);
	}
	FlushBatchDraw();
	if (Winner == 0)
		return 1;
	else if (Winner == 1)
		return 0;
	else return 4;
}

//本函数的作用时通过输入玩家和敌人的数值,进行回合制战斗,过程中在操作段可视化战斗
//传入格式 玩家,敌人  输出形式  玩家胜利 1,玩家失败0  程序运行错误 4


//--------------------------------------------------//--------------------------------------------------//

int Calculator(int Level, int CheckAspect)//CheckAspect参数 1/2/3 stand for HP/Attack/Defence
{
	int Aspect = CheckAspect;
	int CalculateTimes = Level;
	int result;

	if (Aspect == 1) {
		result = 10;
		while (CalculateTimes - 1) {
			result = (int)((double)(result + 2)) * 1.2;
			CalculateTimes -= 1;
		}
		return result;
	}

	if (Aspect == 2) {
		result = 5;
		while (CalculateTimes - 1) {
			result = (int)((double)(result + 2)) * 1.2;
			CalculateTimes -= 1;
		}
		return result;
	}

	if (Aspect == 3) {
		result = 10;
		while (CalculateTimes - 1) {
			result = (int)((double)(result + 2)) * 1.2;
			CalculateTimes -= 1;
		}
		return result;
	}
}
//本函数的功能是通过传入需要计算的等级以及三维方面,计算对应等级的基础属性

//--------------------------------------------------//--------------------------------------------------//
struct Player_* EnemyCreator(struct Player_* Player) {
	struct Player_* Enemy = (struct Player_*)calloc(1, sizeof(struct Player_));
	int Level = RandomDigit(2, (Player->Lvl));//随机生成敌人的等级
	if (Level == 0) {
		Level += 1;
	}
	Enemy->HP = RandomDigit((Calculator(Level, 1) + 3) * 0.4, (Calculator(Level, 1) + 3) * 0.9);
	Enemy->ATK = RandomDigit((Calculator(Level, 2) + 3) * 0.4, (Calculator(Level, 2) + 3) * 0.9);
	Enemy->DF = RandomDigit((Calculator(Level, 3) + 3) * 0.4, (Calculator(Level, 3) + 3) * 0.9);//敌人的属性在对应等级基础属性的0.8~1.2倍浮动
	return Enemy;
}//传入Player的数据,根据Player的等级随机生成敌人

//--------------------------------------------------//--------------------------------------------------//

//事件源码//
//一.无事发生 直接退出事件
//二.觅得传承 修为大增
//三.偶遇敌人1 战斗模块 胜利或失败
//五.登门求助 -钱 得装备 
//六.大能遗物 获得高阶装备
//七.中陷阱 扣钱续命
//八.误入毒瘴 扣属性
//九.上古宗门 突破概率增长
//十.得到高人指点 直接进阶
//十一.合欢宗七进七出



void AdventureCase_1(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "您进行了历练,无事发生.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("你出门转了一圈,发现天下太平,无事发生.\n");     //改为操作端显示!
	outtextxy(262 + 250 - textwidth("你出门转了一圈,发现天下太平,无事发生.") / 2, 42 + 100, "你出门转了一圈,发现天下太平,无事发生.");
	return;
}

//--------------------------------------------------//--------------------------------------------------//

//二.觅得传承 修为大增 H G
void AdventureCase_2(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "您觅得了炎帝的传承!修为增加!.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("正是寒风凛冽之时,你为取暖误入地底,却发现火山深处的地火,定睛一看,竟是炎帝萧炎的传承!修为增加十分之四,攻击提升.");//操作端显示
	outtextxy(262 + 250 - textwidth("正是寒风凛冽之时,你为取暖误入地底,却发现火山深处的地火,") / 2, 42 + 100, "正是寒风凛冽之时,你为取暖误入地底,却发现火山深处的地火,");
	outtextxy(262 + 250 - textwidth("定睛一看,竟是炎帝萧炎的传承!修为增加十分之二,攻击提升.") / 2, 42 + 140, "定睛一看,竟是炎帝萧炎的传承!修为增加十分之二,攻击提升.");
	Player->CurExp += Player->CurExp * 0.2;
	Player->ATK += Player->ATK * 0.1;
	return;
}

//--------------------------------------------------//--------------------------------------------------//

//三.偶遇敌人1 战斗模块 胜利或失败
void AdventureCase_3(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "你偶遇了敌人!进入战斗!.\n";
	char Description2[1000] = "经过一番苦战,你取得了胜利,并且获得了一大笔钱.\n";
	char Description3[1000] = "经过一番苦战,你失败遁走,并且损失了一大笔钱.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	//游戏内容
	//printf("你御剑准备前往山脚下的坊市感受人间烟火,突然一道法术袭来,你游云般躲开后,发现来人正是你的仇敌!");//操作端显示
	outtextxy(262 + 250 - textwidth("你御剑准备前往山脚下的坊市感受人间烟火,") / 2, 42 + 100, "你御剑准备前往山脚下的坊市感受人间烟火,");
	outtextxy(262 + 250 - textwidth("突然一道法术袭来,你游云般躲开后,发现来人正是你的仇敌!") / 2, 42 + 140, "突然一道法术袭来,你游云般躲开后,发现来人正是你的仇敌!");
	int j = FightModel(Player, EnemyCreator(Player));
	if (j == 1)//胜利
	{
		Player->Coin += (Player->Coin * 0.15) + 30;
		//printf("战斗胜利!你打开对方的储物戒指,发现了一大笔钱!");//操作端显示
		outtextxy(262 + 250 - textwidth("战斗胜利!你打开对方的储物戒指,发现了一大笔钱!") / 2, 42 + 430, "战斗胜利!你打开对方的储物戒指,发现了一大笔钱!");

		fputs(Description2, Diary);
		fclose(Diary);
		return;
	}
	if (j == 0)//失败
	{
		Player->Coin = Player->Coin * 0.7;
		//printf("战斗失败!所幸你曾经学过三千雷动,得以逃离,然而却在战斗中损失了自己的储物戒指...");//操作端显示
		outtextxy(262 + 250 - textwidth("战斗失败!所幸你曾经学过三千雷动,") / 2, 42 + 390, "战斗失败!所幸你曾经学过三千雷动,");
		outtextxy(262 + 250 - textwidth("得以逃离,然而却在战斗中损失了自己的储物戒指...") / 2, 42 + 430, "得以逃离,然而却在战斗中损失了自己的储物戒指...");
		fputs(Description3, Diary);
		fclose(Diary);
		return;
	}
}
//--------------------------------------------------//--------------------------------------------------//
//四.中陷阱 扣钱续命 H B
void AdventureCase_4(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "你进入了欣绮山脉,忽然发现远处有一五彩斑斓之物,周围似有五行之物环绕,好奇心驱使下前往一探究竟,却发现是邪修布下的陷阱!此阵法只能通过给予灵石破解,不得已下你留下了一个储物袋.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("你进入了欣绮山脉,忽然发现远处有一五彩斑斓之物,周围似有五行之物环绕,好奇心驱使下前往一探究竟,却发现是邪修布下的陷阱!此阵法只能通过给予灵石破解,不得已下你留下了一个储物袋.");
	outtextxy(262 + 250 - textwidth("你进入了欣绮山脉,忽然发现远处有一五彩斑斓之物,周围似有五行之物环绕,") / 2, 42 + 100, "你进入了欣绮山脉,忽然发现远处有一五彩斑斓之物,周围似有五行之物环绕,");
	outtextxy(262 + 250 - textwidth("好奇心驱使下前往一探究竟,却发现是邪修布下的陷阱!") / 2, 42 + 140, "好奇心驱使下前往一探究竟,却发现是邪修布下的陷阱!");
	outtextxy(262 + 250 - textwidth("此阵法只能通过给予灵石破解,不得已下你留下了一个储物袋.") / 2, 42 + 180, "此阵法只能通过给予灵石破解,不得已下你留下了一个储物袋.");
	//↑操作端显示
	Player->Coin = Player->Coin * 0.7;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//五.误入毒瘴 扣属性 H B
void AdventureCase_5(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "你在山林中被万年妖兽追逐,一番斗法后误入了毒瘴,你急忙调用本命精元护体,虽然苟且得以存活,却功力大退.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("你在山林中被万年妖兽追逐,一番斗法后误入了毒瘴,你急忙调用本命精元护体,虽然苟且得以存活,却功力大退.");
	outtextxy(262 + 250 - textwidth("你在山林中被万年妖兽追逐,一番斗法后误入了毒瘴,") / 2, 42 + 100, "你在山林中被万年妖兽追逐,一番斗法后误入了毒瘴,");
	outtextxy(262 + 250 - textwidth("你急忙调用本命精元护体,虽然苟且得以存活,却功力大退.") / 2, 42 + 140, "你急忙调用本命精元护体,虽然苟且得以存活,却功力大退.");
	Player->ATK = Player->ATK * 0.93;
	Player->DF = Player->DF * 0.93;
	Player->HP = Player->HP * 0.93;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//六.上古宗门传承 突破概率增长 Mid G
void AdventureCase_6(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "你最近感觉心神不宁,恐怕有损道心.于是决定云游四方,在一片落日断垣之下,你偶然间触发了禁制,竟无意间得到了云蕴传承!\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("你最近感觉心神不宁,恐怕扰乱道心.于是决定云游四方,在一片落日断垣之下,你偶然间触发了禁制,竟无意间得到了云蕴传承!一番指点后,你忽然觉得瓶颈松动了,突破概率上升!.");
	outtextxy(262 + 250 - textwidth("你最近感觉心神不宁,恐怕扰乱道心.于是决定云游四方,") / 2, 42 + 100, "你最近感觉心神不宁,恐怕扰乱道心.于是决定云游四方,");
	outtextxy(262 + 250 - textwidth("在一片落日断垣之下,你偶然间触发了禁制,竟无意间得到了云蕴传承!") / 2, 42 + 140, "在一片落日断垣之下,你偶然间触发了禁制,竟无意间得到了云蕴传承!");
	outtextxy(262 + 250 - textwidth("一番指点后,你忽然觉得瓶颈松动了,突破概率上升!") / 2, 42 + 180, "一番指点后,你忽然觉得瓶颈松动了,突破概率上升!");
	Player->rate += 5;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//七.误入合欢宗 被囚禁后修为增长但气血下降  Min B
void AdventureCase_7(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "你随你刚结识的道友出游,他带你前往他的宗门.在你踏入山门一瞬间,护山大阵开启,那道友卸下易容,竟是一合欢邪修,你被囚禁数月后趁机逃出,虽略损气血,却发现修为精进.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("你随你刚结识的道友出游,他带你前往他的宗门.在你踏入山门一瞬间,护山大阵开启,那道友卸下易容,竟是一合欢邪修,你被囚禁数月后趁机逃出,虽略损气血,却发现修为精进.");
	outtextxy(262 + 250 - textwidth("你随你刚结识的道友出游,他带你前往他的宗门.") / 2, 42 + 100, "你随你刚结识的道友出游,他带你前往他的宗门.");
	outtextxy(262 + 250 - textwidth("在你踏入山门一瞬间,护山大阵开启,那道友卸下易容,竟是一合欢邪修,") / 2, 42 + 140, "在你踏入山门一瞬间,护山大阵开启,那道友卸下易容,竟是一合欢邪修,");
	outtextxy(262 + 250 - textwidth("你被囚禁数月后趁机逃出,虽略损气血,却发现修为精进.") / 2, 42 + 180, "你被囚禁数月后趁机逃出,虽略损气血,却发现修为精进.");

	Player->CurExp = Player->CurExp * 1.2;
	Player->HP = Player->HP * 0.95;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//八.天下武斗会 识得玄武门龟男学相册 交流修仙经验 M G
void AdventureCase_8(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "修仙界在天枢域举办百年一届的斗法会,你前去参加,遇见幼时的好友薛象策,他现在已经是玄武派龟男之首,你们相谈甚欢,交流斗法经验.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("修仙界在天枢域举办百年一届的斗法会,你前去参加,遇见幼时的好友薛象策,他现在已经是玄武派龟男之首,你们相谈甚欢,交流斗法经验.");
	outtextxy(262 + 250 - textwidth("修仙界在天枢域举办百年一届的斗法会,") / 2, 42 + 100, "修仙界在天枢域举办百年一届的斗法会,");
	outtextxy(262 + 250 - textwidth("你前去参加,遇见幼时的好友薛象策,他现在已经是玄武派龟男之首,") / 2, 42 + 140, "你前去参加,遇见幼时的好友薛象策,他现在已经是玄武派龟男之首,");
	outtextxy(262 + 250 - textwidth("你们相谈甚欢,交流斗法经验.") / 2, 42 + 180, "你们相谈甚欢,交流斗法经验.");

	Player->CurExp = Player->CurExp * 1.1;
	Player->DF = Player->DF * 1.05;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//九.东海秘境 获得千年蛟珠所化上品灵石 H G
void AdventureCase_9(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "东海中阵阵轰鸣,传闻是第三神龙应龙府现世,你去求一番机缘,发现千年神蛟所化绝品灵石!\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("东海中阵阵轰鸣,传闻是第三神龙应龙府现世,你去求一番机缘,发现千年神蛟所化绝品灵石!");
	outtextxy(262 + 250 - textwidth("东海中阵阵轰鸣,传闻是第三神龙应龙府现世,") / 2, 42 + 100, "东海中阵阵轰鸣,传闻是第三神龙应龙府现世,");
	outtextxy(262 + 250 - textwidth("你去求一番机缘,发现千年神蛟所化绝品灵石!") / 2, 42 + 140, "你去求一番机缘,发现千年神蛟所化绝品灵石!");

	Player->Coin = Player->Coin * 1.25 + 400;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//十. 修仙悬赏 为民除害 H G
void AdventureCase_10(struct Player_* Player) {
	//文本处理
	FILE* Diary = NULL;
	char Description[1000] = "五迢唔被封印,出现了许多肆无忌惮的邪修,你接受任务,立于万万百姓前,横刀向渊,血染天穹.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//游戏内容
	//printf("五迢唔被封印,出现了许多肆无忌惮为非作歹的邪修,你接受任务,立于万万百姓前,横刀向渊,血染天穹.");
	outtextxy(262 + 250 - textwidth("五迢唔被封印,出现了许多肆无忌惮为非作歹的邪修,") / 2, 42 + 100, "五迢唔被封印,出现了许多肆无忌惮为非作歹的邪修,");
	outtextxy(262 + 250 - textwidth("你接受任务,立于万万百姓前,横刀向渊,血染天穹.") / 2, 42 + 140, "你接受任务,立于万万百姓前,横刀向渊,血染天穹.");

	Player->CurExp = Player->CurExp * 1.4;
	Player->Coin = Player->Coin * 1.1 + 100;
	return;
}

//--------------------------------------------------//--------------------------------------------------//
//当按下历练按钮时,只需要调用该函数即可
void AdventureMain(struct Player_* Player)
{
	int CaseNumber = RandomDigit(100, 1);
	if (CaseNumber >= 1 && CaseNumber <= 20) { CaseNumber = 1; }
	else if (CaseNumber >= 21 && CaseNumber <= 30) { CaseNumber = 2; }
	else if (CaseNumber >= 31 && CaseNumber <= 40) { CaseNumber = 3; }
	else if (CaseNumber >= 41 && CaseNumber <= 50) { CaseNumber = 4; }
	else if (CaseNumber >= 51 && CaseNumber <= 56) { CaseNumber = 5; }
	else if (CaseNumber >= 57 && CaseNumber <= 63) { CaseNumber = 6; }
	else if (CaseNumber >= 64 && CaseNumber <= 73) { CaseNumber = 7; }
	else if (CaseNumber >= 74 && CaseNumber <= 88) { CaseNumber = 8; }
	else if (CaseNumber >= 89 && CaseNumber <= 93) { CaseNumber = 9; }
	else if (CaseNumber >= 94 && CaseNumber <= 100) { CaseNumber = 10; }
	FF = CaseNumber;

	switch (CaseNumber) {
	case 1:AdventureCase_1(Player);//执行事件1函数体     
		break;//返回(这里可以休眠 让画面暂时停止一段时间?需要你设计一下)
	case 2:AdventureCase_2(Player);//执行事件2函数体        
		break;
	case 3:AdventureCase_3(Player);//执行事件3函数体        
		break;
	case 4:AdventureCase_4(Player);//执行事件4函数体        
		break;
	case 5:AdventureCase_5(Player);//执行事件5函数体        
		break;
	case 6:AdventureCase_6(Player);//执行事件6函数体        
		break;
	case 7:AdventureCase_7(Player);//执行事件7函数体        
		break;
	case 8:AdventureCase_8(Player);//执行事件8函数体        
		break;
	case 9:AdventureCase_9(Player);//执行事件9函数体        
		break;
	case 10:AdventureCase_10(Player);//执行事件10函数体        
		break;
	default:
		break;
	}
	return;
}