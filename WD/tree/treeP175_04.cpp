//
// Created by Kjoye on 2022/7/25.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct tNode{
    char data;
    tNode *firstchild,*nextsibling;
}tNode,*Tree;

void bulidTree(Tree& t){
    char ch = getchar();
    if(ch == '#') t = nullptr;
    else{
        t = (tNode*)malloc(sizeof(tNode));
        t->data = ch;
        t->nextsibling = t->firstchild = nullptr;
        bulidTree(t->firstchild);
        bulidTree(t->nextsibling);
    }
}

// 若结点没有左孩子，那么必然是叶子结点
int getLeavesNum(Tree t){
    if(!t) return 0;
    if(!t->firstchild) return 1+getLeavesNum(t->nextsibling);  //当前结点是叶子，那总的叶子数就加一，继续算兄弟子树的叶子结点
    else return getLeavesNum(t->firstchild) + getLeavesNum(t->nextsibling);
}

int main() {
    /*
          A
        B   F       //叶子D E C G
      D  C G
       E

       ABD#E##C##FG###
     */
    Tree t;
    bulidTree(t);
    cout << getLeavesNum(t) <<endl;
    return 0;
}
