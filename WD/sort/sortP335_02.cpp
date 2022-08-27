#include<bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//˫��ð������ 
void twoWayBubbleSort(int arr[],int len){
	int low = 0;
	int high = len-1;
	bool flag = true;
	// ���low��high��������low������high ˵��������� 
	// �����ĳ��ð���У�δ����Ԫ�ؽ�����˵��������� 
	while(low < high && flag){  
		flag = false;   //����˴�ð��δ����Ԫ�ؽ��� 
		for(int i = low;i < high;i++){   //�ȰѴ�Ĵ�ǰ����ð 
			if(arr[i] > arr[i+1]){
				swap(arr[i],arr[i+1]);
				flag = true;
			}
		}
		high--;  //�Ͻ���С
		for(int i = high;i > low;i--){    //�ٰ�С�ĴӺ���ǰð 
			if(arr[i] < arr[i-1]){
				swap(arr[i],arr[i-1]);
				flag = true;
			}	
		}
		low++;  //�½����� 
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

