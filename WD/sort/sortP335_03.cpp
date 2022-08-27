#include<bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//将顺序表中奇数元素排到偶数元素之前 
void sortOddEven(int arr[],int len){
	int low = 0;
	int high = len-1;
	//从左向右找一个偶数
	//从右向左找一个奇数
	//交换找到的两个数 
	while(low < high){
		while(low < high && arr[low]%2 != 0) low++;   //从左向右找一个偶数
		while(low < high && arr[high]%2 == 0) high--;
		if(low < high) swap(arr[low],arr[high]);
		low++;
		high--;
	}
}

void show(int arr[],int len){
	for(int i = 0;i < len ;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[]{1,3,4,6,7,10};
	sortOddEven(arr,6);
	show(arr,6);
    return 0;
}

