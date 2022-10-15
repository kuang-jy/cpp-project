#include <iostream>
using namespace std; 
int t,m,w[101],v[101],dp[1010];

int main(){
	cin >> t >> m;
	for(int i = 1;i <= m;i++) cin >> w[i] >> v[i];
	for(int i = 0;i <= t;i++) dp[i] = 0;
	for(int i = 1;i <= m;i++)
		for(int j = t;j >= 1;j--)
			if(j >= w[i]) dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
	cout << dp[t];
	return 0;
}



//#include <bits/stdc++.h>
//using namespace std;
//int t,m,dp[101][1001],w[101],v[101];
//int dpdp[101];
//
//int main(){
//	cin >> t >> m;
//	for(int i = 1;i <= m;i++)
//		cin >> w[i] >> v[i];
//	for(int i = 1;i <= m;i++){
////		for(int j = 1;j <= t;j++){
////			if(j >= w[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
////			else dp[i][j] = dp[i-1][j];
////		}
//		for(int j = t;j >= 0;j--)
//			if(j >= w[i]) dpdp[j] = max(dpdp[j],dpdp[j-w[i]]+v[i]);
//	}
//	cout << dpdp[t];
//	return 0;
//}

