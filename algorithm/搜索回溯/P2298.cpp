#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d;
char ch,dis[2001][2001];
const int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};  //Î»ÖÃÔöÁ¿ 

struct node{
	int x,y,step;
}que[4000010];

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			cin >> ch;
			if(ch == 'm'){
				a = i;b = j;
			}
			if(ch == 'd'){
				c = i;d = j;
			}
			dis[i][j] = ch;
		}
		
	int front = -1, rear = -1;
	que[++rear].step = 0;
	que[rear].x = a;
	que[rear].y = b;
	dis[a][b] = '#';
	while(front < rear){
		node pos = que[++front];
		for(int i = 0;i < 4;i++){
			int nx = pos.x+dx[i],ny = pos.y+dy[i];
			if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && dis[nx][ny] != '#'){
				que[++rear].step = pos.step+1;
				que[rear].x = nx;
				que[rear].y = ny;
				dis[nx][ny] = '#';
				if(nx == c && ny == d){
					cout << que[rear].step <<endl;
					return 0;
				}
			}
		}
	}
	cout <<"No Way!"<<endl;
	return 0;
}

