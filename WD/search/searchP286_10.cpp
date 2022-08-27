//
// Created by Kjoye on 2022/7/28.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    int data;
    tNode *left,*right;
}tNode,*Tree;

void buildTree(Tree& t){
    int data;
    cin >> data;
    if(data == -1) t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = data;
        t->left = t->right = nullptr;
        buildTree(t->left);
        buildTree(t->right);
    }
}

//遍历顺序：右-》根-》左，得到递减序列，判断是否要输出
void disp(Tree t,int k){
    if(!t) return;
    if(t->data < k) return;
    disp(t->right,k);
    printf("%d ",t->data);
    disp(t->left,k);
}

int main() {
    //9 7 3 -1 -1 8 -1 -1 10 -1 15 -1 -1  平衡
    //7 3 -1 -1 9 8 -1 -1 10 -1 15 -1 -1  不平衡
    Tree t;
    buildTree(t);
    disp(t,7);
    return 0;
}
