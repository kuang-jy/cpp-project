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
	que[++rear] = a;  //�������
	vis[a] = 1;  //��Ƿ���
	lowcost[a] = 0;
	int num;
	while(front < rear){  //���зǿ� 
		num = que[++front];  //��ͷ����
		if(num == b) break; 
		if(check(num+x[0]*arr[num]) && !vis[num+x[0]*arr[num]]){  //������ 
			que[++rear] = num+x[0]*arr[num];
			vis[num+x[0]*arr[num]] = 1;
			lowcost[num+x[0]*arr[num]] = lowcost[num]+1;
		}
		if(check(num+x[1]*arr[num]) && !vis[num+x[1]*arr[num]]){  //������ 
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

