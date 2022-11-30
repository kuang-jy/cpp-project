#include <iostream>
#include <cstring>
using namespace std;
string s1,s2;
int ans,dp[210][210];

int main(){
    while(cin >> s1 >> s2){
        memset(dp,0,sizeof(dp));
        ans = 0;
        int n = s1.length(),m = s2.length();
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                ans = max(ans,dp[i][j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}