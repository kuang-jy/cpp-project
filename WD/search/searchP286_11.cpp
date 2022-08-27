//
// Created by Kjoye on 2022/7/28.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    int data,count;
    tNode *left,*right;
}tNode,*Tree;

void bulidTree(Tree& t){
    int data,count;
    cin >> data;
    if(data == -1) t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = data;
        cin >> count;
        t->count = count;
        t->left = t->right = nullptr;
        bulidTree(t->left);
        bulidTree(t->right);
    }
}

//1、如果根结点没有左子树：1.1、如果k=1，那么根结点就是要找的
//                     1.2、如果k!=1，那么进入右子树 找第k-1小
//2、如果根结点有左子树：2.1、如果左子树的count=k-1，那么根结点就是要找的
//                   2.2、如果左子树的count<k-1，那么进入右子树 找k-(左子树count)-1（根结点）
//                   2.3、如果左子树的count>k-1，那么进入左子树 找第k小
//      递归边界：k<1 || k > root->count
tNode* getKMin(Tree t,int k){
    if(k < 1 || k > t->count) return nullptr;
    // case1
    if(!t->left){
        // case1.1
        if(k == 1) return t;
        // case1.2
        else return getKMin(t->right,k-1);
    }
    // case2
    else{
        // case2.1
        if(t->left->count == k-1) return t;
        else if(t->left->count < k-1) return getKMin(t->right,k-t->left->count-1);
        else return getKMin(t->left,k);
    }
}

int main() {
    //9 6 7 3 3 1 -1 -1 8 1 -1 -1 10 2 -1 15 1 -1 -1
    Tree t;
    bulidTree(t);
    cout << getKMin(t,3)->data << endl;
    cout << getKMin(t,1)->data << endl;
    cout << getKMin(t,6)->data << endl;
    return 0;
}
