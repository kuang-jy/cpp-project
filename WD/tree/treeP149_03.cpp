//
// Created by Kjoye on 2022/7/22.
//

#include <bits/stdc++.h>

using namespace std;

void postOrder(bitTree T){
    stk S;
    initStack(S);
    treeNode *p = T;
    while(p || !IsEmpty(S)){
        if(p){
            push(S,p);
            p = p.left;
        } else{
            getTop(S,p);
            if(p.right && p.tag == 0)
                p = p.right;
            else{
                pop(S,p);
                visit(p);
                p.tag = 1;
                p = nullptr;
            }
        }
    }
}

int main() {

    return 0;
}
