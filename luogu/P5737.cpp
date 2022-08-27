//
// Created by Kjoye on 2022/4/20.
//

#include <bits/stdc++.h>

using namespace std;

//判断任意年份是否为闰年，需要满足以下条件中的任意一个：
//① 该年份能被 4 整除同时不能被 100 整除；
//② 该年份能被400整除。
bool isYear(int year){
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
    return false;
}

int main() {
    int count,l,r;
    int arr[100000];
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if(isYear(i)) {
            arr[count] = i;
            count++;
        }
    }
    printf("%d\n",count);
    for (int i = 0; i < count; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
