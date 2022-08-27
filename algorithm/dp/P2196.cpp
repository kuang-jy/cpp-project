#include <bits/stdc++.h>
using namespace std;

//dp定义 dp[i]表示以i结尾能得到的最大数量
//最后一个地窖是没有通向别的地窖的路的，所以从最后一个地窖开始向前逆推，初始化dp[n]=num[n] 
//状态转移：dp[i] = max{dp[j]}+num[i]; 
//最后遍历dp数组找到最大地雷数 
int dp[21],link[21][21],n,num[21],path[21];

void dfs(int i){
	if(!i) return;
	cout << i << " ";
	dfs(path[i]);
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		dp[i] = num[i];
	}

	for(int i = 1; i <= n-1;i++)
		for(int j = i+1;j <= n;j++)
			cin >> link[i][j];
			
	for(int i = n-1;i >= 1;i--){
		int f = 0,pre = 0;  //f记录可达地窖的最多地雷数，pre记录路径 
		for(int j = i+1;j <= n;j++){
			if(link[i][j] && dp[j] > f) {
				f = dp[j];
				pre = j;
			}
		}
		dp[i] = f+num[i];
		path[i] = pre;
	}
	
	int max = 1;
	for(int i = 2;i <=n;i++)
		if(dp[max] < dp[i])
			max = i;
	dfs(max);
	cout << dp[max] << endl;
	return 0;
}
