#include <bits/stdc++.h>
using namespace std;
int n,k,dp[100001];   //dp���鶨�壺dp[i]��ʾ�ӵײ��ߵ���i��̨�׵ķ����� 
const int mod=100003;

int main(){
	cin >> n >> k;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= k;j++){
			if(i-j >= 0){
				dp[i] = dp[i]+dp[i-j];
				dp[i]%=mod;
			} 
		}
	}
	cout <<dp[n];
	return 0;
}

