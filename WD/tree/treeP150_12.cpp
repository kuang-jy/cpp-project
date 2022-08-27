//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

typedef struct{
    tNode* n;
    int tag;
}stk;

void buildtree(Tree& t){
    char ch;
    ch = getchar();
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*) malloc(sizeof(tNode));
        t->data = ch;
        t->left = nullptr;
        t->right = nullptr;
        buildtree(t->left);
        buildtree(t->right);
    }
}

//某节点的根结点都在上方，所以使用非递归的后序遍历，这样当访问到值为x的结点时，栈中元素就是x的所有祖先节点
void ancestor(Tree t,char x){
    if(!t) return;
    stk s[10];  //初始化栈
    int top = -1;  //栈顶初始化
    while (t || top != -1) {
        while (t && t->data != x) {  //向左下走到底
            s[++top].n = t;
            s[top].tag = 0;  //标记这个结点，还没访问右孩子
            t = t->left;
        }
        if (t && t->data == x) {  //若在上一步循环中退出，且t不是空，那么说明找到了x
            while (top != -1) printf("%c ", s[top--].n->data); //栈中所有结点都是祖先
            return;
        }
        while (top != -1 && s[top].tag == 1)  //如果栈顶结点的右孩子已经访问，那么直接退栈
            top--;
        if(top != -1){
            s[top].tag = 1;
            t = s[top].n->right;
        }
    } //while (t || top != -1)
}

int main() {
    //ABD##E##CF##G##
    Tree t;
    buildtree(t);
    ancestor(t,'E');
    return 0;
}
