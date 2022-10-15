#include <bits/stdc++.h>
using namespace std;
int n,m,dp[101][101],a[101][101],ans;

int main(){
	cin >> n >> m;
	for(int i = 1;i < n;i++)
		for(int j = 1;j <= m;j++)
			cin >> a[i][j];
	//dp数组定义：dp[i][j]表示以i，j作为正方形右下角的最大边长
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(a[i][j] == 1){
				dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
				ans = ans > dp[i][j] ? ans : dp[i][j];
			} 
	cout << ans;
	return 0;
}

