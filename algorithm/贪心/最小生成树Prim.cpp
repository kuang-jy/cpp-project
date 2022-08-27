#include <bits/stdc++.h>
using namespace std;

/*
	prim���裺
		ÿ�ζ�ѡ��һ��������С�Ķ��㣬����Ҫ��֤ѡ��㻹��һ������ֱ����ͨ
	 
*/
#define maxSize 20
#define INF 1000

typedef struct VexNode{
	int no;
}VexNode;

typedef struct MGraph{
	int edges[maxSize][maxSize];  //ÿ���ߵ�Ȩ 
	int v,e;  //���������� 
	VexNode vex[maxSize];  //ÿ������ 
}MGraph;

int edgesW[5][5] =     
{    
	INF,5,1,2,INF,
	5,INF,3,INF,4,
	1,3,INF,6,2,
	2,INF,6,INF,3,
	INF,4,2,3,INF
};

void prim(MGraph g,int v,int& sum){  //vΪ��ʼ��㣬sum���ڼ�¼��С������Ȩֵ 
	int flag[maxSize],lowcost[maxSize];  //��ǽ���Ƿ�����ӣ���¼����ӽ���ʣ�������Сֵ
	
	for(int i = 0;i < g.v;i++){   //��ʼ��flag��lowcost���� 
		lowcost[i] = g.edges[v][i];   
		flag[i] = 0;  //δ�������� 
	} 
	flag[v] = 1;  //����ʼ����������
	
	int temp;  //����ʱ�� 
	for(int i = 0;i < g.v-1;i++){  //����ѡ���������Ϊ��ʼ����Ѿ������� 
		int min = INF;   //��ʼ��һ��ѡ�����Сֵ
		for(int j = 0;j < g.v;j++){
			if(!flag[j] && min > lowcost[j]){
				min = lowcost[j];
				temp = j;
			}
		}
		flag[temp] = 1;  //��������̽���������
		sum+=min;
		for(int j = 0;j < g.v;j++){   //����lowcost���� 
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
