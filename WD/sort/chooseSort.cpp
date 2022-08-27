#include<bits/stdc++.h>

using namespace std;
void swap(int& a,int& b);
void adjust(int arr[],int len,int root);
void buildMaxHeap(int arr[],int len);
void maxHeapSort(int arr[],int len);

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//��ѡ�����򣨲��ȶ���  ʱ�䣺O(n^2)  �ռ䣺O(1) 
void chooseSort(int arr[],int len){
	int min = 0,i;
	for(int j = 0;j < len-1;j++){   //һ��Ҫѡlen-1�� 
		min = j;  //��ʼ��minΪ��������ĵ�һ�� 
		for(i = j;i < len;i++){   //ÿ�δӵ�һ���������鿪ʼѡ 
			if(arr[i] < arr[min]) min = i;
		}
		swap(arr[min],arr[j]);
	}
} 

//������
/*
����ѣ���ȫ�������У��� >= ����
С���ѣ���ȫ�������У��� <= ���� 
*/
 
//ͨ�����У����������
//��������� 
void adjust(int arr[],int len,int root){
	arr[0] = arr[root];  //�ݴ�root���ֵ 
	for(int i = 2*root;i <= len;i*=2){  //��root�����ӿ�ʼ 
		if(i < len && arr[i] < arr[i+1]) i++;  //������Һ��ӣ��Ƚ����Һ��ӣ�ȡ�ϴ���
		if(arr[0] >= arr[i]) break;  //�������������ô��������
		else{   //������ӱȸ��� 
			arr[root] = arr[i];   //���ӽ���ɸ���� 
			root = i;   //�ı�rootΪ���ӣ��ж��Ƿ�Ҫ�������� 
		}
		arr[root] = arr[0];  //���root��λ�þ�������λ��  
	} 
} 
//����arr���±�1��ʼ��¼ 
void buildMaxHeap(int arr[],int len){
	//��ȫ�������ķ��ն˽���� [1,2/n]
	for(int i = len/2;i >= 1;i--)    //�����²�ķ�֧��㿪ʼ 
		adjust(arr,len,i);     //��������� 
}
//������ÿ��ѡ��Ѷ�Ԫ�ؽ�����δ�������е���󣬲��ҵ�������� 
//ʱ�䣺O(nlog2n) �ռ䣺O(1) 
//���ȶ� 
void maxHeapSort(int arr[],int len){  //���������õ���������
	buildMaxHeap(arr,len); 
	while(len){
		swap(arr[1],arr[len]);
		adjust(arr,--len,1);
	}
}

//�ѵĲ����ɾ��

 
void disp(int arr[],int len){
	for(int i = 0;i <len;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[10] = { NULL,10,3,6,23,44,56,99,1,21 };
//	chooseSort(arr,9);
//	disp(arr,8);
	maxHeapSort(arr,9);
	disp(arr,10);
    return 0;
}

