#include <bits/stdc++.h>
using namespace std;
int w,h,s,e,ans;
char a[21][21],ch;
const int dx[] = {-1,1,0,0},dy[] = {0,0,1,-1};

void dfs(int x,int y){
	a[x][y] = '#';
	ans++;
	for(int i = 0;i < 4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && ny >= 1 && nx <= h && ny <= w && a[nx][ny] == '.') dfs(nx,ny);
	}
}

int main(){
	cin >> w>>h;
	for(int i = 1;i <= h;i++)
		for(int j = 1;j <= w;j++){
			cin >> ch;
			if(ch == '@') {s = i;e = j;}  //¼ÇÂ¼¿ªÊ¼ 
			a[i][j] = ch;
		}
	dfs(s,e);
	cout << ans ;
	return 0;
}

