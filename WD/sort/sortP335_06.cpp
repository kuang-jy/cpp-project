#include<bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
} 

//�� �� �� --> -1 0 1 
void flag(int arr[],int len){
	int i = -1,j = 0,k = len-1;
	//jΪ����ָ�룬iָ���ɫĩβ��kָ����ɫ��ͷ 
	while(j <= k){
		switch(arr[j]){
			case -1: swap(arr[++i],arr[j++]); break;
			case 0: j++; break;  //��ɫjָ����һ�� 
			case 1: swap(arr[j],arr[k--]); break;   //����ֻ��k--����ֹ����������ɫ����λ�� 
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

