#include <iostream>
using namespace std;
int k = 0,arr[1010],dp[1010],dp1[1010],maxn,minn;

int main(int argc, char const *argv[])
{
    while(cin >> arr[++k]);
    k--;
    dp[1] = 1;dp1[1] = 1;
    for(int i = 2;i <= k;i++){
        dp[i] = 1;dp1[i] = 1;
        for(int j = i-1;j >= 1;j--){
            if(arr[j] >= arr[i] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            if(arr[j] < arr[i] && dp1[i] < dp1[j]+1) dp1[i] = dp1[j]+1;
        }
        minn = dp1[i] > minn ? dp1[i] : minn;
        maxn = dp[i] > maxn ? dp[i] : maxn;
    }
    printf("%d\n%d",maxn,minn);
    return 0;
}
