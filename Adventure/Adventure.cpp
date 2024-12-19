#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>


//--------------------------------------------------//--------------------------------------------------//
struct Player {
    int HP;//血量
    int Attack;//攻击
    int Defence;//防御
    int Time;//寿命
    int Recovery;//恢复能力(战斗回血)
    int Level;//等级(境界)
    int Money;//钱
    int ExpSpeed;//加经验的速度
    int Exp;//经验
    int Breakthrough_probability;//突破概率
    struct Weapon* WearingWeapon;//武器槽
    struct Armor* WearingArmor;//防具槽
    struct Decoration* WearingDecoration;//饰品槽
};
struct Weapon {
    int Attack;
    int Money;
};
struct Armor{
    int HP;
    int Defence;
    int Money;
};
struct Decoration{
    int Attack;
    int HP;
    int Defence;
    int Money;
    int Recovery;
};
//伤害公式:造成伤害=攻击者的攻击×(1-护甲/100000+护甲)
//免伤率=护甲/100000+护甲

//--------------------------------------------------//--------------------------------------------------//


int RandomDigit(int Range,int Start){
    time_t NowTime;
    NowTime = time(NULL);//获取当前时间
    srand((unsigned)NowTime);
    return((rand()%Range)+Start);
    }
    
//随机数函数产生一个范围为Range,从Start开始的随机数
//--------------------------------------------------//--------------------------------------------------//

int FightModel(struct Player *Player,struct Player *Enemy)//注意此处传入的是结构指针!
{
    int flag=1;//标识是否处于战斗状态
    int Attacker=0;//用来标识攻击者是谁,'0'即Player,'1'即Enemy
    int Winner=0;//默认玩家0胜利,若敌人胜利,则标记为1
    int EnemyHp=Enemy->HP;
    int PlayerHp=Player->HP;
    
    while(flag){
        switch(Attacker){
            case 0:EnemyHp-=(Player->Attack)*(1-(Enemy->Defence)/(100000+(Enemy->Defence)));
                    printf("敌人受到了攻击!本次攻击造成%d点伤害,敌人还剩血量%d!\n",(Player->Attack)*(1-(Enemy->Defence)/(100000+(Enemy->Defence))),EnemyHp);
                    
                    //此处注意需要更改为操作端显示!!!!!
                    
                    Attacker=1;//转换攻击者
                    if(EnemyHp<=0){flag=0;Winner=0;}//判断是否死亡 死亡时循环结束
                    break;//无论是否死亡 跳出switch
                    
            case 1:PlayerHp-=(Enemy->Attack)*(1-(Player->Defence)/(100000+(Player->Defence)));
                    printf("您受到了攻击!本次攻击造成%d点伤害,您还剩血量%d!\n",(Enemy->Attack)*(1-(Player->Defence)/(100000+(Player->Defence))),PlayerHp);
                    
                    //此处注意需要更改为操作端显示!!!!!
                    
                    Attacker=0;//转换攻击者
                    if(PlayerHp<=0){flag=0;Winner=1;}//判断是否死亡 死亡时循环结束
                    break;//无论是否死亡 跳出switch
        }
    Sleep(1000);
    }
    if(Winner==0)
    return 1;
    else if(Winner==1)
    return 0;
    else return 4;
}

//本函数的作用时通过输入玩家和敌人的数值,进行回合制战斗,过程中在操作段可视化战斗
//传入格式 玩家,敌人  输出形式  玩家胜利 1,玩家失败0  程序运行错误 4


//--------------------------------------------------//--------------------------------------------------//

int Calculator(int Level,int CheckAspect)//CheckAspect参数 1/2/3 stand for HP/Attack/Defence
{   int Aspect=CheckAspect;
    int CalculateTimes = Level;
    int result;

    if(Aspect==1){
        result= 10;
        while(CalculateTimes-1){
            result = (int)((double)(result+2))*1.2;
            CalculateTimes-=1;}
        return result;
    }

    if(Aspect==2){
        result= 5;
        while(CalculateTimes-1){
            result = (int)((double)(result+2))*1.2;
            CalculateTimes-=1;}
        return result;
    }

    if(Aspect==3){
        result= 1;
        while(CalculateTimes-1){
            result = (int)((double)(result+2))*1.2;
            CalculateTimes-=1;}
        return result;
    }
}
//本函数的功能是通过传入需要计算的等级以及三维方面,计算对应等级的基础属性

//--------------------------------------------------//--------------------------------------------------//
struct Player* EnemyCreator(struct Player* Player){
    struct Player* Enemy=(struct Player*)calloc(1,sizeof(struct Player));
    int Level =RandomDigit(3,((Player->Level)-1));//随机生成敌人的等级
    if(Level == 0){
        Level+=1;
    }
    Enemy->HP=RandomDigit(Calculator(Level,1)*0.4,Calculator(Level,1)*0.8);
    Enemy->Attack=RandomDigit(Calculator(Level,2)*0.4,Calculator(Level,2)*0.8);
    Enemy->Defence=RandomDigit(Calculator(Level,3)*0.4,Calculator(Level,3)*0.8);//敌人的属性在对应等级基础属性的0.8~1.2倍浮动
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



//--------------------------------------------------//--------------------------------------------------//
//一.无事发生 直接退出事件
void AdventureCase_1(struct Player* Player){
    //文本处理
    FILE* Diary = NULL;
    char Description[1000]="您进行了历练,无事发生.\n";
    Diary = fopen("XiuXianDiary.txt","a");
    fputs(Description,Diary);
    fclose(Diary);
    //游戏内容
    printf("你出门转了一圈,发现天下太平,无事发生.\n");     //改为操作端显示!
    return;
}
//--------------------------------------------------//--------------------------------------------------//
//二.觅得传承 修为大增
void AdventureCase_2(struct Player* Player){
    //文本处理
    FILE* Diary = NULL;
    char Description[1000]="您觅得了炎帝的传承!修为增加!.\n";
    Diary = fopen("XiuXianDiary.txt","a");
    fputs(Description,Diary);
    fclose(Diary);
    //游戏内容
    printf("正是寒风凛冽之时,你为取暖误入地底,却发现火山深处的地火,定睛一看,竟是炎帝萧炎的传承!修为增加十分之四,攻击提升.");//操作端显示
    Player->Exp+=Player->Exp*0.4;
    Player->Attack+=Player->Attack*0.1;
    return;
}
//--------------------------------------------------//--------------------------------------------------//
//三.偶遇敌人1 战斗模块 胜利或失败
void AdventureCase_3(struct Player* Player){
    //文本处理
    FILE* Diary = NULL;
    char Description[1000]="你偶遇了敌人!进入战斗!.\n";
    char Description2[1000] = "经过一番苦战,你取得了胜利,并且获得了一大笔钱.\n";
    char Description3[1000] = "经过一番苦战,你失败遁走,并且损失了一大笔钱.\n";
    Diary = fopen("XiuXianDiary.txt","a");
    fputs(Description,Diary);
    //游戏内容
    printf("你御剑准备前往山脚下的坊市感受人间烟火,突然一道法术袭来,你游云般躲开后,发现来人正是你的仇敌!");//操作端显示
    if(FightModel(Player,EnemyCreator(Player))==1)//胜利
    {
        Player->Money+=Player->Money;
        printf("战斗胜利!你打开对方的储物戒指,发现了一大笔钱!");//操作端显示
        fputs(Description2,Diary);
        fclose(Diary);
        return;
    }
    if(FightModel(Player,EnemyCreator(Player))==0)//失败
    {
        Player->Money= Player->Money*0.5;
        printf("战斗失败!所幸你曾经学过三千雷动,得以逃离,然而却在战斗中损失了自己的储物戒指...");//操作端显示
        fputs(Description3,Diary);
        fclose(Diary);
        return;
    }
}
//--------------------------------------------------//--------------------------------------------------//
//当按下历练按钮时,只需要调用该函数即可
void AdventureMain(struct Player* Player)
{
    int CaseNumber = RandomDigit(3,1);
    switch(CaseNumber){
        case 1:AdventureCase_1(Player);//执行事件1函数体
                break ;//返回(这里可以休眠 让画面暂时停止一段时间?需要你设计一下)
        case 2:AdventureCase_2(Player);//执行事件2函数体
                break ;
        case 3:AdventureCase_3(Player);//执行事件3函数体
                break ;
        default:break ;
    }
    return;
}
int main(){
    struct Player *Player1 = (struct Player*)calloc(1,sizeof(struct Player));
    Player1->Attack=10;
    Player1->HP=10;
    Player1->Defence=10;
    Player1->Level=1;
    int i = FightModel(Player1,Player1);
    AdventureCase_1(Player1);
    AdventureMain(Player1);
    return 0;
    }
