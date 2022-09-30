#include <bits/stdc++.h>
using namespace std;

//dp���� dp[i]��ʾ��i��β�ܵõ����������
//���һ���ؽ���û��ͨ���ĵؽѵ�·�ģ����Դ����һ���ؽѿ�ʼ��ǰ���ƣ���ʼ��dp[n]=num[n] 
//״̬ת�ƣ�dp[i] = max{dp[j]}+num[i]; 
//������dp�����ҵ��������� 
int dp[21],link[21][21],n,num[21],path[21],ans,pos;

void dfs(int i){
	if(!i) return;
	dfs(path[i]);
	cout << i << " ";
	
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		dp[i] = num[i];   //˳���ʼ��dp���� 
	}

	for(int i = 1; i <= n-1;i++)
		for(int j = i+1;j <= n;j++)
			cin >> link[i][j];
			
	for(int i = 2;i <= n;i++){    //�����յ���� 
		for(int j = 1;j < i;j++){
			if(link[j][i] && dp[i] < dp[j]+num[i]){   //���������ͨ���Ҵ�j�ڵ�i�ɵõ�������������ô����dp������¼·�� 
				dp[i] = dp[j]+num[i];
				path[i] = j;
			}
		}
		if(ans < dp[i]){    //���´� 
			ans = dp[i];
			pos = i;   //��¼���Ľ�β 
		}
	}
	dfs(pos);
	cout << endl << ans;
	return 0;
}
