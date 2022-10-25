#include <iostream>
using namespace std;
int n,k,arr[11][16],dp[11][16],ans[11][16];

void traceback(int x,int y){
    if(x == 1) {
        printf("%d %d\n",x,ans[x][y]);
        return;
    }
    traceback(x-1,y-ans[x][y]);
    printf("%d %d\n",x,ans[x][y]);
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= k;j++)
            cin >> arr[i][j];
    for(int i = 1;i <= n;i++)  //第几个公司
        for(int j = 1;j <= k;j++)   //当前设备数量
            for(int l = 0;l <= j;l++)   //前i-1个公司分到了几台
                if(dp[i][j] < dp[i-1][l] + arr[i][j-l]){
                    dp[i][j] = dp[i-1][l] + arr[i][j-l];
                    ans[i][j] = j-l;   //记录第i个公司在共有j个设备时分到了几台设备
                }
    printf("%d\n",dp[n][k]);
    traceback(n,k);
    return 0;
}