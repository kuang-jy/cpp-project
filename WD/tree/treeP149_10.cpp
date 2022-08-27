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

int num = 1;
char kOfPreorder(Tree t,int k){
    if(!t) return '#';
    if(k == num) return t->data;
    num++;  //根节点查找完成
    //左子树
    char ans = kOfPreorder(t->left,k);
    if(ans != '#') return ans;   //如果不在左子树
    return kOfPreorder(t->right,k);  //直接返回右子树的查找结果
}

int main() {
    Tree t;
    buildtree(t);
    cout << kOfPreorder(t,3) <<endl;
    return 0;
}
