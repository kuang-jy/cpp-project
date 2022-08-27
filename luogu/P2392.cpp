#include <bits/stdc++.h>
using namespace std;
#define INF 100000
int s[5],a[5][21],ans,mincost=INF,l,r;

void dfs(int n,int i){   //第n个学科的第i门 
	if(i > s[n]){
		mincost = min(mincost,max(l,r));   //是否更新可行解 
		return;
	}
	else{
		l+=a[n][i];  //第i门放左脑 
		dfs(n,i+1);  //搜下一门
		l-=a[n][i];  //左脑回溯
		r+=a[n][i];  //第i门放右脑 
		dfs(n,i+1);  //搜索下一门
		r-=a[n][i];  //右脑回溯 
	}
}

int main(){
	cin >> s[1]>>s[2]>>s[3]>>s[4];
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= s[i];j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= 4;i++){
		dfs(i,1);
		ans += mincost;
		mincost = INF;	
	}
	cout << ans;
	return 0;
}

