#include <bits/stdc++.h>
using namespace std;
int n,a[10010],dp[10010],ans;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i <= n;i++){
		if(a[i] == a[i-1]+1) dp[i] = dp[i-1]+1;
		else dp[i] = 1;
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans;
	return 0;
}

