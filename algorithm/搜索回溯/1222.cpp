#include <iostream>
using namespace std;
int t, n, k,ans;

void dfs(int i,int sum,int pre){
    if(i > k+1 || sum > n) return;
    if(sum == n && i == k+1){
        ans++;
        return;
    }
    for(int j = pre;j <= n;j++)
        dfs(i+1,sum+j,j);
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        ans = 0;
        dfs(1,0,0);
        printf("%d\n",ans);
    }
    return 0;
}