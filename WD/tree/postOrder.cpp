//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void buildTree(Tree& t){
    char ch;
    ch = getchar();
    if (ch == '#') t = nullptr;
    else{
        t = (tNode*) malloc(sizeof (tNode));
        t->data = ch;
        t->left = t->right = nullptr;
        buildTree(t->left);
        buildTree(t->right);
    }
}

typedef struct {
    tNode* node;
    int tag;
}stk;

void postOrder(Tree t){  //非递归的后序遍历
    stk s[10];
    int top = -1;
    while (t || top != -1){
        while (t){  //当前结点作为根节点，向左走到底
            s[++top].node = t;
            s[top].tag = 0;
            t = t->left;
        }
        while (top != -1 && s[top].tag == 1){  //检查是否有完成遍历的结点，全部弹出
            cout << s[top--].node->data  << " ";
        }
        if(top != -1){  //继续访问栈顶结点的右子树
            s[top].tag = 1;
            t = s[top].node->right;
        }
    }
}

int main() {
    Tree t;
    buildTree(t);
    postOrder(t);
    return 0;
}
