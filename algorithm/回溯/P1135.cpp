#include <bits/stdc++.h>
using namespace std;
int n,a,b,arr[201];
const int x[2] = {-1,1};
int que[201],vis[201],lowcost[201];

bool check(int floor){
	if(floor >= 1 && floor <= n) return true;
	return false;
}

void bfs(){
	int front = -1,rear = -1;
	que[++rear] = a;  //起点层入队
	vis[a] = 1;  //标记访问
	lowcost[a] = 0;
	int num;
	while(front < rear){  //队列非空 
		num = que[++front];  //队头出队
		if(num == b) break; 
		if(check(num+x[0]*arr[num]) && !vis[num+x[0]*arr[num]]){  //可以下 
			que[++rear] = num+x[0]*arr[num];
			vis[num+x[0]*arr[num]] = 1;
			lowcost[num+x[0]*arr[num]] = lowcost[num]+1;
		}
		if(check(num+x[1]*arr[num]) && !vis[num+x[1]*arr[num]]){  //可以上 
			que[++rear] = num+x[1]*arr[num];
			vis[num+x[1]*arr[num]] = 1;
			lowcost[num+x[1]*arr[num]] = lowcost[num]+1;
		}
	}
	cout << lowcost[b] ; 
}

int main(){
	cin >> n>>a>>b;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		lowcost[i] = -1;
	}
	bfs();
	return 0;
}

