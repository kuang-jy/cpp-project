#include <iostream>
#include <cstring>
using namespace std;
int dis[1010][1010],x1,x2,y1,y2,n,vis[1010][1010];
const int dx[] = {0,0,1,-1},dy[] = {-1,1,0,0};

struct node{
	int x,y,step;
}que[1000010];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		string row;
		cin >> row;
		for(int k = 1;k <= n;k++)
			dis[i][k] = row[k-1]-'0';
	}
	cin >> x1 >> y1 >> x2 >> y2;
	//广度优先遍历 
	int rear = -1,front = -1;
	que[++rear].step = 0;
	que[rear].x = x1;
	que[rear].y = y1;
	vis[x1][y1] = 1;
	while(front < rear){
		node a = que[++front];
		for(int i = 0;i < 4;i++){
			int nx = a.x +dx[i],ny = a.y + dy[i];
			if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && !vis[nx][ny] && !dis[nx][ny]){
				que[++rear].step = a.step+1;
				que[rear].x = nx;
				que[rear].y = ny;
				vis[nx][ny] = 1;
				if(nx == x2 && ny == y2) {
					cout << que[rear].step;
					return 0;
				}
			}
		}
	}
	return 0;
}

