#include <bits/stdc++.h>
using namespace std;

long long f[1001][4],n,m,dp[1001]; 
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> f[i][1] >> f[i][2] >> f[i][3];
	for(int i = 1;i <= n;i++){
		for(int j = m;j >= 0;j--){
			if(j >= f[i][3]) dp[j] = max(dp[j]+f[i][1],dp[j-f[i][3]]+f[i][2]);   //��ҩˮ���ڴ����Ҫ��ҩˮ��ô������ѡ����ҩ�� �� ����ҩ�� 
			else dp[j] += f[i][1];   //��ҩˮ���ڴ����Ҫ��ҩˮ��ֱ�Ӳ��� 
		} 
	} 
	cout << dp[m]*5 << endl;
	return 0;
}

