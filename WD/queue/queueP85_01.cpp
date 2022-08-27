//
// Created by Kjoye on 2022/7/20.
//

#include <bits/stdc++.h>

using namespace std;

#define MaxSize 5
typedef struct {
    int data[MaxSize];   //队列内存
    int front,rear,tag;  //队头，队尾，标识
}que;
que q;

//入队
int push(que& qq,int x){
    //判断队满
    if(qq.front == qq.rear && qq.tag == 1){
        printf("队满\n");
        return -1;
    }
    qq.data[qq.rear] = x;  //入队
    qq.rear = (qq.rear+1) % MaxSize;
    qq.tag = 1;  //标记操作
    return 1;
}

//出队
int pop(que& qq){
    //判断队空
    if(qq.rear == qq.front && qq.tag == 0){
        printf("队空\n");
        return -1;
    }
    qq.tag = 0; //标记操作
    int x = qq.data[qq.front];
    qq.front = (qq.front+1) % MaxSize;
    return x;
}

int main() {
    //初始化队列
    q.front = 0;
    q.rear = 0;
    pop(q);  //队空
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    push(q,5);
    push(q,6);//队满
    cout << pop(q) << endl;
    cout << pop(q) << endl;
    return 0;
}
