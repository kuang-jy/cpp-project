#include <bits/stdc++.h>
using namespace std;
int a[2000001];

int partition(int a[],int low ,int high){
	int pivot = a[low];
	int i = low;
	for(int j = low+1;j <= high;j++)
		if(a[j] < pivot)
			swap(a[++i],a[j]);
	swap(a[i],a[low]);
	return i;
}

void sort(int a[],int low,int high){
	if(low > high) return;
	int pivot = partition(a,low,high);
	sort(a,low,pivot-1);
	sort(a,pivot+1,high);
}

int main(){
	int n,m,temp;
	cin >> n >> m;
	for(int i = 0;i < m;i++)
		cin >> a[i+1];
	sort(a,1,m);
	for(int i = 1;i <= m;i++)
		cout << a[i] << " ";
	return 0;
}

