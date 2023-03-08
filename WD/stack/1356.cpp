#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char ch;
int stk1[1000],top1 = -1,top2 = -1;
char stk2[1000];

int getPriority(char a){
    if(a == '+' || a == '-') return 0;
    if(a == '^') return 2;
    return 1;
}

int calc(int a,char op,int b){
    if(op == '+') return a+b;
    if(op == '-') return a-b;
    if(op == '*') return a*b;
    if(op == '/') return a/b;
    if(op == '^') return pow(a,b);    
}

int main(){
    scanf("%c",&ch);
    while(ch != '\0'){
        if(ch >= '0' && ch <= '9') stk1[++top1] = ch-'0';
        else if(ch == '(') stk2[++top2] = ch;
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            if(top2 == -1 || stk2[top2] == '(' || getPriority(stk2[top2]) < getPriority(ch)) stk2[++top2] = ch;
            else{
                while(top2 >= 0 && getPriority(stk2[top2]) >= getPriority(ch)){
                    int x = stk1[top1--],y = stk1[top1--];
                    int num = calc(y,stk2[top2--],x);
                    stk1[++top1] = num;
                }
                stk2[++top2] = ch;
            }
        }
        else if(ch == ')'){
            while(top2 >= 0 && stk2[top2] != '('){
                int x = stk1[top1--],y = stk1[top1--];
                int num = calc(y,stk2[top2--],x);
                stk1[++top1] = num;
            }
            top2--;
        }
        scanf("%c",&ch);
    }
    while(top2 >= 0){
        int x = stk1[top1--],y = stk1[top1--];
        int num = calc(y,stk2[top2--],x);
        stk1[++top1] = num;
    }
    printf("%d\n",stk1[0]);
    return 0;
}