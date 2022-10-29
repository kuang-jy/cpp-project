#include <iostream>
using namespace std;
int n,m,nums[100000];
long long dp[100000];

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",&nums[i]);
    dp[0] = 1;
    for(int i = 0;i < n;i++)
        for(int j = nums[i];j <= m;j++)
            dp[j] += dp[j-nums[i]];
    printf("%lld\n",dp[m]);
    return 0;
}