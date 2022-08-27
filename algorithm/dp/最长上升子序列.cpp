#include<bits/stdc++.h>

using namespace std;

/*
	最长上升子序列的定义 (LIS)：
	最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。	
*/

#define N 100
int dp[N];  //dp[i] 表示以num[i]结尾的最长上升子序列长度 

void LIS(int nums[],int n){
	int max = 0;
	for(int i = 0;i < n;i++){
		dp[i] = 1;  //初始为1，即只有本身 
		for(int j = i-1;j >= 0;j--){
			if(nums[j] < nums[i])  //如果前面有小的
				dp[i] = dp[i] < dp[j]+1 ? dp[j]+1 : dp[i];  //更新状态 
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

