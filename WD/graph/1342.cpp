#include <bits/stdc++.h>
using namespace std;
int n,m,p[101][2],vis[101];
double g[101][101],dit[101];

double dist(int xa,int ya,int xb,int yb){
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		dit[i] = 1e9;
		for(int j = 0;j < n;j++)
			g[i][j] = 1e9;
	}
	for(int i = 0;i < n;i++)
		cin >> p[i][0] >> p[i][1];
	cin >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >>a >>b;
		g[a-1][b-1] = g[b-1][a-1] = dist(p[a-1][0],p[a-1][1],p[b-1][0],p[b-1][1]);	
	}
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < n;j++)
//			cout << g[i][j] << " " ;
//		cout << endl;
//	}
	int s,e;
	cin >> s >> e;
	for(int i = 0;i < n;i++){
		if(g[s-1][i] != 0.0) dit[i] = g[s-1][i];
	}
	vis[0] = 1;
//	dit[0] = 0;
	for(int i = 1;i < n;i++){
		int idx = 0;
		for(int j = 0;j < n;j++)
			if(!vis[j] && dit[idx] > dit[j]) idx = j;
//		printf("use:%d\n",idx+1);
		vis[idx] = 1;
		for(int j = 0;j < n;j++)
			if(!vis[j] && dit[j] > dit[idx]+g[idx][j]) dit[j] = dit[idx]+g[idx][j];
	}
	printf("%.2f",dit[e-1]);
	return 0;
}

