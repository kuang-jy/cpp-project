#include <bits/stdc++.h>
using namespace std;
const int N = 300050;
int m,s,t,dp[N];   //dp���鶨�壺dp[i]��ʾ��iʱ����Զ���ߵľ���


int main(){
	cin >> m>>s>>t;
	for(int i = 1;i <= t;i++){
		if(m >= 10) {
			dp[i] = dp[i-1]+60;
			m-=10;
		}
		else{
			dp[i] = dp[i-1];
			m+=4;
		}
	}
	for(int i = 1;i <= t;i++){
		dp[i] = max(dp[i-1]+17,dp[i]);
		if(dp[i] >= s){
			cout << "Yes\n" << i;
			return 0;
		}
	}
	cout << "No\n" << dp[t];
	return 0;
}

