//
// Created by Kjoye on 2022/7/24.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *left,*right;
}tNode,*Tree;

void pre2post(char pre[],int l1,int h1,char post[],int l2,int h2){
    if(l1 > h1) return;
    int half = (h1-l1)/2;  //求子树长度
    post[h2] = pre[l1];  //当前先序的根结点，作为后序的末尾结点
    pre2post(pre,l1+1,l1+half,post,l2,l2+half-1);  //递归构造左子树
    pre2post(pre,h1-half+1,h1,post,h2-half,h2-1);  //递归构造右子树
}

int main() {
    char pre[]{'A','B','D','E','C','F','G'};
    char post[7];
    pre2post(pre,0,6,post,0,6);
    for (char i : post) {
        cout << i << " ";
    }
    cout<< endl;
    return 0;
}
