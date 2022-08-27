#include <bits/stdc++.h>
using namespace std;

/*
	��һ����Ȩ����ͼ���ҳ��Ӷ���i��ʼ������������������·������
	
	���㼯��s[]����ǰ��Щ�����Ѿ�ѡ�ˣ�0/1�� 
	��������dist[]���ڵ�ǰ��s[]�£���������������·�� 
*/

#define maxSize 20
#define INF 1000

typedef struct VexNode{  //���� 
	int no;
}VexNode;

typedef struct MGraph{
	int edges[maxSize][maxSize];
	int v,e;
	VexNode vex[maxSize];
}MGraph;

int edgeW[5][5]=
{
	INF,10,INF,30,100,
	INF,INF,50,INF,INF,
	INF,INF,INF,INF,10,
	INF,INF,20,INF,60,
	INF,INF,INF,INF,INF
};

void dijkstra(MGraph g,int v,int dist[],int path[]){
	int s[maxSize];
	for(int i = 0;i < g.v;i++){
		s[i] = 0;
		dist[i] = g.edges[v][i];
		if(dist[i] != INF) path[i] = v;
		else path[i] = -1;
	}
	s[v] = 1;
	
	int temp;
	for(int i = 0;i < g.v-1;i++){   //����ѡ����� 
		int min = INF;
		for(int j = 0;j < g.v;j++){
			if(!s[j] && dist[j] < min){
				min = dist[j];
				temp = j;	
			}
		}
		s[temp] = 1;
		
		for(int j = 0;j < g.v;j++){
			if(!s[j] && dist[j] > dist[temp]+g.edges[temp][j]){
				dist[j] = dist[temp]+g.edges[temp][j];
				path[j] = temp;   //����·�� 
			}
		}
	}
}

void traceBack(int path[],int i,int j){
	if(j == -1) return;
	traceBack(path,i,path[j]);
	cout << j+1 << "->";
}

int main(){
	MGraph g;
	g.e = 7;
	g.v = 5;
	int dist[maxSize],path[maxSize];
	for(int i = 0;i < 5;i++)
		for(int j = 0;j < 5;j++)
			g.edges[i][j] = edgeW[i][j];
			
	dijkstra(g,0,dist,path);
	traceBack(path,0,4);
	return 0;
}

