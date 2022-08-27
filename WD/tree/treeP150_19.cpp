//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    int weight;
    tNode *left,*right;
}tNode,*Tree;

void buildTree(Tree& t){
    int weight;
    cin >> weight;
    if(weight == -1) t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->weight = weight;
        t->left = t->right = nullptr;
        buildTree(t->left);
        buildTree(t->right);
    }
}

int wpl = 0;
void WPL(Tree t,int deep){
    if(!t) return ;
    if(!t->left && !t->right)
        wpl += deep * t->weight;
    WPL(t->left,deep+1);
    WPL(t->right,deep+1);
}

int main() {
    Tree t;
    buildTree(t);
    WPL(t,0);
    cout << wpl << endl;
    return 0;
}
