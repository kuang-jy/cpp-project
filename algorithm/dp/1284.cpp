#include <iostream>
#include <cstring>
using namespace std;
int t,r,c,mp[110][110],dp[110][110];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                scanf("%d",&mp[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                if(i == 1 && j == 1) dp[i][j] = mp[i][j];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j])+mp[i][j];
        printf("%d\n",dp[r][c]);
    }
    return 0;
}