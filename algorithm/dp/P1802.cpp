#include <bits/stdc++.h>
using namespace std;
int n,x,lose[1010],win[1010],use[1010],dp[1010];

int main(){
	cin >> n >> x;
	for(int i = 1;i <= n;i++) cin >> lose[i] >> win[i] >> use[i];
	for(int i = 0;i <= x;i++) dp[i] = 0;
	for(int i = 1;i <= n;i++)
		for(int j = x;j >= 0;j--)
			if(j >= use[i]) dp[j] = max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
			else dp[j] += lose[i];
	cout << dp[x]*5;
	return 0;
}

