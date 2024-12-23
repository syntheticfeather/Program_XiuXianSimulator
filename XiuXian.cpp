#include<stdio.h>
#include<time.h>
#include<pthread.h>
#include<windows.h>
#include<stdlib.h>
#include"MainScreen.h"








//����
struct Weapon* CreateWeapon(struct Player_* Player_1)//��������
{
    struct Weapon* Weapon = (struct Weapon*)calloc(1, sizeof(struct Weapon));//����ռ�    
    if (Weapon == NULL)
    {
        return NULL;
    }
    float ATKRange = Player_1->ATK * 0.2;//�����������仯��Χ
    float ATK1 = Player_1->ATK / 10;//�������������
    Weapon->ATK = RandomDigit(ATKRange, ATK1);
    Weapon->Coin = RandomDigit(25 * Player_1->Lvl, 10 * Player_1->Lvl);
    if (Weapon->ATK <= 0)
    {
        Weapon->ATK = 1;
    }
    return Weapon;
}

//����
struct Armor* CreatArmor(struct Player_* Player_1)//���ɷ���
{
    struct Armor* Armor = (struct Armor*)calloc(1, sizeof(struct Armor));//�����ַ    
    if (Armor == NULL)
    {
        return NULL;
    }
    int DFRange = Player_1->DF * 0.2;
    int DF1 = Player_1->DF / 10;     
    int HPRange = Player_1->HP * 0.1;
    int HP1 = Player_1->HP / 10;
    Armor->DF = RandomDigit(DFRange, DF1);//�����
    Armor->HP = RandomDigit(HPRange, HP1);//�����
    Armor->Coin = RandomDigit(70 * Player_1->Lvl, 40 * Player_1->Lvl);
    if (Armor->DF <= 0)
    {
        Armor->DF = 1;
    }
    if (Armor->HP <= 0)
    {
        Armor->HP = 1;
    }
    return Armor;
}

//��Ʒ
struct Decoration* CreateDecoration(struct Player_* Player_1)
{
    struct Decoration* Decoration = (struct Decoration*)calloc(1, sizeof(struct Decoration));    
    if (Decoration == NULL)
    {
        return NULL;
    }
    int HPRange = Player_1->HP * 0.1;
    int HP1 = Player_1->HP / 10;
    int ATKRange = Player_1->ATK * 0.1;
    int ATK1 = Player_1->ATK / 10;    
    int DFRange = Player_1->DF * 0.1;
    int DF1 = Player_1->DF / 10;    
    Decoration->HP = RandomDigit(HPRange, HP1);
    Decoration->ATK = RandomDigit(ATKRange, ATK1);
    Decoration->DF = RandomDigit(DFRange, DF1);
    Decoration->Coin = RandomDigit(100 * Player_1->Lvl, 100 * Player_1->Lvl);
    if (Decoration->ATK <= 0)
    {
        Decoration->ATK = 1;
    }
    if (Decoration->DF <= 0)
    {
        Decoration->DF = 1;
    }
    if (Decoration->HP <= 0)
    {
        Decoration->HP = 1;
    }
    return Decoration;
}

//��ҩ�ṹ������
struct ELIXIR* CreateElixir(struct Player_* Player_1)
{
    struct ELIXIR* ELIXIR = (struct ELIXIR*)calloc(1, sizeof(struct ELIXIR));
    if (ELIXIR == NULL)
    {
        return NULL;
    }
    ELIXIR->rate = RandomDigit(3, 1);
    ELIXIR->Coin = RandomDigit(100 * Player_1->Lvl, 100 * Player_1->Lvl);
    return ELIXIR;
}//���ɵ�ҩ






//int main()//��Ҫ�Ž��������Ĳ���
//{
//
//    pthread_t th1;
//    pthread_t th2;
//    pthread_create(&th1, NULL, (void*)Ager1, NULL);
//    pthread_create(&th2, NULL, (void*)Ager2, NULL);
//    return 0;
//}

const int Const = 0;//���������ھ�������


//ʹ�õ�ҩʱ���õĺ���
int UseELIXIR(struct Node* current, struct Player_* Player_1)//ʹ�õ�ҩ��������
{
    Player_1->rate += current->item.elixir.rate;
    return 0;
}

void* AddExp(void* args, struct Player_* Player_1)//��������
{
    while (Const == 0)
    {
        Sleep(500);
        Player_1->CurExp = Player_1->CurExp + Player_1->ExpSpeed;//ÿ0.5��CurExp����x�㣨x����ExpSpeed�仯��
    }
}

void* AddAge(void* args, struct Player_* Player_1)//��������
{
    while (Const == 0)
    {
        Sleep(10000);
        Player_1->Age = Player_1->Age + 1;
    }
}

//��װ������װ�����ֱ��ڵ�����������͵��ж�°�����ʱ��ʹ��
int Wearing(struct Node* current, struct Player_* Player_1)//��װ��
{

    switch (current->Type)//switch����жϣ�Node*current�Ǳ��������ص���Ʒ����ʱ��ָ��
    {
    case TYPE_WEAPON:
        if (Player_1->WearingWeapon == NULL)
        {
            Player_1->WearingWeapon = &current->item.weapon;
            Player_1->ATK = Player_1->WearingWeapon->ATK + Player_1->ATK;//ʹ������������            
        }
        else
        {
            printf("����װ��");//////
        }
        break;
    case TYPE_ARMOR:
        if (Player_1->WearingArmor == NULL)
        {
            Player_1->WearingArmor = &current->item.armor;
            Player_1->DF = Player_1->WearingArmor->DF + Player_1->DF;
            Player_1->HP = Player_1->HP + Player_1->WearingArmor->HP;//ʹ������������           
        }
        else
        {
            printf("����װ��");//////
        }
        break;
    case TYPE_DECORATION:
        if (Player_1->WearingDecoration == NULL)
        {
            Player_1->WearingDecoration = &current->item.decoration;
            Player_1->ATK = Player_1->WearingDecoration->ATK + Player_1->ATK;
            Player_1->DF = Player_1->WearingDecoration->DF + Player_1->DF;
            Player_1->HP = Player_1->WearingDecoration->HP + Player_1->HP;//ʹ������������            
        }
        else
        {
            printf("����װ��");//////
        }
        break;
    default:
        break;
    }
    return 0;
}



int UnLoad(struct Player_* Player_1,int Type)//��װ��
{

    switch (Type)
    {
    case TYPE_WEAPON:
        if (Player_1->WearingWeapon != NULL)
        {
            Player_1->ATK = Player_1->ATK - Player_1->WearingWeapon->ATK;//����װ���Խ�ɫ�����Լӳɣ���������ͨ����ֵ��װ���ٴβ��뱳��            
        }
        else
        {
            printf("��װ��");
        }
        break;
    case TYPE_ARMOR:
        if (Player_1->WearingArmor != NULL)
        {
            Player_1->DF = Player_1->DF - Player_1->WearingArmor->DF;
            Player_1->HP = Player_1->HP - Player_1->WearingArmor->HP;//����װ���Խ�ɫ�����Լӳɣ���������ͨ����ֵ��װ���ٴβ��뱳��            
        }
        else
        {
            printf("����װ��");
        }
        break;
    case TYPE_DECORATION:
        if (Player_1->WearingDecoration != NULL)
        {
            Player_1->ATK = Player_1->ATK - Player_1->WearingDecoration->ATK;
            Player_1->DF = Player_1->DF - Player_1->WearingDecoration->DF;
            Player_1->HP = Player_1->HP - Player_1->WearingDecoration->HP;//����װ���Խ�ɫ�����Լӳɣ���������ͨ����ֵ��װ���ٴβ��뱳��            
        }
        else
        {
            printf("����װ��");
        }
        break;
    default:
        break;
    }

    return 0;
}
















































struct MyStruct {
    int a;
    int b;
    int c;
};
void Test(struct MyStruct* ptr1) {
    ptr1->a = 1;
    ptr1->b = 1;
    ptr1->c = 1;
}

//������ʼʱ�����������
void Prepare()
{
    struct MyStruct myStructInstance;  // �����ṹ��ʵ��  
    struct MyStruct* ptr1 = &myStructInstance;  // ����ָ��myStructInstance��ָ��     
    Test(ptr1);
}