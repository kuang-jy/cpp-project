#include <iostream>
using namespace std;
int n,arr[1010],dp[1010],ans;

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&arr[i]);
    dp[1] = arr[1];
    ans = dp[1];
    for(int i = 2;i <= n;i++){
        dp[i] = arr[i];
        for(int j = i-1;j >= 1;j--)
            if(arr[j] < arr[i]) dp[i] = max(dp[j]+arr[i],dp[i]);
        ans = ans > dp[i] ? ans : dp[i];
    }
    printf("%d\n",ans);
    return 0;
}