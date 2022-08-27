#include<bits/stdc++.h>

using namespace std;
/*
	01�������������Ϊ�������⣺
	��һ������ΪV�ı���������n�����塣���ں�������ʵ�ʼ�����״��������ΪֻҪ������ʣ���������ڵ�������������ǾͿ���װ�������ÿ�����嶼���������ԣ������w�ͼ�ֵv��
	�ʣ�����򱳰�װ�������ʹ������������ܼ�ֵ���
	
	Vi��ʾ�� i ����Ʒ�ļ�ֵ��Wi��ʾ�� i ����Ʒ�����
	����V(i,j)����ǰ�������� j��ǰ i ����Ʒ�����϶�Ӧ�ļ�ֵ��ͬʱ����������󻯣�X1��X2������Xn������ Xi ȡ0��1����ʾ�� i ����Ʒѡ��ѡ����
	
	dp[i][j] ��ʾ���±�Ϊ[0-i]����Ʒ������ȡ���Ž�����Ϊj�ı�������ֵ�ܺ�����Ƕ��١�
	
	Ҫ����V(i,j)��һ��״̬
		��һ���ǵ�i����Ʒû��װ��ȥ���ڶ����ǵ�i����Ʒװ��ȥ�ˡ�
		û��װ��ȥ������V(i-1,j)��
		װ��ȥ�ˣ���ôװ��֮ǰ��ʲô״̬���϶���V(i-1,j-w(i))������������ԭ��V(i-1,j-w(i))����ǰ�������ɵ�һ��״̬������ľ��߾�Ҫ�������Ų��ԡ�����������бȽϣ��ó����š�

	
*/

#define N 100
int dp[N][N];
int w[N],v[N];

void knap(int n,int weight){
	//��ʼ��dp���� 
	for(int i = 0;i <= n;i++) dp[i][0] = 0;
	for(int i = 0;i <= weight;i++) dp[0][i] = 0;
	
	for(int i = 1;i <= n;i++){  //������Ʒ 
		for(int j = 1;j <= weight;j++){  //�������� 
			if(w[i-1] > j) dp[i][j] = dp[i-1][j];  //��ǰ��Ʒװ���� 
			else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
		}
	}
	cout << dp[n][weight] << endl;
}

int dpdp[N];
//����Ч�� �Ż�0/1����
void bestKnap(int n,int weight){
	for(int i = 1;i <= n;i++){
		for(int j = weight;j >= 0;j--){   //0-1������Ҫ�õ���һ��Ʒ��״̬����Ҫ�Ӻ���ǰ�� 
			if(j >= w[i-1]) dpdp[j] = max(dpdp[j],dpdp[j-w[i-1]]+v[i-1]);
		}
		
		for(int j = 0;j <= weight;j++)   //��ӡ���� 
			cout << dpdp[j] << " ";
		cout << endl; 
	}
	cout << dpdp[weight] << endl;
} 

void traceBack(int i,int j){
	if(i == 0 || j == 0) return;
	if(dp[i][j] == dp[i-1][j]){
		traceBack(i-1,j);
	}
	else if(dp[i][j] == dp[i-1][j-w[i-1]]+v[i-1]){
		traceBack(i-1,j-w[i-1]);
		cout << i << " ";
	}
}
 
int main(){
	/*
	3 4
	1 15
	3 20
	4 30
	*/
	int n, weight;  //n����Ʒ�������������weight 
	cin >> n >> weight;
	for(int i = 0;i < n;i++){
		cin >> w[i] >> v[i];  //���������ͼ�ֵ 
	}
	knap(n,weight);
	traceBack(n,weight);
	bestKnap(n,weight);
    return 0;
}

