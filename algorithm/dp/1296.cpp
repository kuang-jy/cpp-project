#include <iostream>
using namespace std;
int t,n,k,pos[110],v[110],dp[1000010];
//dp定义：dp[i]表示前i个位置开餐馆的最大收益

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i = 1;i <= n;i++) scanf("%d",&pos[i]);
        for(int i = 1;i <= n;i++) scanf("%d",&v[i]);
        dp[1] = v[1];
        int ans = dp[1];
        for(int i = 2;i <= n;i++){  //枚举餐馆
            dp[i] = v[i];    //默认开在当前位置收益最大
            for(int j = 1;j < i;j++)  //在当前餐馆前的餐馆
                if(pos[i]-pos[j] > k)
                    dp[i] = max(dp[i],dp[j]+v[i]);   //状态转移
            ans = max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}