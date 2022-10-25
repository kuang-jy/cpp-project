#include <iostream>
using namespace std;
int n,arr[1010],dp[1010],ans;

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    for(int i = 1;i <= n;i++){
        dp[i] = 1;
        for(int j = 1;j < i;j++)
            if(arr[i-1] > arr[j-1]) dp[i] = max(dp[j]+1,dp[i]);
    ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}