//
// Created by Kjoye on 2022/7/27.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    int data;
    tNode *left,*right;
}tNode,*Tree;

void bulidTree(Tree& t){
    int num ;
    cin >> num;
    if(num == -1) t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = num;
        t->left = t->right = nullptr;
        bulidTree(t->left);
        bulidTree(t->right);
    }
}

//二叉排序树的中序遍历是一个递增的有序序列，能保证这个就是二叉排序树
int pre = -999999;  //初始化为无无穷小
bool isBST(Tree t){
    if(!t) return true;  //空树是二叉排序树
    int l,r;
    l = isBST(t->left);  //先判断左子树
    if(!l || pre >= t->data) return false;  //如果左子树不是排序树，或者前一个结点值大于等于当前结点
    pre = t->data;   //更新上一个结点值
    r = isBST(t->right);  //后判断右子树
}

int main() {
    //10 5 4 -1 -1 6 -1 -1 15 14 -1 -1 -1  -> true
    Tree t;
    bulidTree(t);
    cout << isBST(t) << endl;
    return 0;
}
