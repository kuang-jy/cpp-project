#include <iostream>
using namespace std;
#define MOD 1000007
int n,m,num[101],dp[101];   //dp[i][j] ��ʾ��i�軨Ϊֹ ��j�� �İڷ�
//0-1�����Ż���ѹ��Ϊһά����

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&num[i]);
	dp[0] = 1;
	for(int i = 1;i <= n;i++)  //ö��ÿ�軨
		for(int j = m;j >= 1;j--)  //ö�ٰڷ�����
			for(int k = 1;k <= min(num[i],j);k++)  //ö�ٵ�ǰ����������ǰ׺��
				dp[j] = (dp[j] + dp[j-k]) % MOD;
	printf("%d\n",dp[m]);
	return 0;
}






// #include <bits/stdc++.h>
// using namespace std;
// #define N 101
// const int mod = 1e6+7;
// //dp���鶨�壬dp[i][j] ��ʾǰi�ֻ����ɷ�j��ķ�����
// int dp[N][N],m,n,a[N]; 
// int main(){
// 	cin >> n >> m;
// 	for(int i = 1;i <= n;i++) cin >> a[i];
// 	dp[0][0] = 1;   //û�л���������0���ʱ�����ȷ�Ϸ�����Ϊ1	
// 	for(int i = 1;i <= n;i++){   //����ÿ�ֻ� 
// 		for(int j = 0;j <= m;j++){  //�������пɷ����� 
// 			for(int k = 0;k <= a[i];k++){   //������ǰ�ֻ��ɷ����� 
// 				if(k <= j)
// 					dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;   //ǰi�軨�����ɷ�j��ʱ���������пɷŵ�������ۼ� 
// 			}
// 		}
// 	} 
// 	cout << dp[n][m];
// 	return 0;
// }

