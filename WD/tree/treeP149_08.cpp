//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void buildtree(Tree &t)  //先序建树
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

int doubleNode(Tree t){
    if(!t) return 0;
    if(t->left && t->right) return doubleNode(t->left)+ doubleNode(t->right) + 1;  //如果当前结点是双分支
    else return doubleNode(t->left)+ doubleNode(t->right);
}

int main() {
    Tree t;
    buildtree(t);
    cout << doubleNode(t) << endl;
    return 0;
}
