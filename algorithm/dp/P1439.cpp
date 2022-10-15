#include <bits/stdc++.h>
using namespace std;
int n,s1[100001],s2[100001],dp[100001][100001];

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> s1[i];
	for(int i = 1;i <= n;i++) cin >> s2[i];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout << dp[n][n];
	return 0;
}

