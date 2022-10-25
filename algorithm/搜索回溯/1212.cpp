#include <iostream>
using namespace std;
int r,c,vis[30],used[25][25],ans;
char mp[25][25];

void dfs(int x,int y,int step){
    if(x <= 0 || y <= 0 || x > r || y > c || vis[mp[x][y] - 'A'] == 1 || used[x][y] == 1) return;
    vis[mp[x][y] - 'A'] = 1;
    used[x][y] = 1;
    ans++;
    dfs(x+1,y,step+1);
    dfs(x-1,y,step+1);
    dfs(x,y+1,step+1);
    dfs(x,y-1,step+1);
    vis[mp[x][y] - 'A'] = 0;
    used[x][y] = 0;
}

int main(){
    scanf("%d %d",&r,&c);
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++)
            cin >> mp[i][j];
    dfs(1,1,1);
    printf("%d",ans);
}