#include <iostream>
using namespace std;
int r,dp[1010],tri[1010][1010],ans = -1e7;

int main(){
	cin >> r;
	for(int i = 0;i < r;i++)
		for(int j = 0;j <= i;j++)
			cin >> tri[i][j];
	for(int i = 0;i <= r;i++) dp[i] = -1e7;
	dp[1] = tri[0][0];
	ans = dp[1];
	for(int i = 2;i <= r;i++)
		for(int j = i;j >= 1;j--){
			dp[j] = max(dp[j],dp[j-1])+tri[i-1][j-1];
			ans = max(ans,dp[j]);
		}
	printf("%d",ans);
	return 0;
} 

//int a[1001][1001],dp[1001][1001],ans,r;
//
//int main(){
//	cin >> r;
//	for(int i = 1;i <= r;i++)
//		for(int j = 1;j <= i;j++)
//			cin >> a[i][j];
//	dp[1][1] = a[1][1];
//	//dp[][]定义： dp[i][j]表示从起点到i行j列的最长路程
//	//那么dp[i][j] = max {dp[i-1][j],d[i-1][j-1]} + a[i][j]
//	int m = 0;
//	for(int i = 2;i<=r;i++)
//		for(int j = 1;j <= i;j++){
//			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
//			m = m > dp[i][j] ? m:dp[i][j];
//		}
//	cout << m;
//	return 0;
//}

