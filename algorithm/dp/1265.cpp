#include <iostream>
#include <cstring>
using namespace std;
int l1,l2,dp[1010][1010];
string s1,s2;

int main(int argc, char const *argv[])
{
    cin >> s1 >> s2;
    int l1 = s1.length(),l2 = s2.length();
    for(int i = 1;i <= l1;i++)
        for(int j = 1;j <= l2;j++)
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
    printf("%d\n",dp[l1][l2]);
    return 0;
}
