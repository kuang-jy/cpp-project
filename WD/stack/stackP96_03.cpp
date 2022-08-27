//
// Created by Kjoye on 2022/7/21.
//

#include <bits/stdc++.h>

using namespace std;

#define MaxSize 10
struct {
    int n;
    double val;
}stk[MaxSize];

double ans(int n,double x){
    int top = -1;
    for (int i = n; i >= 2; --i) {
        stk[++top].n = i;  // 5,4,3,2
    }
    double pn_1 = 2*x,pn_2 = 1;  //前两层的值
    while (top >= 0){
        stk[top].val = 2*x*pn_1 - 2*(stk[top].n-1)*pn_2;  //计算当前层的值
        pn_2 = pn_1;
        pn_1 = stk[top].val;
        top--;
    }
    if(n == 0) return pn_2;
    return pn_1;
}

int main() {
    cout << ans(3,1.9) << endl;
    return 0;
}
