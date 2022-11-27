#include <iostream>
using namespace std;

typedef struct TNode{
    int ltag,rtag;
    char val;
    TNode *left,*right;
}TNode,*Tree;

void buildTree(Tree& t)  //先序建树
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else{
        t=(TNode *)malloc(sizeof(TNode));
        t->val=ch;
        t->left=NULL;
        t->right=NULL;
        buildTree(t->left);
        buildTree(t->right);
    }
}


//中序线索化
void inThread(Tree& root,TNode*& pre){
    if(!root) return;
    inThread(root->left,pre);
    if(!root->left){
        root->left = pre;
        root->ltag = 1;
    }
    if(pre && !pre->right){
        pre->right = root;
        pre->rtag = 1;
    }
    pre = root;
    inThread(root->right,pre);
}

//先序线索化
void preThread(Tree& root,Tree& pre){
    if(!root) return;
    if(!root->left) {
        root->left = pre;
        root->ltag = 1;
    }
    if(pre && !pre->right){
        pre->right = root;
        pre->rtag = 1;
    }
    pre = root;
    //防止转圈，加入判断
    if(root->ltag != 1)
        preThread(root->left,pre);
    if(root->rtag != 1)
    preThread(root->right,pre);
}

//后序线索化
void postThread(Tree& root,Tree&pre){
    if(!root) return;
    postThread(root->left,pre);
    postThread(root->right,pre);
    if(!root->left){
        root->left = pre;
        root->ltag = 1;
    }
    if(pre && !pre->right){
        pre->right = root;
        pre->rtag = 1;
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
    // abd###cf###
    // ABCE##F##D##CD##G##
    Tree t;
    buildTree(t);
    disp(t);
    Tree pre = NULL;
    // inThread(t,pre);
    // preThread(t,pre);
    postThread(t,pre);
    return 0;
}