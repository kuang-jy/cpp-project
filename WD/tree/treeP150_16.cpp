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
    char ch = getchar();
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof (tNode));
        t->data = ch;
        t->left = nullptr;
        t->right = nullptr;
        bulidTree(t->left);
        bulidTree(t->right);
    }
}

tNode* head = (tNode*)malloc(sizeof (tNode));  //链表头结点
tNode* pre = nullptr;   //记录前一个叶子节点
tNode* getList(Tree t){   //使用中序遍历构造
    if(!t) return nullptr;
    getList(t->left);  //左子树
    if(!t->left && !t->right){  //如果当前结点是叶子结点
        if(!pre){  //如果是第一个叶子结点
            head->right = t;
            pre = t;
        } else{
            pre->right = t;
            pre = t;
        }
        pre->right = nullptr;
    }
    getList(t->right);  //右子树
    return head;
}

int main() {
    //ABD##E##C####
    Tree t;
    bulidTree(t);
    tNode* x = getList(t);
    x = x->right;
    while (x){
        cout << x->data << " " ;
        x = x->right;
    }
    return 0;
}
