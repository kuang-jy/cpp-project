//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    int data;
    tNode *left,*right;
}tNode,*Tree;

Tree getTree(int preOrder[],int inOrder[],int l1,int r1,int l2,int r2){  //先序，中序，先序的开始和结束，中序的开始和结束
    tNode *root = (tNode*) malloc(sizeof(tNode));
    root->data = preOrder[l1];
    //在中序数组找到根节点
    int i = l2;
    for (; inOrder[i] != preOrder[l1]; i++);
    //计算左右子树的数组下标
    int lenl = i-l2;  //左子树长度
    int lenr = r2-i;   //右子树长度
    if(lenl) root->left = getTree(preOrder,inOrder,l1+1,l1+lenl,l2,i-1);
    else root->left = nullptr;
    if(lenr) root->right = getTree(preOrder,inOrder,l1+lenl+1,r1,i+1,r2);
    else root->right = nullptr;
    return root;
}

int main() {

    return 0;
}
