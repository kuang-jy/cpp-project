#include <bits/stdc++.h>
using namespace std;
#define N 201
int dis[N][N],dp[N],n;

int main(){
	cin >> n;
	for(int i = 1;i < n;i++){
		for(int j = i+1;j <= n;j++)
			cin >> dis[i][j];
	}	
	for(int i = 1;i <= n;i++) dp[i] = dis[1][i];
	//dp数组定义，dp[i]表示从1到i的最小花费 
	for(int i = 2;i <= n;i++){   //遍历从2到n的所有情况 
		for(int j = i-1; j >= 1;j--){    //假设n为3，那么当前状态是从1直接到3 （1-3），或者在2中转1-2-3 
			dp[i] = min(dp[i],dp[j]+dis[j][i]);
		}
	} 
	cout << dp[n] << endl;
	return 0;
}

