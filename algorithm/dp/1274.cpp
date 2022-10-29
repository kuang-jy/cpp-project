#include <iostream>
using namespace std;
int n,arr[110],dp[110][110],s[110];  //s记录前缀和，用于求出区间和

int main(){
    scanf("%d",&n);
    for(int i =1;i <= n;i++) {
        scanf("%d",&arr[i]);
        s[i] = s[i-1]+arr[i];
        dp[i][i] = 0;
    }
    for(int i = 2;i <= n;i++){  //枚举问题规模
        for(int j = 1;j <= n-i+1;j++){  //枚举区间起点
            int t = j+i-1;  //区间终点
            dp[j][t] = dp[j][j] + dp[j+1][t] + s[t] - s[j-1];   //默认在起点位置断开
            for(int k = j+1;k < t;k++){  //区间断开点
                dp[j][t] = min(dp[j][t],dp[j][k]+dp[k+1][t]+s[t]-s[j-1]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}