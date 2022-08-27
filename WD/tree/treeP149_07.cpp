//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void buildtree(Tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(tNode *)malloc(sizeof(tNode));
        t->data=ch;
        t->left=NULL;
        t->right=NULL;
        buildtree(t->left);
        buildtree(t->right);
    }
}

bool judge(Tree t){
    if(!t) return true;
    tNode* q[15];  //队列
    int front = -1,rear = -1;
    q[++rear] = t;  //根入队
    bool flag = true;  //记录是否出现过空结点
    tNode *temp;
    while (front < rear){
        temp = q[++front]; //取得队头结点
        if(!temp) flag = false;  //标记出现过null
        else{
            if(!flag) return false;  //如果出现过一次null 后面队列中还有元素的话就不是完全二叉树
            q[++rear] = temp->left;
            q[++rear] = temp->right;
        }
    }
    return true;
}

using namespace std;

int main() {
    Tree t;
    buildtree(t);
    cout << judge(t) << endl;
    return 0;
}
