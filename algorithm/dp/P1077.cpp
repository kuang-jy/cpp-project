#include <bits/stdc++.h>
using namespace std;
#define N 101
const int mod = 1e6+7;
//dp���鶨�壬dp[i][j] ��ʾǰi�ֻ����ɷ�j��ķ�����
int dp[N][N],m,n,a[N]; 
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dp[0][0] = 1;   //û�л���������0���ʱ�����ȷ�Ϸ�����Ϊ1	
	for(int i = 1;i <= n;i++){   //����ÿ�ֻ� 
		for(int j = 0;j <= m;j++){  //�������пɷ����� 
			for(int k = 0;k <= a[i];k++){   //������ǰ�ֻ��ɷ����� 
				if(k <= j)
					dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;   //ǰi�軨�����ɷ�j��ʱ���������пɷŵ�������ۼ� 
			}
		}
	} 
	cout << dp[n][m];
	return 0;
}

