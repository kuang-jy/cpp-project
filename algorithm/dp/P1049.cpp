#include <bits/stdc++.h>
using namespace std;
int v,n,dp[20001],w[31];
int main(){
	cin >> v >> n;
	for(int i = 1;i <= n;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = v;j >= 1;j--)
			if(j >= w[i]) dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
	cout << v-dp[v] << endl;
	return 0;
}

