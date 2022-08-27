//
// Created by Kjoye on 2022/4/20.
//

#include <bits/stdc++.h>

using namespace std;
int rect[1024][1024];

void setNum(int size,int x,int y){  // size是正方形大小，x，y为左上角座标
    if(size == 2){  // 递归边界
        rect[x][y] = 0;
        return;
    }
    for (int i = x; i < size/2+x; ++i)
        for (int j = y; j < size/2+y; ++j)
            rect[i][j] = 0;
    setNum(size/2,x+size/2,y);  // 右上
    setNum(size/2,x,y+size/2);  // 右下
    setNum(size/2,x+size/2,y+size/2);  // 右下
}

int main() {
    int n;
    cin >> n;
    n = (int) pow(2,n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rect[i][j] = 1;
        }
    }
    setNum(n,0,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ",rect[i][j]);
        }
        printf("\n");
    }
    return 0;
}
