#include <bits/stdc++.h>
using namespace std;
int n,m,arr[101][101],ans;
const int dx[] = {1,-1,0,0},dy[] = {0,0,-1,1};
char ch;

void dfs(int x,int y){
	arr[x][y] = 0;
	for(int i = 0;i < 4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && arr[nx][ny])
			dfs(nx,ny);
	}
}

int main(){
	cin >>n>>m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			cin >> ch;		
			arr[i][j] = ch - '0';	
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(arr[i][j]){
				ans++;
				dfs(i,j);
			}
	cout << ans;
	return 0;
}

