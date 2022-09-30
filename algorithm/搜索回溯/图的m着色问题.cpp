#include <bits/stdc++.h>
using namespace std;

#define maxSize 20
#define INF 1000
int g[maxSize][maxSize];   //邻接矩阵 
int color[maxSize];    //记录每个顶点颜色
int cnt,m,n;  //方案数，m种颜色，n个顶点 

bool check(int num,int i){   //检查第num个顶点的颜色是否可以为i 
	for(int j = 1;j <= n;j++){
		if(g[num][j] == 1 && color[j] == i) return 0;   //邻接并且颜色相同 
	}
	return 1;
}

void GraphColor(int num){   //对第num个点着色 
	if(num > n){    //若已经到达边界，则产生了一组可行解
		for(int i = 1;i <= n;i++)
			cout << color[i] << " ";
		cout << endl;
		cnt++;
		return;
	}
	else{    //判断当前结点颜色 
		for(int i = 1;i <= m;i++){   //遍历所有颜色 
			if(check(num,i)){
				color[num] = i;
				GraphColor(num+1);
			}
		}
	}
}

int main(){
	/*
5 3
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 1
0 1 0 1 0
	*/
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> g[i][j];
	GraphColor(1);
	cout << cnt << endl;
	return 0;
}

