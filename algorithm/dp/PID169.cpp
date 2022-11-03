#include <iostream>
#include <cstring>
using namespace std;
int n,dp[110];

int main(){
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i <= 10;i++) scanf("%d",&dp[i]);
    scanf("%d",&n);
    dp[0] = 0;
    for(int i = 2;i <= n ;i++)
        for(int j = 0;j < i;j++)
            dp[i] = min(dp[i],dp[j]+dp[i-j]);
    printf("%d\n",dp[n]);
    return 0;
}