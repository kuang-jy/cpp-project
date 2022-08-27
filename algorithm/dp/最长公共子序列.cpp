#include<bits/stdc++.h>

using namespace std;

/*
	LCS问题描述：

	输入两个字符串
	输出最长公共子序列的长度。若最大公共子序列的长度大于0，则还会输出一个最大公共子序列。
	举例：
	1528936与568937
	4
	5893
	(注意：子序列是不连续的，而子串是连续的。但它们的字符出现顺序均与所输入字符串的字母先后顺序一致。)
	
	分析：
	设序列S1={x1,x2,...,xn} S2={y1,y2,...,ym} 的最长公共子序列为S={z1,z2,...,zk}，则
		1) 若xn=ym，那么zk=xn=ym，S[k-1]是S1[n-1]和S2[m-1]的最长公子序列
		2) 若xn!=ym，zk!=xn，那么S[k]是S1[n-1]和S2[m]的最长公共子序列
		3) 若xn!=ym，zk!=ym，那么S[k]是S1[n]和s2[m-1]的最长公共子序列 
		
	dp[i][j]表示：S1的前i个字符和S2的前j个字符的最长公共子序列长度
	
				0  							, i=0或j=0 
	dp[i][j] =  dp[i-1][j-1]+1				,S1[i] = S2[j]
				max{dp[i-1][j],dp[i][j-1]}  ,S1[i] != S2[j]
*/

#define N 500
int dp[N][N];     
int track[N][N];  //用于回溯，标识方向 
char s1[N],s2[N];

void LCS(char s1[],char s2[],int m,int n){
	for(int i = 0;i < m+1;i++)     //初始化dp数组 
		dp[0][i] = 0;
	for(int i = 0;i < n+1;i++)     //初始化dp数组 
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

void TraceBack(int i,int j){   //构造最优解 
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

