#include <bits/stdc++.h>
using namespace std;
int a[1001][1001],dp[1001][1001],ans,r;

int main(){
	cin >> r;
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= i;j++)
			cin >> a[i][j];
	dp[1][1] = a[1][1];
	//dp[][]定义： dp[i][j]表示从起点到i行j列的最长路程
	//那么dp[i][j] = max {dp[i-1][j],d[i-1][j-1]} + a[i][j]
	int m = 0;
	for(int i = 2;i<=r;i++)
		for(int j = 1;j <= i;j++){
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
			m = m > dp[i][j] ? m:dp[i][j];
		}
	cout << m;
	return 0;
}

