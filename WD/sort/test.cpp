#include<bits/stdc++.h>

using namespace std;

//��������ֱ�Ӳ��������۰��������ϣ������
 
//ֱ�Ӳ������򣨲����ڱ��� ʱ�䣺O(n^2) �ռ䣺O(1) 
void insertSort(int arr[],int len){
	int j;
	for(int i = 1;i < len;i++)  //ÿ��ѡ��һ��δ�����Ԫ�� 
		if(arr[i] < arr[i-1]){  //�Ƚϵ�ǰ���ݺ�ǰһ�����ݴ�С 
			int temp = arr[i];   //���浱ǰ���ݣ���ֹ���ݺ��Ƹ��� 
			for(j = i-1;j >= 0 && temp < arr[j];j--)  //ѭ���Ƚϣ����� 
				arr[j+1] = arr[j];  //���� 
			arr[j+1] = temp;  //��󽫸����ݲ��� 
		}
}
//ֱ�Ӳ������򣨴��ڱ��� ʱ�䣺O(n^2) �ռ䣺O(1) 
void insertSortTag(int arr[],int len){
	int j;
	for(int i = 2;i < len;i++){  //0���ڱ� 
		if(arr[i] < arr[i-1]){
			arr[0] = arr[i];
			for(j = i-1;arr[0] < arr[j];j--)  //�����ж� j>=0����Ϊ0λ�����ǵ��ڵ� 
				arr[j+1] = arr[j];
			arr[j+1] = arr[0];
		}
	}
}

//�۰�������򣨴��ڱ��� ʱ�䣺O(n^2) �ռ䣺O(1) 
void binaryInsertSort(int arr[],int len){
	for(int i =2;i < len;i++){
		int low = 1;
		int high = i-1;
		while(low <= high){  //���ֲ��� 
			int mid = (low+high)/2;
			if(arr[mid] <= arr[i]) low = mid+1;  //��֤�ȶ��ԣ��Ⱥ��ڴ˴�ȡ 
			else high = mid-1;
		}
		//Ҫ��low��i-1�����ݺ���
		arr[0] = arr[i];  //�ڱ������������
		for(int j = i-1;j >= low;j--)  //���� 
			arr[j+1] = arr[j];
		arr[low] = arr[0];
	}
}

//ϣ�����򣬲��ȶ�  ʱ�����O(n^2)����len��ĳ����Χ��O(n^1.3) �ռ䣺O(1)
//���������������� 
//arr[0]���ݴ浥Ԫ�������ڱ� 
void shellSort(int arr[],int len){
	int j;
	for(int d = len/2;d >= 1;d/=2){  //�����仯
		for(int i=d+1; i <= len; i++){  //ֱ�Ӳ�������ÿ���ӱ��е�Ԫ�ؽ�����У�������һ����һ���ӱ� 
			if(arr[i] < arr[i-d]){
				arr[0] = arr[i];
				for(j = i-d; j > 0 && arr[0] < arr[j]; j-=d){  //����Ԫ�� 
					arr[j+d] = arr[j];
				}
				arr[j+d] = arr[0]; 
			}  //end if 
		} 
	}
} 
//*************** ��������end ************** 

//��������ð�����򣬿�������

//ð������ ʱ�䣺O(n^2) �ռ䣺O(1) 
void bubbleSort(int arr[],int len){
	int temp;
	bool flag;
	for(int i = 0;i < len;i++){
		flag = false;  //��ʶ���ν����Ƿ�������� 
		for(int j = len-1;j > i;j--){  //ÿ�˶������һ��Ԫ�ؿ�ʼ ������ֻ��Ҫ�Ƚϵ�i����һ��Ԫ�ؼ��� 
			if(arr[j-1] > arr[j]){  //��֤�ȶ��ԣ���ȡ�Ⱥ� 
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
		if(!flag) return;  //���ĳ������δ������������ôһ�����Ѿ�����ֱ�ӷ��� 
	}
} 

//�������򣨲��ȶ��� ���ʱ�䣺O(nlog2n)  �ʱ�䣺O(n^2)  ƽ��ʱ�䣺O(nlog2n) 
//		             ��ÿռ䣺O(log2n)  ��ռ䣺O(n)  
int partition(int arr[],int low,int high){  //����Ļ��ֺ��� 
	int pivot = arr[low];  //ѡ���׼��
	while(low < high){
		while(low < high && arr[high] >= pivot) high--;  //�����ӱ�Ԫ�رȻ�׼������highָ�벻��ǰ��
		arr[low] = arr[high];    //�������� arr[high] >= pivot �˳�while����ô��ʾhighָ�������С�ڻ�׼������ôhighָ�������Ӧ����lowָ���λ�ã�����Ѿ����� high��lowָ��ͬһλ�� 
		while(low < high && arr[low] <= pivot) low++;  
		arr[high] = arr[low];
	}
	arr[low] = pivot;  //����׼�����������ӱ��м� 
	return low;  //���ػ�׼��λ�� 
}
void quickSort(int arr[],int low,int high){
	if(low >= high) return;  //ֻʣ1��Ԫ�أ��Ѿ�����ֱ�ӷ��� 
	int pivot = partition(arr,low,high);  //�����ӱ�
	quickSort(arr,low,pivot-1);
	quickSort(arr,pivot+1,high); 
} 

//************* ��������end *************** 

void show(int arr[],int len){
	for(int i = 0;i <len;i++) 
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[]{-1,1,3,2,4,6,4,2,1,3};
//	insertSortTag(arr,9);
//	binaryInsertSort(arr,10);
//	shellSort(arr,9);
//	bubbleSort(arr,10);
	quickSort(arr,0,9);
	show(arr,10);
    return 0;
}

