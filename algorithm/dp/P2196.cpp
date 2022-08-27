#include <bits/stdc++.h>
using namespace std;

//dp���� dp[i]��ʾ��i��β�ܵõ����������
//���һ���ؽ���û��ͨ���ĵؽѵ�·�ģ����Դ����һ���ؽѿ�ʼ��ǰ���ƣ���ʼ��dp[n]=num[n] 
//״̬ת�ƣ�dp[i] = max{dp[j]}+num[i]; 
//������dp�����ҵ��������� 
int dp[21],link[21][21],n,num[21],path[21];

void dfs(int i){
	if(!i) return;
	cout << i << " ";
	dfs(path[i]);
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		dp[i] = num[i];
	}

	for(int i = 1; i <= n-1;i++)
		for(int j = i+1;j <= n;j++)
			cin >> link[i][j];
			
	for(int i = n-1;i >= 1;i--){
		int f = 0,pre = 0;  //f��¼�ɴ�ؽѵ�����������pre��¼·�� 
		for(int j = i+1;j <= n;j++){
			if(link[i][j] && dp[j] > f) {
				f = dp[j];
				pre = j;
			}
		}
		dp[i] = f+num[i];
		path[i] = pre;
	}
	
	int max = 1;
	for(int i = 2;i <=n;i++)
		if(dp[max] < dp[i])
			max = i;
	dfs(max);
	cout << dp[max] << endl;
	return 0;
}
