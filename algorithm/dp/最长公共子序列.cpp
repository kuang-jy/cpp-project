#include<bits/stdc++.h>

using namespace std;

/*
	LCS����������

	���������ַ���
	�������������еĳ��ȡ�����󹫹������еĳ��ȴ���0���򻹻����һ����󹫹������С�
	������
	1528936��568937
	4
	5893
	(ע�⣺�������ǲ������ģ����Ӵ��������ġ������ǵ��ַ�����˳������������ַ�������ĸ�Ⱥ�˳��һ�¡�)
	
	������
	������S1={x1,x2,...,xn} S2={y1,y2,...,ym} �������������ΪS={z1,z2,...,zk}����
		1) ��xn=ym����ôzk=xn=ym��S[k-1]��S1[n-1]��S2[m-1]�����������
		2) ��xn!=ym��zk!=xn����ôS[k]��S1[n-1]��S2[m]�������������
		3) ��xn!=ym��zk!=ym����ôS[k]��S1[n]��s2[m-1]������������� 
		
	dp[i][j]��ʾ��S1��ǰi���ַ���S2��ǰj���ַ�������������г���
	
				0  							, i=0��j=0 
	dp[i][j] =  dp[i-1][j-1]+1				,S1[i] = S2[j]
				max{dp[i-1][j],dp[i][j-1]}  ,S1[i] != S2[j]
*/

#define N 500
int dp[N][N];     
int track[N][N];  //���ڻ��ݣ���ʶ���� 
char s1[N],s2[N];

void LCS(char s1[],char s2[],int m,int n){
	for(int i = 0;i < m+1;i++)     //��ʼ��dp���� 
		dp[0][i] = 0;
	for(int i = 0;i < n+1;i++)     //��ʼ��dp���� 
		dp[i][0] = 0;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <=n;j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				track[i][j] = 2;
			}
			else if(dp[i-1][j] > dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
				track[i][j] = 3;
			} 

			else{
				dp[i][j] = dp[i][j-1];
				track[i][j] = 1;
			} 

		}
	}
	cout << dp[m][n] << endl;
}

void TraceBack(int i,int j){   //�������Ž� 
	if(i == 0 || j == 0) return;
	if(track[i][j] == 2){
		TraceBack(i-1,j-1);
		cout << s1[i-1] << " ";
	}
	else if(track[i][j] == 1) TraceBack(i,j-1);
	else TraceBack(i-1,j);
}

int main(){
	int m,n;
	gets(s1);
	gets(s2);
	m=strlen(s1);
	n=strlen(s2);
	LCS(s1,s2,m,n);
	TraceBack(m,n);
    return 0;
}

