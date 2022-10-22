#include <iostream>
using namespace std;
int n,city[5100][2],dp[5100][2],maxn;

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> city[i][0] >> city[i][1];
    dp[1][0] = 0; dp[1][1] = 1;
    maxn = 1;
    int pre = 1;
    for(int i = 2;i <= n;i++){
        if((city[i-1][0] > city[i][0] && city[i-1][1] > city[i][1]) || (city[i-1][0] < city[i][0] && city[i-1][1] < city[i][1])){
            dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + 1;
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        else dp[i][0] = dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
        maxn = max(maxn,dp[i][0]);
        maxn = max(maxn,dp[i][1]);
    }
    printf("%d",maxn);
    return 0;
}
