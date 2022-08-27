#include<bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//双端冒泡排序 
void twoWayBubbleSort(int arr[],int len){
	int low = 0;
	int high = len-1;
	bool flag = true;
	// 如果low和high遇到，或low超过了high 说明排序结束 
	// 如果在某趟冒泡中，未产生元素交换，说明排序结束 
	while(low < high && flag){  
		flag = false;   //假设此次冒泡未产生元素交换 
		for(int i = low;i < high;i++){   //先把大的从前往后冒 
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
				flag = true;
			}
		}
		high--;  //上界缩小
		for(int i = high;i > low;i--){    //再把小的从后往前冒 
			if(arr[i] < arr[i-1]){
				swap(arr[i],arr[i-1]);
				flag = true;
			}	
		}
		low++;  //下界增加 
	}
} 

void show(int arr[],int len){
	for(int i = 0;i < len ;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int arr[]{-1,4,2,3,6,2,1,9};  //len=8
	twoWayBubbleSort(arr,8);
	show(arr,8);
    return 0;
}

