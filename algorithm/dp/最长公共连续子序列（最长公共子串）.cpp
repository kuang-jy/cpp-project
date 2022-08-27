#include<bits/stdc++.h>

using namespace std;

/*
	给定两个序列X=<x1,x2,...,xmx1,x2,...,xm>和Y=<y1,y2,...,yny1,y2,...,yn>，求X和Y的最长公共公共子序列。（连续子序列必须连续的） 
	例如：输入两个字符串 acbac和 acaccbabb，则最大连续子串为 “cba”, 则返回长度 3。
	
	分析：
		dp[i-1][j-1]表示字符串S1以i-1结尾和S2以j-1结尾的最长连续子串长度
		  1）s1[i] = s2[j] 那么dp[i][j] = dp[i-1][j-1]+1
		  2）s1[i] != s2[j] 那么dp[i][j] = 0 ，因为要求连续子序列 
*/

#define N 100
int dp[N][N];
char s1[N],s2[N];
int track[N][N];
int r,c;

void LCString(char s1[],char s2[],int m,int n){ 
	int max = 0;
	//初始化dp数组 
	for(int i = 0;i <= m;i++) dp[0][i] = 0;
	for(int i = 0;i <= n;i++) dp[i][0] = 0;
	
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <=n;j++){
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
				track[i][j] = 1;  //表示左上 
				if(dp[i][j] > max){
					max = dp[i][j];
					r = i;
					c = j;
				}
			}
			else {
				dp[i][j] = 0;
				track[i][j] = -1;
			}
		}
	}
	cout << max << endl;
}

void TraceBack(int i,int j){
	if(i == 0 || j == 0) return;
	if(track[i][j] == 1){
		TraceBack(i-1,j-1);
		cout << s1[i-1] << " "; 
	}
}

int main(){
	int m,n;
	gets(s1);
	gets(s2);
	m = strlen(s1);
	n = strlen(s2);
	LCString(s1,s2,m,n);
	TraceBack(r,c);
    return 0;
}

