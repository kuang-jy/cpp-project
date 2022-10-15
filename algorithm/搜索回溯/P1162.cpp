#include <bits/stdc++.h>
using namespace std;
int n,a[32][32],vis[32][32];
const int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};

void dfs(int x,int y){
	vis[x][y] = 1;
	for(int i = 0;i < 4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 0 && ny >= 0 && nx <= n+1 && ny <= n+1 && !vis[nx][ny] && !a[nx][ny])
			dfs(nx,ny);
	}
}
 
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> a[i][j];
	dfs(0,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(vis[i][j]) cout << "0 ";
			else if(!vis[i][j] && a[i][j] == 1) cout << "1 ";
			else cout << "2 ";
		}
		cout << endl;
	}
	return 0;
}

