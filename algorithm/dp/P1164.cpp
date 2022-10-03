#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],dp[101][10001];
int main(){
	cin >> n>>m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 0;i <= n;i++) dp[i][0] = 1;   //一块钱也没有的话，只有一种方案 
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= m;j++)
			if(j >= a[i]) dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i]];
			else dp[i][j] = dp[i-1][j];
	cout << dp[n][m] << endl;
	return 0;
}

