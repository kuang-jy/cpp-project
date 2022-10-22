#include <iostream>
#include <string.h>
using namespace std;
int n,mp[1010][1010],dp[1010],path[1010];
const int INF = 0x3f;

void traceBack(int idx){
    if(path[idx] == idx){
        // printf("%d ",idx);
        return;
    }
    traceBack(path[idx]);
    printf("%d ",idx);
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 0;i <= n;i++) path[i] = i;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            cin >> mp[i][j];
            if(mp[i][j] == 0) mp[i][j] = INF;
            if(i == 1) {
                dp[j] = mp[i][j];
                path[j] = i;
            }
        }
    path[1] = 0;
    for(int i = 2;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(mp[j][i] != 0 && dp[j]+mp[j][i] < dp[i]){
                dp[i] = dp[j]+mp[j][i];
                path[i] = j;
            }
    printf("minlong=%d\n",dp[n]);
    traceBack(n);
    return 0;
}
