#include<bits/stdc++.h>

using namespace std;

/*
	��һ������ΪV�ı���������n�����塣���ں�������ʵ�ʼ�����״��������ΪֻҪ������ʣ���������ڵ�������������ǾͿ���װ�������
	ÿ�����嶼���������ԣ������w�ͼ�ֵv��
	ÿ�������ǿ����зֵ� 
	�ʣ�����򱳰�װ�������ʹ������������ܼ�ֵ���

	ʹ��̰�����ԣ�ÿ�ζ�ѡ�� ��λ��ֵ��� ����Ʒ���뱳�� 
*/ 
#define N 100
int w[N],v[N];
float x[N];
float ans[N];

//����Ʒ���յ�λ��ֵ�������� 
int partition(int low,int high){
	float pivot = x[low];
	int a = w[low];
	int b = v[low];
	while(low < high){
		while(low < high && x[high] <= pivot) high--;
		x[low] = x[high];
		w[low] = w[high];
		v[low] = v[high];
		while(low < high && x[low] >= pivot) low++;
		x[high] = x[low];
		w[high] = w[low];
		v[high] = v[low];
	}
	x[low] = pivot;
	w[low] = a;
	v[low] = b;
	return low;
}

void sort(int low,int high){
	if(low >= high) return;
	int pivot = partition(low,high);
	sort(low,pivot-1);
	sort(pivot+1,high);
}


void greedyKnap(int n,int weight){
	int i;
	sort(0,n-1);
	for(i = 0;i < n;i++) ans[i] = 0;
	for(i = 0;i < n;i++){
		if(w[i] > weight) break;
		ans[i] = 1;
		weight -= w[i];
	}
	if(i < n) ans[i] = weight*1.0/w[i];
}

int main(){
	int n,weight;
	cin >> n >> weight;
	for(int i = 0;i < n;i++){
		cin >> w[i] >> v[i];
	}
	//���㵥λ��ֵ 
	for(int i = 0;i < n;i++)
		x[i] = v[i]*1.0/w[i];
	greedyKnap(n,weight);
	for(int i = 0;i < n;i++) cout << ans[i] << " ";
    return 0;
}

