#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,0,-1,1},dy[] = {1,-1,0,0};
int n,m,a,b,dis[501][501],t[501][501];

struct node{
	int x,y;
}que[250010];

int main(){
	cin >> n>>m >> a>>b;
	int front = -1, rear = -1;
	 
	for(int i = 0;i < a;i++){   //输入感染源 
		rear++;
		cin >> que[rear].x >> que[rear].y;
		dis[que[rear].x][que[rear].y] = 1;  //已感染 
	}
	
	while(front < rear){
		node pos = que[++front];
		for(int i = 0;i < 4;i++){
			int nx = pos.x+dx[i],ny = pos.y+dy[i];
			if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && dis[nx][ny] != 1){
				que[++rear].x = nx;
				que[rear].y = ny;
				dis[nx][ny] = 1;
				t[nx][ny] = t[pos.x][pos.y]+1;
			}
		}
	}
	
	while(b--){
		cin >> n>>m;
		cout << t[n][m] << "\n";
	}
	
	return 0;
}

