//*********分治解法*********
#include <iostream>
using namespace std;
int n,nums[200010];
/*
一个数组的最大子段和可能出现在三种情况中：
	首先将数组划分为low,mid,high两部分
	一、最大子段和出现在low-mid中
	二、最大子段出现在mid-high中
	三、最大子段出现在low-k-mid-j-high中
	对于情况一和二，直接递归调用求解即可
	对于情况三，迭代循环求解
*/

int resolve(int low,int high){
	if(low == high)  return nums[low];  //划分到只有一个元素后直接返回该元素
	int mid = low+(high-low)/2;
	int subl = resolve(low,mid);   //情况1
	int subr = resolve(mid+1,high);	  //情况2
	//以下是情况3
	int sum = 0,maxl = -999999999,maxr = -999999999;
	for(int i = mid;i >= low;i--){
		sum+=nums[i];
		maxl = max(maxl,sum);
	}
	sum = 0;
	for(int i = mid+1;i <= high;i++){
		sum += nums[i];
		maxr = max(maxr,sum);
	}
	return max(maxl+maxr,max(subr,subl));   //返回三种情况的最大值就是答案
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> nums[i];
	cout << resolve(1,n) << endl;
	return 0;
}



//******动态规划解法******
// #include <iostream>
// using namespace std;
// int n,nums[200010],dp[200010],ans = -9999999999;

// int main(){
// 	scanf("%d",&n);
// 	for(int i = 1;i <= n;i++) {
// 		scanf("%d",&nums[i]);
// 		dp[i] = nums[i];  //初始化dp数组
// 	}
// 	for(int i = 1;i <= n;i++){
// 		//如果上一状态>0，那么当前状态的最大和就是当前数直接加上上一状态的值
// 		//如果上一状态<=0，那么当前状态的最大和就是当前数，因为加上一个负数显然不会是当前的最大和
// 		dp[i] = max(dp[i-1]+nums[i],nums[i]);
// 		ans = max(ans,dp[i]);
// 	}
// 	printf("%d\n",ans);
// 	return 0;
// }








// #include <bits/stdc++.h>
// using namespace std;
// #define max 200001
// int n,a[max];

// int maxsum(int a[],int low,int high){
// 	if(low == high) return a[low] > 0 ? a[low] : 0;
// 	int mid = low+(high-low)/2;
// 	int l = maxsum(a,low,mid);
// 	int r = maxsum(a,mid+1,high);
// 	int sum = 0,temp1 = -19260817,temp2 = -19260817;
// 	for(int i = mid;i >= low;i--){
// 		sum += a[i];
// 		if(temp1 < sum) temp1 = sum;
// 	}
// 	sum = 0;
// 	for(int i = mid+1;i <= high;i++){
// 		sum += a[i];
// 		if(temp2 < sum) temp2 = sum;
// 	}
// 	sum = temp1+temp2;
// 	return sum > l ? (sum > r ? sum : r) : (l > r ? l : r); 
// } 

// int main(){
// 	cin >> n;
// 	for(int i = 0;i < n;i++)
// 		cin >>a[i];
// 	cout << maxsum(a,0,n-1) << endl;
// 	return 0;
// }
