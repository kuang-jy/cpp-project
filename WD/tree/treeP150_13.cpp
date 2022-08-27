//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

typedef struct {
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

tNode* getCommon(Tree t,tNode* a,tNode* b){  //假设a在b的左边，那么先找到的就是a
    stk s1[10],s2[10];  //两个栈，s2是辅助栈
    int top = -1;
    int top1 = -1;
    while (t || top != -1){
        while (t){   //沿着左分支向下
            s1[++top].n = t;
            s1[top].tag = 0;
            t = t->left;
        }
        while (top != -1 && s1[top].tag == 1){i
            if(s1[top].n == a){
                for (int i = 0; i <= top; ++i) s2[i] = s1[i];
                top1 = top;
            }
            if(s1[top].n == b)
                for (int i = top; i >= 0; --i)
                    for (int j = top1; j >= 0; --j)
                        if(s1[i].n == s2[j].n) return s1[i].n;
            top--;
        }  //while (top != -1 && s1[top].tag == 1)
        if(top != -1){
            s1[top].tag = 1;
            t = s1[top].n->right;
        }
    }
    return nullptr;
}

int main() {
    Tree t;
    buildtree(t);
    cout << getCommon(t,t->left->left,t->left)->data << endl;
    return 0;
}
