#include <bits/stdc++.h>
using namespace std;
int m,n,k,w[51],g[51],cal[51],dp[51][401][401],dp1[401][401];  //ѹ��dp���� 
int main(){
	cin>>m>>k>>n;
	for(int i = 1;i <= n;i++)
		cin >> w[i] >> g[i] >> cal[i];
//	for(int i = 1;i <= n;i++){  //��Ʒ 
//		for(int j = 1;j <= m;j++){   //��� 
// 			for(int l = 1;l <= k;l++){   //���� 
//				if(j >= w[i] && l >= g[i]) dp[i][j][l] = max(dp[i-1][j][l],dp[i-1][j-w[i]][l-g[i]]+cal[i]);
//				else dp[i][j][l] = dp[i-1][j][l];
//			}
//		}
//	}
//		ѹ��dp����
	for(int i = 1;i <= n;i++)
		for(int j = m;j >= w[i];j--)
			for(int l = k;l >= g[i];l--)
				dp1[j][l] = max(dp1[j][l],dp1[j-w[i]][l-g[i]]+cal[i]);
	cout << dp1[m][k];
	return 0;
}

