#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001],dp[1001][1001];
int main(){
	cin >> n>>m;
	int x,y;
	for(int i = 1;i <= m;i++){
		cin >> x>> y;
		a[x][y] = 1;
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			if(i == 1 && j == 1) {
				dp[i][j] = 1;
				continue;
			}
			if(a[i][j] == 0) dp[i][j] = (dp[i-1][j] + dp[i][j-1])%100003;
		}
	cout << dp[n][n];
	return 0;
}

