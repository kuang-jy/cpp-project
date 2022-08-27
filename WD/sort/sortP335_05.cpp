#include<bits/stdc++.h>

using namespace std;

//���ڿ��ŵĻ���
//ѡȡlow��Ϊpivot
//����һ�˻��ֺ������Ϊ[1,m-1],m,[m+1,n]
//�������������������
//					1��m=k����ôpivot���ǵ�kС��Ԫ��
//					2��m<k����ô�����������ҵ�k-mС��Ԫ�� 
//					3��m>k����ô�����������ҵ�kС��Ԫ�� 
int kMin(int arr[],int low ,int high, int k){
	int pivot = arr[low];
	int low_temp = low;
	int high_temp = high;
	while(low < high){   //һ�˻��� 
		while(low < high && arr[high] >= pivot) high--;
		arr[low] = arr[high];
		while(low < high && arr[low] <= pivot) low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	//�����������
	if(low == k) return arr[low];
	else if(low < k) return kMin(arr,low+1,high_temp,k);  //����k������Ҫ�ı䣬��Ϊlow��high�Ѿ���Է����˸ı� 
	return kMin(arr,low_temp,low-1,k);
	
}

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}
//��һ�ֻ��ֵ�д�� 
int kMin2(int arr[],int low ,int high, int k){
	int pivot = arr[low];
	int i = low;  //iָ���pivotС�����һ���� 
	for(int j = low+1;j <= high;j++){
		if(arr[j] < pivot) swap(arr[j],arr[++i]);
	}
	swap(arr[i],arr[low]);
	//�����������
	if(i == k) return arr[i];
	else if(i < k) return kMin(arr,i+1,high,k);  //����k������Ҫ�ı䣬��Ϊlow��high�Ѿ���Է����˸ı� 
	return kMin(arr,low,i-1,k);
} 

int main(){
	//-1 1 2 2 3 4 5
	int arr[] = {NULL,-1,2,1,3,4,5,2};
	cout << kMin2(arr,1,7,7) << endl;
    return 0;
}

