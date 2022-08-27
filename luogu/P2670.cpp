//
// Created by Kjoye on 2022/4/21.
//

#include <bits/stdc++.h>

using namespace std;
int arr[105][105];

int main() {
    memset(arr, 0, sizeof(arr));
    int n,m;
    char temp;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> temp;
            if(temp == '*') arr[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] == 1) printf("*");
            else {
                printf("%d", arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i][j - 1] + arr[i][j + 1] +
                             arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
            }
        }
        printf("\n");
    }
    return 0;
}
