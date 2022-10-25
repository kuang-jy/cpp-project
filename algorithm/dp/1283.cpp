#include <iostream>
using namespace std;
int n,arr[1010],dp[1010],dp1[1010],ans;

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    for(int i = 1;i <= n;i++){
        dp[i] = 1;
        for(int j = 1;j < i;j++)
            if(arr[j-1] < arr[i-1])
                dp[i] = max(dp[j]+1,dp[i]);
    }
    for(int i = n;i >= 1;i--){
        dp1[i] = 1;
        for(int j = n;j > i;j--)
            if(arr[j-1] < arr[i-1])
                dp1[i] = max(dp1[j]+1,dp1[i]);
    }
    for(int i = 1;i <= n;i++)
        ans = max(ans,dp[i]+dp1[i]-1);
    printf("%d\n",ans);
    return 0;
}