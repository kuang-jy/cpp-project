#include <bits/stdc++.h>
using namespace std;
int n,m,arr[1001][1001],vis[1001][1001],x,y,ans[100010];
char ch;
const int dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};

bool check(int a,int b,int s,int e){
	if(vis[a][b] != -1) return false;
	if(a >= 1 && b >= 1 && a <= n && b <= n){
		if(arr[s][e] == 1 && arr[a][b] == 0) return true;
		if(arr[s][e] == 0 && arr[a][b] == 1) return true;
	}
	return false;
}

void dfs(int s,int e,int ask){
	vis[s][e] = ask;
	for(int i = 0;i < 4;i++){
		int nx = s+dx[i];
		int ny = e+dy[i];
		if(check(nx,ny,s,e)){
			ans[ask]++;
			dfs(nx,ny,ask);
		} 
	}
}

int main(){
	memset(vis,-1,sizeof(vis));
	cin >> n>> m;
	for(int i = 1;i <= m;i++) ans[i] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			cin >> ch;
			arr[i][j] = ch-'0';
		}
	for(int i = 1;i <= m;i++){
		cin >> x >> y;
		if(vis[x][y] == -1)
			dfs(x,y,i);
		else ans[i] = ans[vis[x][y]]; 
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << endl;
	return 0;
}

