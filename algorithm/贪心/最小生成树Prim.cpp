#include <bits/stdc++.h>
using namespace std;

/*
	prim步骤：
		每次都选择一个代价最小的顶点，并且要保证选完点还是一棵树，直到连通
	 
*/
#define maxSize 20
#define INF 1000

typedef struct VexNode{
	int no;
}VexNode;

typedef struct MGraph{
	int edges[maxSize][maxSize];  //每条边的权 
	int v,e;  //点数，边数 
	VexNode vex[maxSize];  //每个顶点 
}MGraph;

int edgesW[5][5] =     
{    
	INF,5,1,2,INF,
	5,INF,3,INF,4,
	1,3,INF,6,2,
	2,INF,6,INF,3,
	INF,4,2,3,INF
};

void prim(MGraph g,int v,int& sum){  //v为初始结点，sum用于记录最小生成树权值 
	int flag[maxSize],lowcost[maxSize];  //标记结点是否已添加，记录已添加结点对剩余结点的最小值
	
	for(int i = 0;i < g.v;i++){   //初始化flag，lowcost数组 
		lowcost[i] = g.edges[v][i];   
		flag[i] = 0;  //未加入树中 
	} 
	flag[v] = 1;  //将初始结点加入树中
	
	int temp;  //遍历时用 
	for(int i = 0;i < g.v-1;i++){  //控制选点次数，因为初始结点已经在树中 
		int min = INF;   //初始化一次选点的最小值
		for(int j = 0;j < g.v;j++){
			if(!flag[j] && min > lowcost[j]){
				min = lowcost[j];
				temp = j;
			}
		}
		flag[temp] = 1;  //将距离最短结点加入树中
		sum+=min;
		for(int j = 0;j < g.v;j++){   //更新lowcost数组 
			if(!flag[j] && lowcost[j] > g.edges[temp][j]) 
				lowcost[j] = g.edges[temp][j];
		} 
	} 
}

int main(){
	MGraph g;
	g.e = 8;
	g.v = 5;
	for(int i = 0;i < 5;i++)
		for(int j = 0;j < 5;j++)
			g.edges[i][j] = edgesW[i][j];
	int sum = 0;
	prim(g,0,sum);
	cout << sum << endl;
	return 0;
}
