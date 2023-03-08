#include <iostream>
using namespace std;
int v,n,arr[33],dp[20010];

int main(){
    scanf("%d%d",&v,&n);
    for(int i = 1;i <= n;i++) scanf("%d",&arr[i]);
    for(int i = 1;i <= n;i++)
        for(int j = v;j >= arr[i];j--)
            dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
    printf("%d\n",v-dp[v]);
    return 0;
}