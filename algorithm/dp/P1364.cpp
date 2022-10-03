#include <bits/stdc++.h>
using namespace std;
int n,dis[101][101],popu[101];
/*
	佛洛依德算法模板题 
*/
int main(){
	cin >>n;
	for(int i=1; i<=n; i++) {   //数据初始化 
		for(int j=1; j<=n; j++) {
			dis[i][j]=1000000;
		}
	}
	
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
		cin >> popu[i];
		int a,b;
		cin >> a>>b ;
		dis[i][a] = dis[a][i] = 1;
		dis[i][b] = dis[b][i] = 1;
	}
	
	for(int i = 1;i <= n;i++){   //遍历中转节点 
		for(int j = 1;j <= n;j++){  //遍历起点 
			if(i != j){    //不要在起点中转 
				for(int k = 1;k <= n;k++){  //遍历终点 
					//起点不等于终点，且不在终点中转 
					if(k != j && k != i) dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
				}
			}
		}	
	}
	
	int ans = 1000000,cnt;
	for(int i = 1;i <= n;i++){   //遍历所有设置医院的情况 
		cnt = 0;
		for(int j = 1;j <= n;j++){   //计算每个城镇居民路程之和 
			if(i != j) cnt += popu[j]*dis[i][j];
		}
		ans = min(ans,cnt);
	}
	cout << ans;
	return 0;
}

