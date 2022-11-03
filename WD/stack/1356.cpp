#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int stk1[10000],top1 = -1,top2 = -1;
char stk2[10000];
/*
1+(3+2)*(7^2+6*9)/(2)
*/

int prior[129];

void calc(){
    int a = stk1[top1--];
    int b = stk1[top1--];
    char ch = stk2[top2--];
    switch(ch){
        case '+': stk1[++top1] = a+b; break;
        case '-': stk1[++top1] = b-a; break;
        case '*': stk1[++top1] = a*b; break;
        case '/': stk1[++top1] = b/a; break;
        case '^': stk1[++top1] = (int)pow(b,a);
    }
}

int main(){
    prior['+'] = prior['-'] = 1;
    prior['*'] = prior['/'] = 2;
    prior['^'] = 3;
    prior['('] = 0;
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0;i < n;i++){
        char ch = s[i];
        switch(ch){
            case '+':
            case '-':
            case '*':
            case '/': 
            case '^':
                   while(prior[ch] < prior[stk2[top2]] && top2 >= 0) calc();
                    stk2[++top2] = ch;
                    break;
            case '(': stk2[++top2] = ch; break;
            case ')': 
                    while(stk2[top2] != '(') calc();
                    top2--;
                    break;
            default: stk1[++top1] = ch-'0';
        }
    }
    while(top2 >= 0) calc();
    printf("%d\n",stk1[0]);
    return 0;
}