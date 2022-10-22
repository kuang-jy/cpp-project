#include <iostream>
using namespace std;
int r,dp[1010][1010],mp[1000][1000],ans = 0;

int main(int argc, char const *argv[])
{
    cin >> r;
    for(int i = 0;i < r;i++)
        for(int j = 0;j <= i;j++)
            cin >> mp[i][j];
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= i;j++){
            if(i == 1 && j == 1) {dp[1][1] = mp[0][0];continue;}
            else dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + mp[i-1][j-1];
            ans = max(ans,dp[i][j]);
        }
    cout << ans;
    return 0;
}
