#include <iostream>
using namespace std;
int n,arr[110][110],dp[110][110],ans;

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
            scanf("%d",&arr[i][j]);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= i;j++)
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + arr[i][j];
    for(int i =1;i <= n;i++)
        ans = ans > dp[n][i] ? ans : dp[n][i];
    printf("%d\n",ans);
    return 0;
}