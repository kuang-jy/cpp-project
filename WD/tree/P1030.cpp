#include <bits/stdc++.h>
using namespace std;
int n;
char a[9],b[9];

void build(char inOrder[],char postOrder[],int l1,int h1,int l2,int h2){
    if(l1 > h1) return ;
    //在中序里找到根
    int k;
    for(k = l1;k <= h1;k++) if(inOrder[k] == postOrder[h2]) break;
    cout << inOrder[k];  //输出根
    int len1 = k-l1;   //左子树长度
    build(inOrder,postOrder,l1,k-1,l2,l2+len1-1);
    build(inOrder,postOrder,k+1,h1,l2+len1,h2-1);
}

int main(){
    cin >>a;
    cin >>b;
    build(a,b,0, strlen(a)-1,0, strlen(b)-1);
    return 0;
}

