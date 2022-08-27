//
// Created by Kjoye on 2022/7/22.
//

#include <bits/stdc++.h>

using namespace std;

struct tree{
    int data[12] = {-1,1,2,3,-1,4-1,5,-1,-1,6,-1};
};

int getLowest(tree t,int n1,int n2){
    if(t.data[n1] != -1 && t.data[n2] != -1)
        while (n1 != n2){
            //编号大的先找（层次更深）
            if(n1 > n2) n1/=2;  //父节点
            else n2/=2;  //父节点
        }
    return t.data[n1];
}

int main() {
    tree t;
    cout << getLowest(t,1,2) << endl;
    return 0;
}
