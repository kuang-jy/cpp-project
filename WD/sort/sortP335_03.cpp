#include<bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//��˳���������Ԫ���ŵ�ż��Ԫ��֮ǰ 
void sortOddEven(int arr[],int len){
	int low = 0;
	int high = len-1;
	//����������һ��ż��
	//����������һ������
	//�����ҵ��������� 
	while(low < high){
		while(low < high && arr[low]%2 != 0) low++;   //����������һ��ż��
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

