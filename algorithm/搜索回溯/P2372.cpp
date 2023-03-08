#include <iostream>
using namespace std;
int m,n,x,y,ans,vis[21][21];
char map[22][22];
const int dx[8] = {1,1,-1,-1,1,-1,0,0},dy[8] = {1,-1,1,-1,0,0,1,-1};  //位置增量

void dfs(int r,int c){
    vis[r][c] = 1;
    for(int i = 0;i < 8;i++){
        int nx = r+dx[i],ny = c+dy[i];
        if(nx > 0 && nx <= m&& ny > 0 && ny <= n && !vis[nx][ny] && map[nx][ny] == 'X') dfs(nx,ny);   //如果这个格子没出界，没被访问过并且显示的是'X'，就访问这个格子
        if(i > 3 && (nx <= 0 || ny <= 0 || nx > m || ny > n || map[nx][ny] != 'X')) ans++;    //如果方向是上下左右，并且出界了或者显示的不是'X'，周长就要+1 
    }
}

int main(){
    scanf("%d%d%d%d",&m,&n,&x,&y);
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= n;j++)
            cin >> map[i][j];
    dfs(x,y);
    printf("%d\n",ans);
    return 0;
}