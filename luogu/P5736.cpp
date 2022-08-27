//
// Created by Kjoye on 2022/4/20.
//

#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for (int i = 2; i <= (int)sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int n,temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if(isPrime(temp)) cout << temp << " ";
    }
    return 0;
}
