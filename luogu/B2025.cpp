//
// Created by Kjoye on 2022/4/19.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 2-i; j > 0; --j) {
            printf("%s"," ");
        }
        for (int j = 1+2*i; j > 0; --j) {
            printf("%c",'*');
        }
        printf("\n");
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = i+1; j > 0; --j) {
            printf("%s"," ");
        }
        for (int j = 3-2*i; j > 0; --j) {
            printf("%c",'*');
        }
        printf("\n");
    }
    return 0;
}
