//
// Created by Kjoye on 2022/7/20.
//

#include <bits/stdc++.h>

using namespace std;

#define Maxsize 10
typedef struct {
    int data[Maxsize];   //队列内存
    int front,rear,tag;  //队头，队尾，标识
}que;

typedef struct{
    int data[Maxsize];
    int top;
}stk;

//入栈
bool pushS(stk &S,int x){
    if(S.top == Maxsize-1) return false;
    S.data[++S.top] = x;
    return true;
}
//出栈
int popS(stk& S){
    if(S.top == -1) return -1;
    return S.data[S.top--];
}

//入队
int pushQ(que& qq,int x){
    //判断队满
    if(qq.front == qq.rear && qq.tag == 1){
        printf("队满\n");
        return -1;
    }
    qq.data[qq.rear] = x;  //入队
    qq.rear = (qq.rear+1) % Maxsize;
    qq.tag = 1;  //标记操作
    return 1;
}

//出队
int popQ(que& qq){
    //判断队空
    if(qq.rear == qq.front && qq.tag == 0){
        printf("队空\n");
        return -1;
    }
    qq.tag = 0; //标记操作
    int x = qq.data[qq.front];
    qq.front = (qq.front+1) % Maxsize;
    return x;
}

bool isQEmpty(que q){
    return q.front == q.rear && q.tag == 0;
}
bool isSEmpty(stk s){
    return s.top == -1;
}

int main() {
    que q;
    q.rear = 0;
    q.front = 0;
    stk s;
    s.top = -1;
    pushQ(q,1);
    pushQ(q,2);
    pushQ(q,3);
    pushQ(q,4);
    pushQ(q,5);
    while (!isQEmpty(q)){
        pushS(s,popQ(q));
    }
    while (!isSEmpty(s)){
        pushQ(q,popS(s));
    }
    while (!isQEmpty(q)){
        printf("%d ",popQ(q));
    }
    return 0;
}
