//
// Created by Kjoye on 2022/7/21.
//

#include <bits/stdc++.h>

using namespace std;
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int f,r,tag;
}que;

void init(que& q){
    q.r = q.f = 0;
    q.tag = 0;
}
bool isEmpty(que q){
    return q.f == q.r && q.tag == 0;
}
bool isFull(que q){
    return q.r = q.f && q.tag == 1;
}
void pop(que& q,int& x){
    if(isEmpty(q)) return;
    x = q.data[q.f];
    q.f = (q.f+1)%MaxSize;
    q.tag = 0;
}
void push(que& q,int x){
    if(isFull(q)) return;
    q.data[q.r] = x;
    q.r = (q.r+1) % MaxSize;
    q.tag = 1;
}

void show(que q){
    int x;
    while (!isEmpty(q)){
        pop(q,x);
        cout << x << " ";
    }
    cout << endl;
}

void manage(que& q1,que& q2){  //客车，货车队列
    que ship;
    init(ship);
    int num = 0;  //记录已上船数量
    int count = 0;  //记录客车上船数量
    int car;
    while (num < 10){
        if(!isEmpty(q1) && count != 4) {  //还有客车，且已上船数量不到4
            pop(q1,car);
            push(ship,car);
            num++;
            count++;
        }
        else if(count == 4 && !isEmpty(q2)){  //客车上足4量，且还有货车
            pop(q2,car);
            push(ship,car);
            count = 0;
            num++;
        }
        else if(count != 4 && !isEmpty(q2)){  //客车没上足4量，客车不够，货车补
            pop(q2,car);
            push(ship,car);
            num++;
            count++; //当作客车
        }
        else count = 0;  //客车上够4量，没有货车，重置计数，继续上客车
        if(isEmpty(q1) && isEmpty(q2)) num = 11;  //货车+客车不足10，直接退出循环
    }
    show(q1);
    show(q2);
    show(ship);
}


int main() {
    que q1;
    que q2;
    init(q1);
    init(q2);
    for (int i = 0; i < MaxSize; ++i) {
        push(q1,1);
        push(q2,2);
    }
    manage(q1,q2);
    return 0;
}
