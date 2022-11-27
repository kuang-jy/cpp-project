#include <iostream>
using namespace std;

typedef struct TNode{
    char val;
    TNode *left,*right;
}TNode,*Tree;

void calcSub(float a,char op,float b,float& ans){
    if(op == '+') ans =  a+b;
    else if(op == '-') ans =  a-b;
    else if(op == '*') ans =  a*b;
    else ans = a/b;
}

float calc(Tree root){
    if(!root->left && !root->right) return root->val - '0';   //叶子结点直接返回值
    float subL = calc(root->left);
    float subR = calc(root->right);
    float ans;
    calcSub(subL,root->val,subR,ans);
    return ans;
}

void bulidTree(Tree& root){
    char ch;
    ch = getchar();
    if(ch == '#') root = NULL;
    else{
        root = (TNode*)malloc(sizeof(TNode));
        root->val = ch;
        root->left = root->right = NULL;
        bulidTree(root->left);
        bulidTree(root->right);
    }
}

void disp(Tree root){
    if(root){
        cout << root->val << " ";
        disp(root->left);
        disp(root->right);
    }
}

int main(){
    // +3##**4##5##+2##3##
    Tree t;
    bulidTree(t);
    // disp(t);
    cout << calc(t) << endl;
    return 0;
}