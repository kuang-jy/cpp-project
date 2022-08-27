//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

typedef struct Q{
    tNode* data[10]; //保存每个结点指针
    int front,rear;
    int level[10];  //保存每个结点的层次
}Q;

void buildTree(Tree& t){
    char ch = getchar();
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof (tNode));
        t->data = ch;
        t->left = t->right = nullptr;
        buildTree(t->left);
        buildTree(t->right);
    }
}

int getMaxWidth(Tree t){
    Q q;
    q.front = q.rear = -1;
    int n ;  //记录当前层次
    q.data[++q.rear] = t;  //根节点入队
    q.level[q.rear] = 1;  //根节点层次是1
    tNode* temp;
    while (q.front < q.rear){
        temp = q.data[++q.front];
        n = q.level[q.front];  //出队结点所在层次
        if(temp->left){
            q.data[++q.rear] = temp->left;
            q.level[q.rear] = n+1;  //加深一层
        }
        if(temp->right){
            q.data[++q.rear] = temp->right;
            q.level[q.rear] = n+1;  //加深一层
        }
    } // end while (q.front < q.rear)
    int level = 1;  //第一层开始
    int max = 1;  //记录最多结点数量
    int i = 0;
    while (i <= q.rear) {
        int count = 0;
        while (i <= q.rear && q.level[i] == level) {
            count++;
            i++;
        }
        level = q.level[i];
        if(count > max) max = count;
    }
    return max;
}


int main() {
    Tree t;
    buildTree(t);
    cout << getMaxWidth(t);
    return 0;
}
