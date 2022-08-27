#include <bits/stdc++.h>
using namespace std;

/*
	Kruskal步骤：（使用并查集） 
		每次选择代价最小的边，保证没有环出现，直到森林变成一棵树 
		1、将所有边递增排序
		2、依次选择最小的边，若和已经选择的边不构成环，那就保留这条边
		3、重复2，直到所有点都被连接 
*/ 
#define maxSize 20
#define INF 1000

typedef struct VexNode{   //顶点 
	int no;
}VexNode;

typedef struct MGraph{
	int edges[maxSize][maxSize];
	int v,e;
	VexNode vex[maxSize];
}MGraph;

int edgesW[5][5] =     
{    
	INF,5,1,2,INF,
	5,INF,3,INF,4,
	1,3,INF,6,2,
	2,INF,6,INF,3,
	INF,4,2,3,INF
};

typedef struct edgeA{   //边 
	int a,b,w;   //a和b之间有一条权重为w的边 
}edgeA;

edgeA edgex[maxSize];
int u[maxSize];  //并查集 

int find(int n){  //找到根节点 
	while(n != u[n]) n = u[n];
	return n;
}

//快排 
int partition(edgeA arr[],int low,int high){
	edgeA pivot = arr[low];   //选取枢轴 
	while(low < high){
		while(low < high && arr[high].w >= pivot.w) high--;
		arr[low] = arr[high];
		while(low < high && arr[low].w <= pivot.w) low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void quickSort(edgeA arr[],int low,int high){
	if(low >= high) return;
	int pivot = partition(arr,low,high);
	quickSort(arr,low,pivot-1);
	quickSort(arr,pivot+1,high);
}

void kruskal(MGraph g, edgeA arr[],int& sum){
	for(int i = 0;i < g.v;i++) u[i] = i;   //初始化并查集
	quickSort(arr,0,g.e-1);   //排序 
	for(int i = 0;i < g.e;i++) cout << arr[i].w << endl; 
	for(int i = 0;i < g.e;i++){  //遍历所有的边 
		int a = find(arr[i].a);   //找到当前边的两端结点的父结点 
		int b = find(arr[i].b);
		if(a!=b){		//如果两个父节点不一样 
			u[a] = b;  //更新并查集 
			sum += arr[i].w;   //计算sum 
		}
	} 
}

int main(){
	MGraph g;
	g.e = 8;
	g.v = 5;
	int sum = 0,k = 0;
	for(int i = 0;i < 5;i++)
		for(int j = 0;j < 5;j++)
			g.edges[i][j] = edgesW[i][j];
			
	for(int i = 0;i < 5;i++)
		for(int j = i+1;j < 5;j++)
			if(edgesW[i][j] != INF){
			edgex[k].a = i;
			edgex[k].b = j;
			edgex[k].w = edgesW[i][j];
			k++;
		}
	kruskal(g,edgex,sum);
	cout << sum << endl;
	return 0;
}

