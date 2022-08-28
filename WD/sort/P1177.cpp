#include<iostream>
#pragma GCC optimize(2)
using namespace std;

int n,a[100001];

void qsort(int a[],int low,int high){
	if(high < low) return;
	int pivot = a[low],i = low,j = high;
	while(i < j){
		while(i < j && a[j] >= pivot) j--;
		a[i] = a[j];
		while(i < j && a[i] <= pivot) i++;
		a[j] = a[i];
	}
	a[i] = pivot;
	qsort(a,low,i-1);
	qsort(a,i+1,high);
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	qsort(a,0,n-1);
	for(int i = 0;i < n;i++)
		cout << a[i] << " ";
	return 0;
}

