//
// Created by Kjoye on 2022/7/20.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct linkNode{
    int data;
    linkNode *next;
} linkNode,*linkList;

//P70 04
bool isSym(linkList L,int n){  //n为链表长度
    stack<linkNode*> stack;
    linkNode *p = L->next;
    for (int i = 0; i < 2/n; ++i) {
        stack.push(p);
        p = p->next;
    }
    if(n % 2 != 0) {
        p = p->next;
        stack.pop();
    }
    while (!stack.empty() && p){
        if(stack.top()->data != p->data) return false;
        stack.pop();
        p = p->next;
    }
    return true;
}

//P70 05
#define MaxSize 50
typedef struct{
    int data[MaxSize];  //栈的空间
    int top[2];  //两个栈顶指针
} stk;
stk s;  //全局变量

//入栈操作
int push(int i,int x){  //i为栈号，x为入栈元素
    //成功返回1，否则0
    if(i != 0 && i != 1) {
        printf("栈号错误");
        return 0;
    }
    //判断栈满
    if(s.top[1]-s.top[0] == 1){
        printf("栈满");
        return 0;
    }
    switch (i) {
        case 0:
            s.data[++s.top[0]] = x; return 1;
        case 1:
            s.data[++s.top[1]] = x; return 1;
    }
}

//出栈操作
int pop(int i){  //i为栈号
    if(i != 0 && i != 1){
        printf("栈号有误");
        return 0;
    }
    switch (i) {
        case 0:
            //判断栈空
            if(s.top[0] == -1){
                printf("栈空");
                return -1;
            }//end if
            return s.data[s.top[0]--];
        case 1:
            //判断栈空
            if(s.top[1] == MaxSize){
                printf("栈空");
                return -1;
            } //end if
            return s.data[s.top[1]++];
    }// end switch
}

int main() {
    s.top[0] = -1;
    s.top[1] = MaxSize;
    return 0;
}
