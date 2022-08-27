#include<bits/stdc++.h>

using namespace std;

//基于快排的划分
//选取low作为pivot
//经过一趟划分后数组变为[1,m-1],m,[m+1,n]
//接下来会有三种情况：
//					1、m=k，那么pivot就是第k小的元素
//					2、m<k，那么进入右子组找第k-m小的元素 
//					3、m>k，那么进入左子组找第k小的元素 
int kMin(int arr[],int low ,int high, int k){
	int pivot = arr[low];
	int low_temp = low;
	int high_temp = high;
	while(low < high){   //一趟划分 
		while(low < high && arr[high] >= pivot) high--;
		arr[low] = arr[high];
		while(low < high && arr[low] <= pivot) low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	//进入三种情况
	if(low == k) return arr[low];
	else if(low < k) return kMin(arr,low+1,high_temp,k);  //这里k并不需要改变，因为low和high已经相对发生了改变 
	return kMin(arr,low_temp,low-1,k);
	
}

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}
//另一种划分的写法 
int kMin2(int arr[],int low ,int high, int k){
	int pivot = arr[low];
	int i = low;  //i指向比pivot小的最后一个数 
	for(int j = low+1;j <= high;j++){
		if(arr[j] < pivot) swap(arr[j],arr[++i]);
	}
	swap(arr[i],arr[low]);
	//进入三种情况
	if(i == k) return arr[i];
	else if(i < k) return kMin(arr,i+1,high,k);  //这里k并不需要改变，因为low和high已经相对发生了改变 
	return kMin(arr,low,i-1,k);
} 

int main(){
	//-1 1 2 2 3 4 5
	int arr[] = {NULL,-1,2,1,3,4,5,2};
	cout << kMin2(arr,1,7,7) << endl;
    return 0;
}

