//
// Created by Kjoye on 2022/4/19.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n % 10;
    int b = n/10 % 10;
    int c = n/100;
    cout << a << b << c << endl;
    return 0;
}
