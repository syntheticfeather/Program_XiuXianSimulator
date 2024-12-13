#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randomdigit(){
    time_t nowtime;
    nowtime = time(NULL);//获取当前时间
    srand((unsigned)nowtime);
    return(rand()%10+1);
    }//随机数函数产生一个1-10的随机数
//--------------------------------------------------//






int main(){
    printf("%d",randomdigit());
}
