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

int getDepth(Tree t){
    if(!t) return 0;
    return max(getDepth(t->left), getDepth(t->right))+1;
}

bool isBalance2(Tree t){
    if(!t) return true;
    int h1 = getDepth(t->left);
    int h2 = getDepth(t->right);
    if(abs(h1-h2) >= 2) return false;
    return true;
}

//一个函数，求树的深度 以及 是否平衡
void isBalance(Tree t,int& height,bool& balance){
    int hl = 0,hr = 0;
    bool bl = false,br = false;
    if(!t){   //空树平衡，且高度为0
        height = 0;
        balance = true;
    }
    else{      //有左右孩子
        isBalance(t->left,hl,bl);  //求左子树高度，是否平衡
        isBalance(t->right,hr,br);  //求右子树高度，是否平衡
        height = hl > hr ? hl+1 : hr+1;    //当前树的高度是左子树和右子树高度中较高者+1
        if(abs(hl-hr) < 2) balance = bl && br;  //判断当前树是不是平衡的
        else balance = false;
    }
}

int main() {
    //9 7 3 -1 -1 8 -1 -1 10 -1 15 -1 -1  平衡
    //7 3 -1 -1 9 8 -1 -1 10 -1 15 -1 -1  不平衡
    Tree t;
    buildTree(t);
    cout << isBalance2(t) << endl;
    bool flag;
    int depth;
    isBalance(t,depth,flag);
    cout << depth << " " << flag << endl;
    return 0;
}
