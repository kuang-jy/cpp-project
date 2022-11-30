#include <iostream>
#include <cstring>
using namespace std;
int cost[602][602],n,dp[602];

int main(){
	memset(dp,0x3f,sizeof(dp));  //dp初始化极大值
	dp[1] = 0;  //起点租金为零
	scanf("%d",&n);
	for(int i = 1;i < n;i++)
		for(int j = i+1;j <= n;j++)
			scanf("%d",&cost[i][j]);   //读取站点费用
	for(int i = 2;i <= n;i++)   //计算每个站点最少租金
		for(int j = 1;j < i;j++)
			dp[i] = min(dp[i],dp[j]+cost[j][i]);
	printf("%d\n",dp[n]);
	return 0;
}




























// #include <bits/stdc++.h>
// using namespace std;
// #define N 201
// int dis[N][N],dp[N],n;

// int main(){
// 	cin >> n;
// 	for(int i = 1;i < n;i++){
// 		for(int j = i+1;j <= n;j++)
// 			cin >> dis[i][j];
// 	}	
// 	for(int i = 1;i <= n;i++) dp[i] = dis[1][i];
// 	//dp数组定义，dp[i]表示从1到i的最小花费 
// 	for(int i = 2;i <= n;i++){   //遍历从2到n的所有情况 
// 		for(int j = i-1; j >= 1;j--){    //假设n为3，那么当前状态是从1直接到3 （1-3），或者在2中转1-2-3 
// 			dp[i] = min(dp[i],dp[j]+dis[j][i]);
// 		}
// 	} 
// 	cout << dp[n] << endl;
// 	return 0;
// }

