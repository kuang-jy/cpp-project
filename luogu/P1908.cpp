#include <bits/stdc++.h>
using namespace std;
int n,arr[500000],a[500000];
long long cnt;

void merge(int a[],int low,int mid ,int high){
	int i,j,k;
	for(i = low;i <= high;i++) arr[i] = a[i];
	for(i = low,j = mid+1,k = low;i <= mid && j <= high;k++){
		if(arr[i] <= arr[j]) a[k] = arr[i++];
		else {
			cnt+=mid-i+1;
			a[k] = arr[j++];
		}
	}
	while(i <= mid) a[k++] = arr[i++];
	while(j <= high) a[k++] = arr[j++];
}

void ms(int a[],int low ,int high){
	if(low >= high) return;
	int mid = (low+high)/2;
	ms(a,low,mid);
	ms(a,mid+1,high);
	merge(a,low,mid,high);
}

int main(){
	cin >> n;
	for(int i = 0;i <n ;i++)
		cin >> a[i];
	ms(a,0,n-1);
	cout << cnt << endl;
	return 0;
}

