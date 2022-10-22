#include <iostream>
using namespace std;
int n,seq[201],dp[201],path[201];

void traceBack(int i){
    if(path[i] == i) {
        printf("%d ",seq[i]);
        return;
    }
    traceBack(path[i]);
    printf("%d ",seq[i]);
}

int main(int argc, char const *argv[])
{
    cin >> n;int idx,max;
    for(int i = 1;i <= n;i++) cin >> seq[i];
    dp[0] = 0;path[0] = 0;
    dp[1] = 1;path[1] = 1;
    for(int i = 2;i <= n;i++){
        dp[i] = 1;
        path[i] = i;
        for(int j = i-1;j >= 1;j--){
            if(seq[j] <= seq[i] && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
                path[i] = j;
            }
        }
    }
    max = dp[1];
    idx = 1;
    for(int i = 1;i <= n;i++){
        if(max < dp[i]){
            max = dp[i];
            idx = i;
        }
    }
    printf("max=%d\n",max);
    traceBack(idx);
    return 0;
}
