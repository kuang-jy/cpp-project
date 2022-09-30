#include <bits/stdc++.h>
using namespace std;

//dp定义 dp[i]表示以i结尾能得到的最大数量
//最后一个地窖是没有通向别的地窖的路的，所以从最后一个地窖开始向前逆推，初始化dp[n]=num[n] 
//状态转移：dp[i] = max{dp[j]}+num[i]; 
//最后遍历dp数组找到最大地雷数 
int dp[21],link[21][21],n,num[21],path[21],ans,pos;

void dfs(int i){
	if(!i) return;
	dfs(path[i]);
	cout << i << " ";
	
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		dp[i] = num[i];   //顺便初始化dp数组 
	}

	for(int i = 1; i <= n-1;i++)
		for(int j = i+1;j <= n;j++)
			cin >> link[i][j];
			
	for(int i = 2;i <= n;i++){    //所有终点可能 
		for(int j = 1;j < i;j++){
			if(link[j][i] && dp[i] < dp[j]+num[i]){   //如果两点联通，且从j挖到i可得到更大数量，那么更新dp，并记录路径 
				dp[i] = dp[j]+num[i];
				path[i] = j;
			}
		}
		if(ans < dp[i]){    //更新答案 
			ans = dp[i];
			pos = i;   //记录最大的结尾 
		}
	}
	dfs(pos);
	cout << endl << ans;
	return 0;
}
