//
// Created by Kjoye on 2022/7/21.
//

#include <bits/stdc++.h>

using namespace std;
#define MaxSize 10
#define eleType char
typedef struct{
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

void train(char* str){
    stk s;
    init(s);
    char ans[MaxSize];
    int i = 0;
    int j = 0;
    while (str[i] != '\0'){
        if(str[i] == 'H') push(s,'H');
        else ans[j++] = 'S';
        i++;
    }
    char c;
    while (!isEmpty(s)){
        c = pop(s);
        ans[j++] = c;
    }
    for (char an : ans) cout << an << " ";
    cout << endl;
}

int main() {
    char* x = (char*)"HSHSSSSHHS";
    train(x);
    return 0;
}
