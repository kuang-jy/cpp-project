#include<bits/stdc++.h>

using namespace std;


//�� len/2 ����СԪ�ط���A1��ʣ��Ԫ�ط���A2
//һ�˻���֮���ж�low�Ƿ��ڵ�len/2��λ��
//���������1��low == len/2 ���ֳɹ� 
//			2��low < len/2 ��low�ұ߼������� 
// 			3��low > len/2 ��low��߼������� 
int divide(int arr[],int len){
	bool flag = true;  //����Ƿ񻮷ֳɹ�
	int low = 0,high = len-1;
	int low_temp = 0,high_temp = len-1;  //��¼ԭʼlow��high 
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
		//�ж�������� 
		if(low == mid-1) flag = false;
		else if(low < mid-1){
			low_temp = ++low;   //��С��߽� 
			high = high_temp;   //�ָ�high 
		}
		else{
			high_temp = --low;   //��С�ұ߽� 
			low = low_temp;     //�ָ�low 
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

