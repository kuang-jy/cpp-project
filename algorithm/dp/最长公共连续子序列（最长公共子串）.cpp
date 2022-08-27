#include<bits/stdc++.h>

using namespace std;

/*
	������������X=<x1,x2,...,xmx1,x2,...,xm>��Y=<y1,y2,...,yny1,y2,...,yn>����X��Y����������������С������������б��������ģ� 
	���磺���������ַ��� acbac�� acaccbabb������������Ӵ�Ϊ ��cba��, �򷵻س��� 3��
	
	������
		dp[i-1][j-1]��ʾ�ַ���S1��i-1��β��S2��j-1��β��������Ӵ�����
		  1��s1[i] = s2[j] ��ôdp[i][j] = dp[i-1][j-1]+1
		  2��s1[i] != s2[j] ��ôdp[i][j] = 0 ����ΪҪ������������ 
*/

#define N 100
int dp[N][N];
char s1[N],s2[N];
int track[N][N];
int r,c;

void LCString(char s1[],char s2[],int m,int n){ 
	int max = 0;
	//��ʼ��dp���� 
	for(int i = 0;i <= m;i++) dp[0][i] = 0;
	for(int i = 0;i <= n;i++) dp[i][0] = 0;
	
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <=n;j++){
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
				track[i][j] = 1;  //��ʾ���� 
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

