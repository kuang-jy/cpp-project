//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    char data[10];
    struct node *left,*right;
}BTree;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void buildTree(Tree& t){
    char weight;
    cin >> weight;
    if(weight == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = weight;
        t->left = t->right = nullptr;
        buildTree(t->left);
        buildTree(t->right);
    }
}

void tree2exp(Tree root,int deep){
    if(!root) return;
    else if(!root->left && !root->right) printf("%c",root->data);  //操作数
    else {
        if (deep > 1) printf("(");
        tree2exp(root->left, deep + 1);
        printf("%c",root->data);   //操作符
        tree2exp(root->right, deep + 1);
        if (deep > 1) printf(")");
    }
}

int main() {
    //*+a##b##*c##-#d##
    Tree t;
    buildTree(t);
    tree2exp(t,1);
    return 0;
}
