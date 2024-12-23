#include<stdio.h>
#include<time.h>
#include<pthread.h>
#include<windows.h>
#include<stdlib.h>
#include"MainScreen.h"








//武器
struct Weapon* CreateWeapon(struct Player_* Player_1)//生成武器
{
    struct Weapon* Weapon = (struct Weapon*)calloc(1, sizeof(struct Weapon));//分配空间    
    if (Weapon == NULL)
    {
        return NULL;
    }
    float ATKRange = Player_1->ATK * 0.2;//武器攻击力变化范围
    float ATK1 = Player_1->ATK / 10;//武器攻击力起点
    Weapon->ATK = RandomDigit(ATKRange, ATK1);
    Weapon->Coin = RandomDigit(25 * Player_1->Lvl, 10 * Player_1->Lvl);
    if (Weapon->ATK <= 0)
    {
        Weapon->ATK = 1;
    }
    return Weapon;
}

//防具
struct Armor* CreatArmor(struct Player_* Player_1)//生成防具
{
    struct Armor* Armor = (struct Armor*)calloc(1, sizeof(struct Armor));//分配地址    
    if (Armor == NULL)
    {
        return NULL;
    }
    int DFRange = Player_1->DF * 0.2;
    int DF1 = Player_1->DF / 10;     
    int HPRange = Player_1->HP * 0.1;
    int HP1 = Player_1->HP / 10;
    Armor->DF = RandomDigit(DFRange, DF1);//随机数
    Armor->HP = RandomDigit(HPRange, HP1);//随机数
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

//饰品
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

//丹药结构体生成
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
}//生成丹药






//int main()//需要放进主函数的部分
//{
//
//    pthread_t th1;
//    pthread_t th2;
//    pthread_create(&th1, NULL, (void*)Ager1, NULL);
//    pthread_create(&th2, NULL, (void*)Ager2, NULL);
//    return 0;
//}

const int Const = 0;//常量，用于经验增长


//使用丹药时调用的函数
int UseELIXIR(struct Node* current, struct Player_* Player_1)//使用丹药增加属性
{
    Player_1->rate += current->item.elixir.rate;
    return 0;
}

void* AddExp(void* args, struct Player_* Player_1)//经验增长
{
    while (Const == 0)
    {
        Sleep(500);
        Player_1->CurExp = Player_1->CurExp + Player_1->ExpSpeed;//每0.5秒CurExp增长x点（x根据ExpSpeed变化）
    }
}

void* AddAge(void* args, struct Player_* Player_1)//年龄增长
{
    while (Const == 0)
    {
        Sleep(10000);
        Player_1->Age = Player_1->Age + 1;
    }
}

//穿装备和脱装备，分别在点击穿戴按键和点击卸下按键的时候使用
int Wearing(struct Node* current, struct Player_* Player_1)//穿装备
{

    switch (current->Type)//switch语句判断，Node*current是背包进行特点物品查找时的指针
    {
    case TYPE_WEAPON:
        if (Player_1->WearingWeapon == NULL)
        {
            Player_1->WearingWeapon = &current->item.weapon;
            Player_1->ATK = Player_1->WearingWeapon->ATK + Player_1->ATK;//使人物属性增加            
        }
        else
        {
            printf("已有装备");//////
        }
        break;
    case TYPE_ARMOR:
        if (Player_1->WearingArmor == NULL)
        {
            Player_1->WearingArmor = &current->item.armor;
            Player_1->DF = Player_1->WearingArmor->DF + Player_1->DF;
            Player_1->HP = Player_1->HP + Player_1->WearingArmor->HP;//使人物属性增加           
        }
        else
        {
            printf("已有装备");//////
        }
        break;
    case TYPE_DECORATION:
        if (Player_1->WearingDecoration == NULL)
        {
            Player_1->WearingDecoration = &current->item.decoration;
            Player_1->ATK = Player_1->WearingDecoration->ATK + Player_1->ATK;
            Player_1->DF = Player_1->WearingDecoration->DF + Player_1->DF;
            Player_1->HP = Player_1->WearingDecoration->HP + Player_1->HP;//使人物属性增加            
        }
        else
        {
            printf("已有装备");//////
        }
        break;
    default:
        break;
    }
    return 0;
}



int UnLoad(struct Player_* Player_1,int Type)//脱装备
{

    switch (Type)
    {
    case TYPE_WEAPON:
        if (Player_1->WearingWeapon != NULL)
        {
            Player_1->ATK = Player_1->ATK - Player_1->WearingWeapon->ATK;//消除装备对角色的属性加成，背包可以通过赋值将装备再次插入背包            
        }
        else
        {
            printf("无装备");
        }
        break;
    case TYPE_ARMOR:
        if (Player_1->WearingArmor != NULL)
        {
            Player_1->DF = Player_1->DF - Player_1->WearingArmor->DF;
            Player_1->HP = Player_1->HP - Player_1->WearingArmor->HP;//消除装备对角色的属性加成，背包可以通过赋值将装备再次插入背包            
        }
        else
        {
            printf("已有装备");
        }
        break;
    case TYPE_DECORATION:
        if (Player_1->WearingDecoration != NULL)
        {
            Player_1->ATK = Player_1->ATK - Player_1->WearingDecoration->ATK;
            Player_1->DF = Player_1->DF - Player_1->WearingDecoration->DF;
            Player_1->HP = Player_1->HP - Player_1->WearingDecoration->HP;//消除装备对角色的属性加成，背包可以通过赋值将装备再次插入背包            
        }
        else
        {
            printf("已有装备");
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

//主程序开始时调用这个函数
void Prepare()
{
    struct MyStruct myStructInstance;  // 创建结构体实例  
    struct MyStruct* ptr1 = &myStructInstance;  // 创建指向myStructInstance的指针     
    Test(ptr1);
}