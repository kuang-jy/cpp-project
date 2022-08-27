//
// Created by Kjoye on 2022/7/23.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void buildtree(Tree &t)  //先序建树
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else{
        t=(tNode *)malloc(sizeof(tNode));
        t->data=ch;
        t->left=NULL;
        t->right=NULL;
        buildtree(t->left);
        buildtree(t->right);
    }
}

void del(Tree& t){   //删除t结点为根的树
    if(!t) return;
    del(t->left);  //先删当前结点的左
    del(t->right);  //再删当前结点的右
    free(t);  //释放当前结点
}

void searchDel(Tree& t,char x){  //找到值为x的结点，并删除以x为根的树
    if(!t) return;
    if(t->data == x) {
        del(t); //如果根节点值为x，直接删除根节点
        t = nullptr;
    }
    else {     //进入左右子树寻找，并删除
        searchDel(t->left, x);
        searchDel(t->right, x);
    }
}

void display(Tree t){
    if(t){
        cout << t->data << " ";
        display(t->left);
        display(t->right);
    }
}

int main() {
    //ABCE##F##D##CD##G##
    Tree t;
    buildtree(t);
    searchDel(t,'C');
    display(t);
    return 0;
}
