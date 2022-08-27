//
// Created by Kjoye on 2022/7/25.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void buildTree(Tree& t){
    char ch = getchar();
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = ch;
        t->left = t->right = nullptr;
        buildTree(t->left);
        buildTree(t->right);
    }
}

//孩子兄弟法表示的树的高度
// 高度为第一孩子子树的高度 和 所有兄弟子树的高度中较大的一个
int getDepth(Tree t){
    int h1,h2;  //孩子子树的高度，兄弟子树的高度
    if(!t) return 0;  //空树高度0
    else{
        h1 = getDepth(t->left) + 1;  //计算孩子子树的高度
        h2 = getDepth(t->right);  //计算兄弟子树的高度
        return h1 > h2 ? h1 : h2;
    }
}

int main() {
    /*
     * ABE#F##C#DG####
     */
    Tree t;
    buildTree(t);
    cout << getDepth(t) << endl;
    return 0;
}
