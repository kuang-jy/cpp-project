#include <iostream>
using namespace std;
int n,m,ans;
char arr[1000][1000];

void dfs(int x,int y,int n,int m){
    if(x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == '0') return;
    arr[x][y] = '0';
    dfs(x-1,y,n,m);
    dfs(x+1,y,n,m);
    dfs(x,y-1,n,m);
    dfs(x,y+1,n,m);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] != '0'){
                ans++;
                dfs(i,j,n,m);
            }
    printf("%d\n",ans);
    return 0;
}