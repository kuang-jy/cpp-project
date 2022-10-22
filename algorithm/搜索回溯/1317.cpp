#include <iostream>
using namespace std;
int n,r,vis[25];

void dfs(int idx,int ans[],int pre){
    if(idx == r){
        for(int i = 0;i < r;i++) printf("%3d",ans[i]);
        printf("\n");
        return;
    }
    for(int i = 1;i <= n;i++)
        if(!vis[i] && pre < i){
            vis[i] = 1;
            ans[idx] = i;
            dfs(idx+1,ans,i);
            vis[i] = 0;
            ans[idx] = 0;
        }
}

int main(int argc, char const *argv[])
{
    cin >> n >> r;
    int ans[r];
    dfs(0,ans,-1);
    return 0;
}
