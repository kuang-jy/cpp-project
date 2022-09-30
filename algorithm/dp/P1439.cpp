#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin >> n;
	int a[n],b[n];
	int dp[n+1];
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++) cin >> b[i];
	memset(dp,0,n+1);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(a[i] == b[j]) dp[j] = dp[]
	return 0;
}

