#include <iostream>
using namespace std;
#define MOD 1000007
int n,m,num[101],dp[101];   //dp[i][j] 表示第i盆花为止 放j盆 的摆法
//0-1背包优化，压缩为一维数组

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&num[i]);
	dp[0] = 1;
	for(int i = 1;i <= n;i++)  //枚举每盆花
		for(int j = m;j >= 1;j--)  //枚举摆放盆数
			for(int k = 1;k <= min(num[i],j);k++)  //枚举当前花的数量，前缀和
				dp[j] = (dp[j] + dp[j-k]) % MOD;
	printf("%d\n",dp[m]);
	return 0;
}






// #include <bits/stdc++.h>
// using namespace std;
// #define N 101
// const int mod = 1e6+7;
// //dp数组定义，dp[i][j] 表示前i种花共可放j盆的方案数
// int dp[N][N],m,n,a[N]; 
// int main(){
// 	cin >> n >> m;
// 	for(int i = 1;i <= n;i++) cin >> a[i];
// 	dp[0][0] = 1;   //没有花，且最多放0盆的时候可以确认方案数为1	
// 	for(int i = 1;i <= n;i++){   //遍历每种花 
// 		for(int j = 0;j <= m;j++){  //遍历所有可放数量 
// 			for(int k = 0;k <= a[i];k++){   //遍历当前种花可放数量 
// 				if(k <= j)
// 					dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;   //前i盆花在最多可放j盆时，遍历所有可放的情况并累加 
// 			}
// 		}
// 	} 
// 	cout << dp[n][m];
// 	return 0;
// }

