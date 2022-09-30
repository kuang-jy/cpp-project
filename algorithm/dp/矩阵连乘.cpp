#include <bits/stdc++.h>
using namespace std;
#define N 100

void matrixChain(int p[],int s[][N],int dp[][N],int n){
	for(int i = 1;i <= n;i++) dp[i][i] = 0;   //��������ֻ��һ�����󣬲���Ҫ�ˣ�����Ϊ0
	
	for(int i = 2 ;i <= n;i++){     //�Ӿ�����������������ʼ
		for(int j = 1;j <= n-i+1;j++){   //��������������Ϊiʱ���п��ܵ����
			int k = j+i-1;   //��jΪ���ĳ�Ϊi�ľ��������յ� 
			dp[j][k] = dp[j][j] + dp[j+1][k] + p[j-1]*p[j]*p[k];
			s[j][k] = j;
			for(int l = j+1;l < k;l++){
				int temp = dp[j][l] + dp[l+1][k] + p[j-1]*p[l]*p[k];
				if(temp < dp[j][k]){
					dp[j][k] = temp;
					s[j][k] = l;
				}
			}
		}		
	} 
} 

void traceBack(int s[][N],int i,int j){
	if(i==j) cout << "A" << i;
	else{
		cout << "(";
		traceBack(s,i,s[i][j]);
		traceBack(s,s[i][j]+1,j);
		cout << ")";
	}
}

int main(){
	int p[N] = {30,35,15,5,10,20,25};  //����ά��
	int n = 7;
	int dp[N][N],s[N][N];
	matrixChain(p,s,dp,n);
	traceBack(s,1,6); 
	return 0;
}

