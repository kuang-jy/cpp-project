//
// Created by Kjoye on 2022/7/22.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;

void solve(tree t) {
    stack<treenode *> s;
    queue<treenode *> q;
    q.push(t);
    while (!q.empty()) {
        s.push(q.front());
        if (q.front()->lchild) q.push(q.front()->lchild);
        if (q.front()->rchild) q.push(q.front()->rchild);
        q.pop();
    }
    while (!s.empty()) {
        cout << s.top() << " " << endl;
        s.pop();
    }
}

int main() {
    return 0;
}
