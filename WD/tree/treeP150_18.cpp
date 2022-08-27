//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    int ltag,rtag;
    tNode *left,*right;
}tNode,*Tree;

void buildTree(Tree& t){
    char ch;
    cin >> ch;
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = ch;
        t->left = t->right = nullptr;
        t->ltag = t->rtag = 0;
        buildTree(t->left);
        buildTree(t->right);
    }
}

//中序线索化
tNode* pre = nullptr;  //记录前序结点
void inThread(Tree& t){
    if(!t) return;
    inThread(t->left);  //线索化左子树
    if(!t->left){  //建立当前节点的前驱线索
        t->left = pre;
        t->ltag = 1;
    }
    if(pre && pre->right){  //建立前驱节点的后继线索
        pre->right = t;
        pre->rtag = 1;
    }
    pre = t;  //前序结点改变
    inThread(t->right);  //线索化右子树
}

//中序二叉树某结点，在后续遍历中的前驱结点
/*
 * 1.如果该结点有右孩子，那么前驱就是右孩子
 * 2.如果该结点没有右孩子但有左孩子，那么前驱就是左孩子
 * 3.如果该结点既没有左孩子，也没有右孩子，那么沿着左线索向上找，3.1 若找到了有左孩子的前驱，那么这个前驱的左孩子就是该节点在后序中的前驱
 *                                                     3.2 若找到null为止，说明该结点不存在后序前驱
 */
tNode* find(Tree t,tNode* p){
    tNode *q;
    if(p->rtag == 0) return p->right;  //情况1
    else if(p->ltag == 0) return p->left;  //情况2
    else{   //情况3
        while (p->ltag == 1 && p->left)
            p = p->left;
        if(p->ltag == 0) return p->left;  //情况3.1
        return nullptr;    //情况3.2
    }
}


int main() {
    Tree t;
    buildTree(t);
    inThread(t);
    cout << find(t,t->right->left)->data << endl;
    return 0;
}
