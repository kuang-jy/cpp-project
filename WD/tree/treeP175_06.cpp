//
// Created by Kjoye on 2022/7/25.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void bulidTree(char preOrder[],int degree[],Tree& root){  //先序序列，结点的度，结点个数，待构造的树的根节点
    int n = sizeof(preOrder)/sizeof(preOrder[0]);  //计算结点数量
    tNode* arr[n];  //存放每个结点的指针
    for (int j = 0; j < n; ++j) {  //初始化所有结点
        arr[j] = (tNode*) malloc(sizeof (tNode));  //分配空间
        arr[j]->data = preOrder[j];
        arr[j]->left = arr[j]->right = nullptr;
    }
    int d,k = 0;
    for (int i = 0; i < n; ++i) {
        d = degree[i]; //当前结点的度
        if(d){    //如果度不为0
            arr[i]->left = arr[++k];   //将第一个孩子链入
            for (int j = 1; j < d; ++j) {
                k++;
                arr[k-1]->right = arr[k];
            }
        }
    }
    root = arr[0];
}

void disp(Tree t){
    if(!t) return;
    cout << t->data << " ";
    disp(t->left);
    disp(t->right);
}

int main() {
    char preOrder[]{'A','B','C','D','E','F','G'};
    int degree[]{3,2,0,1,0,0,0};
    tNode* root;
    bulidTree(preOrder,degree,root);
    disp(root);
    return 0;
}
