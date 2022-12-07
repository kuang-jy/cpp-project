#include <bits/stdc++.h>
using namespace std;
int n,degrees[10010],times[10010],dp[10010];
vector<int> link[10010];   //记录连接情况 

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int x,t,p;
		scanf("%d %d %d",&x,&t,&p);
		times[x] = t;
		while(p){
			degrees[x]++;   //计算入度 
			link[p].push_back(x);   //记录连接 
			scanf("%d",&p);
		}
	}
	//拓扑排序 + dp
	int que[10010],front = -1,rear = -1;
	for(int i = 1;i <= n;i++)
		if(!degrees[i]){
			que[++rear] = i;  //入度为0点入队
			dp[i] = times[i];  //计算用时 
		}
	while(front < rear){
		int x = que[++front];
		for(int i = 0;i < link[x].size();i++){
			dp[link[x][i]] = max(dp[link[x][i]],dp[x]+times[link[x][i]]);   //更新任务用时 
			if(--degrees[link[x][i]] == 0)   //若入度为零，入队 
				que[++rear] = link[x][i];
		}
	}
	//dp数组最大值就是所需最短时间 
	int ans = dp[1];
	for(int i = 2;i <= n;i++) ans = max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}