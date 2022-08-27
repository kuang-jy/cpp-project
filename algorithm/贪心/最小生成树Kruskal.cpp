#include <bits/stdc++.h>
using namespace std;

/*
	Kruskal���裺��ʹ�ò��鼯�� 
		ÿ��ѡ�������С�ıߣ���֤û�л����֣�ֱ��ɭ�ֱ��һ���� 
		1�������бߵ�������
		2������ѡ����С�ıߣ������Ѿ�ѡ��ı߲����ɻ����Ǿͱ���������
		3���ظ�2��ֱ�����е㶼������ 
*/ 
#define maxSize 20
#define INF 1000

typedef struct VexNode{   //���� 
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

typedef struct edgeA{   //�� 
	int a,b,w;   //a��b֮����һ��Ȩ��Ϊw�ı� 
}edgeA;

edgeA edgex[maxSize];
int u[maxSize];  //���鼯 

int find(int n){  //�ҵ����ڵ� 
	while(n != u[n]) n = u[n];
	return n;
}

//���� 
int partition(edgeA arr[],int low,int high){
	edgeA pivot = arr[low];   //ѡȡ���� 
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
	for(int i = 0;i < g.v;i++) u[i] = i;   //��ʼ�����鼯
	quickSort(arr,0,g.e-1);   //���� 
	for(int i = 0;i < g.e;i++) cout << arr[i].w << endl; 
	for(int i = 0;i < g.e;i++){  //�������еı� 
		int a = find(arr[i].a);   //�ҵ���ǰ�ߵ����˽��ĸ���� 
		int b = find(arr[i].b);
		if(a!=b){		//����������ڵ㲻һ�� 
			u[a] = b;  //���²��鼯 
			sum += arr[i].w;   //����sum 
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

