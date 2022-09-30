#include <bits/stdc++.h>
using namespace std;
int m,n,x,y,used[401][401],ans[401][401];
//马的位置增量 
const int dx[] = {-2,-2,2,2,-1,-1,1,1,0};
const int dy[] = {-1,1,-1,1,-2,2,-2,2,0};

typedef struct que{
	int x,y;
}que;
que q[160001];

int check(int a,int b){
	if(a >= 1 && a <= n && b >= 1 && b <= m) return true;
	return false;
}

void bfs(int r,int c){
	int head = -1,tail = -1,lowcost = 0;
	//开始结点入队 
	q[++tail].x = r;
	q[tail].y = c;
	used[r][c] = 1;
	ans[r][c] = 0;
	while(head < tail){   //队列非空 
		head++;  //出队
		lowcost = ans[q[head].x][q[head].y]+1;  //下一结点的最小步数
		for(int i = 0;i < 9;i++){
			int nx = q[head].x+dx[i];
			int ny = q[head].y+dy[i];
			if(check(nx,ny) && !used[nx][ny]){
				q[++tail].x = nx;
				q[tail].y = ny;
				used[nx][ny] = 1;
				ans[nx][ny] = lowcost;
			}
		} 
	}
	
}
int main(){
	cin >> n>>m>>x>>y;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			ans[i][j] = -1;
	bfs(x,y);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			printf("%-5d",ans[i][j]);
		cout << endl;
	}
	return 0;
}

