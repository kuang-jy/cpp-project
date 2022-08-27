#include<bits/stdc++.h>

using namespace std;

/*
	给定由n个整数(可能为负整数)组成的序列a1，a2， a3… ， an， 寻找它的某个连续子段，使得其和最大。例如( -2,11,-4,13,-5,-2 )最大子段是{ 11,-4,13 }其和为20。
	
*/ 


//暴力法
void solve1(int a[],int n){
	int start = 0;//起始位置
	int end = 0;//结束位置
	int max = 0;
	for(int i = 0; i <= n; ++i){
    	int sum = 0;
	    for(int j = i; j <= n;++j){
	        sum += a[j];
	        if(sum > max){
	           start = i;
	           end = j;
	           max = sum;
	        }
	    }
	} 
	cout << max << endl;
} 

//分治法
//将序列a[1:n]分为 a[1:2/n] a[2/n+1,n]
//那么最大子段和只可能是三种情况：
//								1、在[1, n/2]这个区域内
//								2、在[n/2+1, n]这个区域内
//								3、起点位于[1,n/2],终点位于[n/2+1,n]内 
int solve2(int a[],int left,int right){
	if(left == right) return a[left] > 0 ? a[left] : 0;  //如果只有一个数了，并且还是负数，那直接不加
	int mid = (left+right)/2;
	//情况一 
	int leftmax = solve2(a,left,mid); 
	//情况二 
	int rightmax = solve2(a,mid+1,right);
	//情况三，需要暴力求解
	int sum = 0;
	int lefttemp = 0,righttemp = 0;
	for(int i = mid;i >= left;i--){
		sum += a[i];
		if(lefttemp < sum) lefttemp = sum;
	} 
	sum = 0;
	for(int i = mid+1;i <= right;i++){
		sum += a[i];
		if(righttemp < sum) righttemp = sum;
	} 
	sum = lefttemp+righttemp;
	if(sum < leftmax) sum = leftmax;
	if(sum < rightmax) sum = rightmax;
	return sum;
} 

//动态规划法
/*
	令b[j]表示以位置 j 为终点的所有子区间中和最大的一个
	子问题:如j为终点的最大子区间包含了位置j-1,则以j-1为终点的最大子区间必然包括在其中
	如果b[j-1] >0, 那么显然b[j] = b[j-1] + a[j]，用之前最大的一个加上a[j]即可
	如果b[j-1]<=0,那么b[j] = a[j] ,因为既然最大，前面的负数必然不能使你更大
*/
int solve3(int a[],int n){
	int max = 0,b = 0;
	for(int i = 0;i < n;i++){
		if(b > 0) b+= a[i];
		else b = a[i];
		if(b > max) max = b;
	}
	return max;
} 

int main(){
	int a[] = {-2,11,-4,13,-5,-2};
	solve1(a,5);
	cout << solve2(a,0,5) << endl;
	cout << solve3(a,6) << endl;
    return 0;
}

