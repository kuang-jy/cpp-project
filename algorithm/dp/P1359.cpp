#include <iostream>
#include <cstring>
using namespace std;
int cost[602][602],n,dp[602];

int main(){
	memset(dp,0x3f,sizeof(dp));  //dp��ʼ������ֵ
	dp[1] = 0;  //������Ϊ��
	scanf("%d",&n);
	for(int i = 1;i < n;i++)
		for(int j = i+1;j <= n;j++)
			scanf("%d",&cost[i][j]);   //��ȡվ�����
	for(int i = 2;i <= n;i++)   //����ÿ��վ���������
		for(int j = 1;j < i;j++)
			dp[i] = min(dp[i],dp[j]+cost[j][i]);
	printf("%d\n",dp[n]);
	return 0;
}




























// #include <bits/stdc++.h>
// using namespace std;
// #define N 201
// int dis[N][N],dp[N],n;

// int main(){
// 	cin >> n;
// 	for(int i = 1;i < n;i++){
// 		for(int j = i+1;j <= n;j++)
// 			cin >> dis[i][j];
// 	}	
// 	for(int i = 1;i <= n;i++) dp[i] = dis[1][i];
// 	//dp���鶨�壬dp[i]��ʾ��1��i����С���� 
// 	for(int i = 2;i <= n;i++){   //������2��n��������� 
// 		for(int j = i-1; j >= 1;j--){    //����nΪ3����ô��ǰ״̬�Ǵ�1ֱ�ӵ�3 ��1-3����������2��ת1-2-3 
// 			dp[i] = min(dp[i],dp[j]+dis[j][i]);
// 		}
// 	} 
// 	cout << dp[n] << endl;
// 	return 0;
// }

