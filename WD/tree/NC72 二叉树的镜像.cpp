#include <iostream>
using namespace std;
int m,n,w[31],v[31],dp[202];

int main(){
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= n;i++) scanf("%d %d",&w[i],&v[i]);
    for(int i = 1;i <= n;i++)
        for(int j = w[i];j <= m;j++)
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
    printf("max=%d\n",dp[m]);
    return 0;
}