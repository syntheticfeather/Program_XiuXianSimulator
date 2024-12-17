#include<stdio.h>
#include<stdlib.h>
#include<time.h>



//--------------------------------------------------//
struct SanWei {
    int HP;
    int Attack;
    int Defence;
    int Level;
    int Money;
};
//伤害公式:造成伤害=攻击者的攻击×(1-护甲/100+护甲)
//免伤率=护甲/100+护甲

//--------------------------------------------------//


int RandomDigit(){
    time_t NowTime;
    NowTime = time(NULL);//获取当前时间
    srand((unsigned)nowtime);
    return(rand()%10+1);
    }//随机数函数产生一个1-10的随机数


//--------------------------------------------------//


int TimeCounter(int CountdownTime){
    time_t time0,time2;
    time0 = time(Null);
    while(){
        time2 = time(Null);
        if(difftime(time0,time2)>CountdownTime) break;
    }
    return 1;
}//函数的效果是根据给定的冷却时间,强制循环直到冷却时间后返回整型'1',表示冷却完毕 其实就是硬控主程序CountdownTime秒


//--------------------------------------------------//

char* FightModel(struct SanWei *Player,struct SanWei *Enemy)//注意此处传入的是结构指针!
{
    int CountdownTimer = 1;//攻击冷却
    int flag=1;//标识是否处于战斗状态
    int Attacker=0;//用来标识攻击者是谁,'0'即Player,'1'即Enemy
    int EnemyHp=Enemy->HP;
    int PlayerHp=Player->HP;
    while(flag){
        switch(Attacker){
            case 0:EnemyHp-=(Player->Attack)*(1-(Enemy->Defence)/(100+(Enemy->Defence)));
                    Attacker=1;//转换攻击者
                    if(EnemyHp<0) flag=0;//判断是否死亡 死亡时循环结束
                    break;//无论是否死亡 跳出switch
                    
            case 1:PlayerHp-=(Enemy->Attack)*(1-(Player->Defence)/(100+(Player->Defence)));
                    Attacker=0;//转换攻击者
                    if(PlayerHp<0) flag=0;//判断是否死亡 死亡时循环结束
                    break;//无论是否死亡 跳出switch
        }
        
    }
    
    
}





// int main(){
//     printf("%d",randomdigit());
// }
