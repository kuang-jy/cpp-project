//
// Created by Kjoye on 2022/7/28.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    int data;
    tNode *left,*right;
}tNode,*Tree;

void bulidTree(Tree& t){
    int data;
    cin >> data;
    if(data == -1) t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = data;
        t->left = t->right = nullptr;
        bulidTree(t->left);
        bulidTree(t->right);
    }
}

//递归方式
int getDepth(Tree t,tNode* node){
    if(!t) return 0;   //递归边界，叶子结点或空树返回0，向上求和至根结点
    if(node->data > t->data) return getDepth(t->right,node)+1;
    return getDepth(t->left,node)+1;
}

//非递归方式
int getDepth2(Tree t,tNode* node){
    if(!t) return 0;  //空树层次为0
    int depth = 0;
    tNode *curNode = t;
    while (curNode){
        if(node->data > curNode->data) curNode = curNode->right;
        else curNode = curNode->left;
        depth++;
    }
    return depth;
}

int main() {
    //9 7 3 -1 -1 8 -1 -1 10 -1 15 -1 -1
    Tree t;
    bulidTree(t);
    cout << getDepth2(t,t->left->right) << endl;
    return 0;
}
