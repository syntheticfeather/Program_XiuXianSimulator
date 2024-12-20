#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>
#include<easyx.h>
#include"Adven.h"
#include"MainScreen.h"




//--------------------------------------------------//--------------------------------------------------//
//struct Player_
//{
//    bool IsBeginner = false;
//    float HP = 1.0;
//    float ATK = 1.0;
//    float DF = 1.0;
//    int Recovery = 1;//�ָ�����(ս����Ѫ)
//    int rate = 80;
//    int Lvl = 0;
//    int CurExp = 8;
//    int MaxExp = 10;
//    int Age = 1000;
//    int Coin = 4;
//    char Name[10] = "";
//    struct Weapon* WearingWeapon;//������
//    struct Armor* WearingArmor;//���߲�
//    struct Decoration* WearingDecoration;//��Ʒ��
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
//�˺���ʽ:����˺�=�����ߵĹ�����(1-����/100000+����)
//������=����/100000+����

//--------------------------------------------------//--------------------------------------------------//


int RandomDigit(int Range, int Start) {
	time_t NowTime;
	NowTime = time(NULL);//��ȡ��ǰʱ��
	srand((unsigned)NowTime);
	return((rand() % Range) + Start);
}

//�������������һ����ΧΪRange,��Start��ʼ�������
//--------------------------------------------------//--------------------------------------------------//

int FightModel(struct Player_* Player, struct Player_* Enemy)//ע��˴�������ǽṹָ��!
{
	int flag = 1;//��ʶ�Ƿ���ս��״̬
	int Attacker = 0;//������ʶ��������˭,'0'��Player,'1'��Enemy
	int Winner = 0;//Ĭ�����0ʤ��,������ʤ��,����Ϊ1
	int EnemyHp = Enemy->HP;
	int PlayerHp = Player->HP;

	while (flag) {
		switch (Attacker) {
		case 0:EnemyHp -= (Player->ATK) * (1 - (Enemy->DF) / (100000 + (Enemy->DF)));
			//printf("�����ܵ��˹���!���ι������%d���˺�,���˻�ʣѪ��%.2f!\n", (Player->ATK) * (1 - (Enemy->DF) / (100000 + (Enemy->DF))), EnemyHp);
			//outtextxy(262, 42 + 100, ("�����ܵ��˹���!���ι������%d���˺�,���˻�ʣѪ��%.2f!\n", (Player->ATK) * (1 - (Enemy->DF) / (100000 + (Enemy->DF))), EnemyHp));
			//sprintf(DFText, "%d", (int)DF);
			int te;
			te = (Player->ATK) * (1 - (2, Enemy->DF) / (100000 + (Enemy->DF)));
			char text1[100], text2[100];
			sprintf(text1, "%d", (int)((Player->ATK) * (1 - (2, Enemy->DF) / (100000 + (Enemy->DF)))));
			sprintf(text2, "%d", (int)EnemyHp);
			outtextxy(262, 42 + 100, "�����ܵ��˹���!���ι������");
			outtextxy(262 + textwidth("�����ܵ��˹���!���ι������"), 42 + 100, text1);
			outtextxy(262 + textwidth("�����ܵ��˹���!���ι������"), 42 + 100, "        ���˺�,");
			outtextxy(262, 42 + 130, "���˻�ʣѪ��");
			outtextxy(262 + textwidth("���˻�ʣѪ��"), 42 + 130, text2);
			//262,42
			//�˴�ע����Ҫ����Ϊ��������ʾ!!!!!

			Attacker = 1;//ת��������
			if (EnemyHp <= 0) { flag = 0; Winner = 0; }//�ж��Ƿ����� ����ʱѭ������
			break;//�����Ƿ����� ����switch

		case 1:PlayerHp -= (Enemy->ATK) * (1 - (Player->DF) / (100000 + (Player->DF)));
			//printf("���ܵ��˹���!���ι������%d���˺�,����ʣѪ��%.2f!\n", (Enemy->ATK) * (1 - (Player->DF) / (100000 + (Player->DF))), PlayerHp);
			outtextxy(262, 42 + 150, "���ܵ��˹���!���ι������%d���˺�,����ʣѪ��%.2f!\n");
			//�˴�ע����Ҫ����Ϊ��������ʾ!!!!!
			char text3[100], text4[100];
			sprintf(text3, "%d", (int)((Enemy->ATK) * (1 - (Player->DF) / (100000 + (Player->DF)))));
			sprintf(text4, "%d", (int)PlayerHp);
			outtextxy(262, 42 + 100, "���ܵ��˹���!���ι������");
			outtextxy(262 + textwidth("���ܵ��˹���!���ι������"), 42 + 100, text3);
			outtextxy(262 + textwidth("���ܵ��˹���!���ι������"), 42 + 100, "        ���˺�,");
			outtextxy(262, 42 + 130, "����ʣѪ��");
			outtextxy(262 + textwidth("����ʣѪ��"), 42 + 130, text4);
			Attacker = 0;//ת��������
			if (PlayerHp <= 0) { flag = 0; Winner = 1; }//�ж��Ƿ����� ����ʱѭ������
			break;//�����Ƿ����� ����switch
		}
		EndBatchDraw();
		Sleep(1000);
	}
	if (Winner == 0)
		return 1;
	else if (Winner == 1)
		return 0;
	else return 4;
}

//������������ʱͨ��������Һ͵��˵���ֵ,���лغ���ս��,�������ڲ����ο��ӻ�ս��
//�����ʽ ���,����  �����ʽ  ���ʤ�� 1,���ʧ��0  �������д��� 4


//--------------------------------------------------//--------------------------------------------------//

int Calculator(int Level, int CheckAspect)//CheckAspect���� 1/2/3 stand for HP/Attack/Defence
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
		result = 1;
		while (CalculateTimes - 1) {
			result = (int)((double)(result + 2)) * 1.2;
			CalculateTimes -= 1;
		}
		return result;
	}
}
//�������Ĺ�����ͨ��������Ҫ����ĵȼ��Լ���ά����,�����Ӧ�ȼ��Ļ�������

//--------------------------------------------------//--------------------------------------------------//
struct Player_* EnemyCreator(struct Player_* Player) {
	struct Player_* Enemy = (struct Player_*)calloc(1, sizeof(struct Player_));
	int Level = RandomDigit(3, ((Player->Lvl) - 1));//������ɵ��˵ĵȼ�
	if (Level == 0) {
		Level += 1;
	}
	Enemy->HP = RandomDigit(Calculator(Level, 1) * 0.4, Calculator(Level, 1) * 0.8);
	Enemy->ATK = RandomDigit(Calculator(Level, 2) * 0.4, Calculator(Level, 2) * 0.8);
	Enemy->DF = RandomDigit(Calculator(Level, 3) * 0.4, Calculator(Level, 3) * 0.8);//���˵������ڶ�Ӧ�ȼ��������Ե�0.8~1.2������
	return Enemy;
}//����Player������,����Player�ĵȼ�������ɵ���
//--------------------------------------------------//--------------------------------------------------//

//�¼�Դ��//
//һ.���·��� ֱ���˳��¼�
//��.�ٵô��� ��Ϊ����
//��.ż������1 ս��ģ�� ʤ����ʧ��
//��.�������� -Ǯ ��װ�� 
//��.�������� ��ø߽�װ��
//��.������ ��Ǯ����
//��.���붾�� ������
//��.�Ϲ����� ͻ�Ƹ�������
//ʮ.�õ�����ָ�� ֱ�ӽ���
//ʮһ.�ϻ����߽��߳�



void AdventureCase_1(struct Player_* Player) {
	//�ı�����
	FILE* Diary = NULL;
	char Description[1000] = "������������,���·���.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//��Ϸ����
	//printf("�����ת��һȦ,��������̫ƽ,���·���.\n");     //��Ϊ��������ʾ!
	outtextxy(262, 42 + 200, ("�����ת��һȦ,��������̫ƽ,���·���.\n"));
	return;
}

//--------------------------------------------------//--------------------------------------------------//

//��.�ٵô��� ��Ϊ����
void AdventureCase_2(struct Player_* Player) {
	//�ı�����
	FILE* Diary = NULL;
	char Description[1000] = "���ٵ����׵۵Ĵ���!��Ϊ����!.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	fclose(Diary);
	//��Ϸ����
	//printf("���Ǻ�������֮ʱ,��Ϊȡů����ص�,ȴ���ֻ�ɽ��ĵػ�,����һ��,�����׵����׵Ĵ���!��Ϊ����ʮ��֮��,��������.");//��������ʾ
	outtextxy(262, 42 + 200, ("���Ǻ�������֮ʱ,��Ϊȡů����ص�,ȴ���ֻ�ɽ��ĵػ�,"));
	outtextxy(262, 42 + 240, ("����һ��,�����׵����׵Ĵ���!��Ϊ����ʮ��֮��,��������."));
	Player->CurExp += Player->CurExp * 0.4;
	Player->ATK += Player->ATK * 0.1;
	return;
}

//--------------------------------------------------//--------------------------------------------------//

//��.ż������1 ս��ģ�� ʤ����ʧ��
void AdventureCase_3(struct Player_* Player) {
	//�ı�����
	FILE* Diary = NULL;
	char Description[1000] = "��ż���˵���!����ս��!.\n";
	char Description2[1000] = "����һ����ս,��ȡ����ʤ��,���һ����һ���Ǯ.\n";
	char Description3[1000] = "����һ����ս,��ʧ�ܶ���,������ʧ��һ���Ǯ.\n";
	Diary = fopen("XiuXianDiary.txt", "a");
	fputs(Description, Diary);
	//��Ϸ����
	//printf("������׼��ǰ��ɽ���µķ��и����˼��̻�,ͻȻһ������Ϯ��,�����ư�㿪��,��������������ĳ��!");//��������ʾ
	outtextxy(262, 42 + 200, ("������׼��ǰ��ɽ���µķ��и����˼��̻�,"));
	outtextxy(262, 42 + 240, ("ͻȻһ������Ϯ��,�����ư�㿪��,��������������ĳ��!"));
	if (FightModel(Player, EnemyCreator(Player)) == 1)//ʤ��
	{
		Player->Coin += Player->Coin;
		//printf("ս��ʤ��!��򿪶Է��Ĵ����ָ,������һ���Ǯ!");//��������ʾ
		outtextxy(262, 42 + 280, ("ս��ʤ��!��򿪶Է��Ĵ����ָ,������һ���Ǯ!"));

		fputs(Description2, Diary);
		fclose(Diary);
		return;
	}
	if (FightModel(Player, EnemyCreator(Player)) == 0)//ʧ��
	{
		Player->Coin = Player->Coin * 0.5;
		//printf("ս��ʧ��!����������ѧ����ǧ�׶�,��������,Ȼ��ȴ��ս������ʧ���Լ��Ĵ����ָ...");//��������ʾ
		outtextxy(262, 42 + 280, ("ս��ʧ��!����������ѧ����ǧ�׶�,"));
		outtextxy(262, 42 + 320, ("��������,Ȼ��ȴ��ս������ʧ���Լ��Ĵ����ָ..."));
		fputs(Description3, Diary);
		fclose(Diary);
		return;
	}
}

//--------------------------------------------------//--------------------------------------------------//
//������������ťʱ,ֻ��Ҫ���øú�������
void AdventureMain(struct Player_* Player)
{
	int CaseNumber = RandomDigit(3, 1);
	switch (CaseNumber) {
	case 1:AdventureCase_1(Player);//ִ���¼�1������     
		break;//����(����������� �û�����ʱֹͣһ��ʱ��?��Ҫ�����һ��)
	case 2:AdventureCase_2(Player);//ִ���¼�2������        
		break;
	case 3:AdventureCase_3(Player);//ִ���¼�3������        
		break;
	default:
		break;
	}
	return;
}