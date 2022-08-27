//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void bulidTree(Tree& t){
    char ch;
    cin >> ch;
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = ch;
        t->left = t->right = nullptr;
        bulidTree(t->left);
        bulidTree(t->right);
    }
}

bool isSimilar(Tree t1,Tree t2){
    bool l,r;
    if(!t1 && !t2) return true;
    else if(!t1 || !t2) return false;
    else{
        l = isSimilar(t1->left,t2->left);
        r = isSimilar(t1->right,t2->right);
        return l&&r;
    }
}

int main() {
    //AB###
    //C#D##
    Tree t1,t2;
    bulidTree(t1);
    bulidTree(t2);
    cout << isSimilar(t1,t2) << endl;
    return 0;
}
