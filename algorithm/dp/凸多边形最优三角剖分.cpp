#include<bits/stdc++.h>

using namespace std;

/*
	����͹�����P���Լ��������ɶ���εıߺ�����ɵ��������ϵ�Ȩ����w��Ҫ��ȷ����͹����ε������ʷ֣�ʹ�ø������ʷ�������������Ȩ֮��Ϊ��С��
	
	��͹(n+1)����P={V0,V1����Vn}�����������ʷ�T����������V0VkVn,1<=k<=n��
	��T��ȨΪ��������Ȩ֮�ͣ�������V0VkVn��Ȩ��{V0,V1����Vk}��Ȩ��{Vk,Vk+1����Vn}��Ȩ֮�͡�
	��Tȷ�����������Ӷ���ε������ʷ�Ҳ�����ŵġ�
	
	��t[i][j],1<=i<j<=nΪ͹�����{Vi-1,Vi����Vj}�����������ʷ�����Ӧ��Ȩֵ����ֵ����������ֵ��
	�����ʷְ���������Vi-1VkVj��Ȩ���Ӷ����{Vi-1,Vi����Vk}��Ȩ���Ӷ����{Vk��Vk+1����Vj}��Ȩ֮�͡�
	 
*/
#define N 100
int weight[N][N] = {{0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},
{1,2,1,6,0,1},{4,3,4,2,1,0}};  //��¼�������Ȩֵ 
int dp[N][N];  //��¼����ֵ 
int s[N][N];  //��¼�ʷֲ��� 

//�ʷ������ε��ܳ�
int get_weight(int a, int b, int c)
{
    return weight[a][b] + weight[b][c] + weight[c][a];
}

void triangleDivide(int n){
	for(int i = 1;i <= n;i++) dp[i][i] = 0;  //��ʼ���Խ���Ϊ0��ֻ��һ�����ǲ��ܱ����ǻ��ֵ� 
	for(int l = 2;l <= n;l++){		//�����ģ 
		for(int i = 1;i <= n-l+1;i++){   //���� 
			int j = i+l-1;   	//�յ�� 
			dp[i][j] = dp[i][i] + dp[i+1][j] + get_weight(i-1,i,j);
			s[i][j] = i;
			for(int k = i+1;k < j;k++){
				int temp = dp[i][k] + dp[k+1][j] + get_weight(i-1,k,j);
				if(temp < dp[i][j]){
					dp[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][n-1];
}

int main(){
	triangleDivide(6);
    return 0;
}

