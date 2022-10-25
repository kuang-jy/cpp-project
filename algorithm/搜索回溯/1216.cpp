#include <iostream>
using namespace std;
int r,c,x,y,ans;
char mp[22][22];

void dfs(int nx,int ny){
    if(nx <= 0 || ny <= 0 || nx > r || ny > c || mp[nx][ny] == '#') return;
    ans++;
    mp[nx][ny] = '#';
    dfs(nx+1,ny);
    dfs(nx-1,ny);
    dfs(nx,ny+1);
    dfs(nx,ny-1);
}

int main(){
    scanf("%d %d",&c,&r);
    while(c && r){
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++){
                cin >> mp[i][j];
                if(mp[i][j] == '@'){
                    x = i;y = j;
                }
            }
        ans = 0;
        dfs(x,y);
        printf("%d\n",ans);
        scanf("%d %d",&c,&r);
    }
    return 0;
}