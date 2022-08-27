#include<bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
} 

//红 白 蓝 --> -1 0 1 
void flag(int arr[],int len){
	int i = -1,j = 0,k = len-1;
	//j为工作指针，i指向红色末尾，k指向蓝色开头 
	while(j <= k){
		switch(arr[j]){
			case -1: swap(arr[++i],arr[j++]); break;
			case 0: j++; break;  //白色j指向下一个 
			case 1: swap(arr[j],arr[k--]); break;   //这里只让k--，防止出现两个蓝色交换位置 
		}
	}
}

int main(){
	int arr[] = {1,-1,0,0,-1,1};
	flag(arr,6);
	for(int i = 0;i < 6;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
    return 0;
}

