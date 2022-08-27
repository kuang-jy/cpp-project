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

int getMin(Tree t){  //向左下走到底
    while (t->left)
        t = t->left;
    return t->data;
}

int getMax(Tree t){  //向右下走到底
    while (t->right)
        t = t->right;
    return t->data;
}

int main() {
    //9 7 3 -1 -1 8 -1 -1 10 -1 15 -1 -1
    Tree t;
    buildTree(t);
    cout << getMax(t) << endl;
    cout << getMin(t) << endl;
    return 0;
}
