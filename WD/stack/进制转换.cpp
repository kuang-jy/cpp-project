#include <iostream>
using namespace std;
#define INF 1000000

typedef struct stack{
    int data[INF];
    int top;
}stack;

int main(){
    stack stk;
    stk.top = -1;
    int num,n;
    scanf("%d%d",&num,&n);  //输入10进制数，和目标进制
    while(num){
        stk.data[++stk.top] = num%n;
        num /= n;
    }
    for(int i = stk.top;i >= 0;i--) printf("%d",stk.data[i]);
    return 0;
}