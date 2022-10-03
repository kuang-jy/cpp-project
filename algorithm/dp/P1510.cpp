#include <bits/stdc++.h>
using namespace std;
int v,n,c,val[10001],cost[10001],dp[10001];
int main(){
	cin >>v>>n>>c;
	for(int i = 1;i <= n;i++) cin >> val[i] >> cost[i];
	for(int i = 1;i <= n;i++)
		for(int j = c;j >= 1;j--)
			if(j >= cost[i]) dp[j] = max(dp[j],dp[j-cost[i]]+val[i]);
//	cout << dp[c] << endl;
	if(dp[c] < v) cout << "Impossible";
	else{
		for(int i = 0;i <= c;i++)
			if(dp[i] >= v) {
				cout << c-i << endl;
				return 0;
			}
	}
	return 0;
}

