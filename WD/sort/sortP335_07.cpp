#include<bits/stdc++.h>

using namespace std;


//将 len/2 个最小元素放入A1，剩余元素放入A2
//一趟划分之后判断low是否在第len/2的位置
//三种情况：1、low == len/2 划分成功 
//			2、low < len/2 对low右边继续划分 
// 			3、low > len/2 对low左边继续划分 
int divide(int arr[],int len){
	bool flag = true;  //标记是否划分成功
	int low = 0,high = len-1;
	int low_temp = 0,high_temp = len-1;  //记录原始low，high 
	int mid = len/2;
	while(flag){
		int pivot = arr[low];
		while(low < high){
			while(low < high && arr[high] >= pivot) high--;
			arr[low] = arr[high];
			while(low < high && arr[low] <= pivot) low++;
			arr[high] = arr[low];
		}
		arr[low] = pivot;
		//判断三种情况 
		if(low == mid-1) flag = false;
		else if(low < mid-1){
			low_temp = ++low;   //缩小左边界 
			high = high_temp;   //恢复high 
		}
		else{
			high_temp = --low;   //缩小右边界 
			low = low_temp;     //恢复low 
		}
	} 
	int count1 = 0,count2 = 0;
	for(int i = 0;i <= low;i++) count1+=arr[i];
	for(int i = low+1;i < len;i++) count2+=arr[i];
	return count2-count1;
}

int main(){
	//1 2 2 3 | 6 7 8 9
	int arr[] = {2,6,1,3,7,9,2,8};
	cout << divide(arr,8) << endl;
    return 0;
}

