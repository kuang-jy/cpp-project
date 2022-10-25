#include <iostream>
using namespace std;
int k,n,m,x,y,vis[11][11],ans;
const int dx[8] = {1,1,2,2,-1,-1,-2,-2},dy[8] = {2,-2,1,-1,2,-2,1,-1};

void dfs(int x,int y,int step){
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y] == 1) return;
    if(step == n*m){
        ans++;
        return;
    }
    vis[x][y] = 1;
    for(int i = 0;i < 8;i++)
        dfs(x+dx[i],y+dy[i],step+1);
    vis[x][y] = 0;
}

int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d %d %d %d",&n,&m,&x,&y);
        ans = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                vis[i][j] = 0;
        dfs(x,y,1);
        printf("%d\n",ans);
    }
    return 0;
}