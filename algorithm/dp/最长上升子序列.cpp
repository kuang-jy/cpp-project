#include<bits/stdc++.h>

using namespace std;

/*
	����������еĶ��� (LIS)��
	�������������������һ������ĸ����������ҵ�һ�������ܳ����ɵ͵������е������У����������в�һ���������Ļ���Ψһ�ġ�	
*/

#define N 100
int dp[N];  //dp[i] ��ʾ��num[i]��β������������г��� 

void LIS(int nums[],int n){
	int max = 0;
	for(int i = 0;i < n;i++){
		dp[i] = 1;  //��ʼΪ1����ֻ�б��� 
		for(int j = i-1;j >= 0;j--){
			if(nums[j] < nums[i])  //���ǰ����С��
				dp[i] = dp[i] < dp[j]+1 ? dp[j]+1 : dp[i];  //����״̬ 
		}
		if(max < dp[i]) max = dp[i];
	}
	cout << max << endl;
}

int main(){
	int nums[] = {1,5,2,3,4,0,3};
	LIS(nums,7);
    return 0;
}

