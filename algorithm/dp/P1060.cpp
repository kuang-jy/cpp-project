#include <bits/stdc++.h>
using namespace std;
int n,m,w[26],v[26],dp[30001];

int main(){
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		w[i+1] = a;
		v[i+1] = a*b;
	}
	for(int i = 1;i <= m;i++)
		for(int j = n;j >= 1;j--)
			if(j >= w[i])
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		
	cout << dp[n] << endl;
	return 0;
}

