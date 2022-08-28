#include <bits/stdc++.h>
using namespace std;
//位置增量 
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};
int n,m,t,sx,sy,fx,fy,block[11][2],vis[6][6],ans;

bool check(int x,int y){
	if(x >= 1 && x <= n && y >= 1 && y <= m) {
		for(int i = 1;i <= t;i++)
			if(x == block[i][0] && y == block[i][1]) return false;
		return true;
	}
	return false;
}

void dfs(int nx,int ny){   //从nx，ny开始走 
	if(nx == fx && ny == fy){
		ans++;
		return;
	}
	for(int k = 0;k < 4;k++){
		int xx = nx+dx[k];
		int yy = ny+dy[k];
		if(check(xx,yy) && !vis[xx][yy]){
			vis[nx][ny] = 1;
			dfs(xx,yy);
			vis[nx][ny] = 0;
		}
	}
}

int main(){
	cin >> n >> m >> t >> sx >> sy >>fx >> fy;
	for(int i = 1;i <= t;i++)
		cin >> block[i][0] >> block[i][1];
	dfs(sx,sy);
	cout <<ans;
	return 0;
}

