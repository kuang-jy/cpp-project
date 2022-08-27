//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void exchange(Tree& t){
    if(!t) return;
    tNode* temp = t->left;
    t->left = t->right;
    t->right = temp;
    exchange(t->left);
    exchange(t->right);
}

int main() {

    return 0;
}
