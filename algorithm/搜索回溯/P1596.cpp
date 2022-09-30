#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
char a[101][101];
//位置增量 
const int dx[] = {-1,-1,-1,1,1,1,0,0};
const int dy[] = {-1,0,1,-1,0,1,-1,1};

bool check(int x,int y){
	if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}

void dfs(int x,int y){   //沿着一个方向搜到底，走不下去了换方向，这样可以将所有连通的水塘变成陆地 
	a[x][y] = '.';   //变成陆地 
	for(int i = 0;i < 8;i++){   //8个方向搜索 
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(check(nx,ny) && a[nx][ny] == 'W')   //如果可达 并且 是水塘那就继续搜 
			dfs(nx,ny);
	}
}

int main(){
	cin >> n >> m;
	for(int i =1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> a[i][j];
	
	for(int i =1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(a[i][j] == 'W'){
				dfs(i,j);
				cnt++;
			}
	cout << cnt;
	return 0;
}

