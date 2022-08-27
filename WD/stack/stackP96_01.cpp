//
// Created by Kjoye on 2022/7/21.
//

#include <bits/stdc++.h>

using namespace std;

#define MaxSize 10
#define eleType char
typedef struct {
    eleType data[MaxSize];
    int top;
}stk;

void init(stk& S){
    S.top = -1;
}

bool push(stk& S,char x){
    if(S.top == MaxSize-1) return false;
    S.data[++S.top] = x;
    return true;
}

eleType pop(stk& S){
    if(S.top == -1) return -1;
    return S.data[S.top--];
}

bool isEmpty(stk S){
    return S.top == -1;
}

bool isValid(char* str){
    stk s;
    init(s);  //初始化栈
    int i = 0;
    char temp;
    while (str[i] != '\0'){
        switch (str[i]) {
            case '{':
                push(s,'{');
                break;
            case '(':
                push(s,'(');
                break;
            case '[':
                push(s,'[');
                break;
            case '}':
                temp = pop(s);
                if(temp != '{') return false;
                break;
            case ')':
                temp = pop(s);
                if(temp != '(') return false;
                break;
            case ']':
                temp = pop(s);
                if(temp != '[') return false;
                break;
            //不是括号不进行操作
            default:;
        }  //end switch
        i++;
    } //end while
    //栈空则匹配成功
    if(isEmpty(s)) return true;
    return false;
}

int main() {
    char* str = (char*)"(){}[])";
    cout << isValid(str) << endl;
    return 0;
}
