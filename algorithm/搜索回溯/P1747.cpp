#include <iostream>
#include <string.h>
using namespace std;
int x1,x2,y1,y2;
int vis[401][401];
const int dx[] = {1,1,-1,-1,2,2,-2,-2,2,-2,2,-2},dy[] = {2,-2,2,-2,1,-1,1,-1,2,-2,-2,2};   //12��λ������ 

typedef struct node{   //���н�� 
	int x,y,step;
}node;

int solve(int x,int y){   //������ȱ��� 
	node que[100000];
	int rear = -1,front = -1;
	que[++rear].x = x;
	que[rear].y = y;  //������
	que[rear].step = 0;
	while(front < rear){
		node a = que[++front];
		for(int i = 0;i < 12;i++){
			int nx = a.x+dx[i];
			int ny = a.y+dy[i];
			if(nx >= 1 && ny >= 1 && !vis[nx][ny]){
				que[++rear].x = nx;
				que[rear].y = ny;
				que[rear].step = a.step+1;
				vis[nx][ny] = 1;   //��Ƿ��� 
				if(nx == 1 && ny == 1) return que[rear].step;
			}
		}
	}
}

int main(){
	cin >> x1 >> y1 >> x2 >> y2;
	cout << solve(x1,y1) << endl;
	memset(vis,0,sizeof(vis));   //ע�����vis���� 
	cout << solve(x2,y2) << endl;
	return 0;
}

