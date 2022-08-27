//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode {
    int data;
    tNode *left,*right;
}tNode,*Tree;

int depth(Tree t){
    int depth = 0;
    if(!t) return depth;  //树空，深度为0
    tNode* q[10];  //模拟队列
    int f = -1,r = -1;  //队头，队尾指针
    q[++r] = t;  //根节点入队
    tNode* temp;
    int last = 0; //初始last为头结点
    while (f < r){
        temp = q[++f];  //队头出队
        if(temp->left) q[++r] = temp->left;
        if(temp->right) q[++r] = temp->right;
        if(f == last) {  //如果是当前层的最后一个结点，层数+1，并让last指向下一层的最后一个结点
            last = r;
            depth++;
        }

    }
    return depth;
}

int main() {

    return 0;
}
