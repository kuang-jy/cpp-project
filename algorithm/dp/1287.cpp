#include <iostream>
#include <cstring>
using namespace std;
int n,mp[110][110],dp[110][110];

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            scanf("%d",&mp[i][j]);
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(i == 1 && j == 1) dp[i][j] = mp[i][j];
            else dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + mp[i][j];
    printf("%d\n",dp[n][n]);
    return 0;
}