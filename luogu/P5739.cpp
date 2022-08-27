//
// Created by Kjoye on 2022/4/20.
//

#include <bits/stdc++.h>

using namespace std;

int calNum(int n){
    if(n == 0) return 1;
    return n* calNum(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << calNum(n) << endl;
    return 0;
}
