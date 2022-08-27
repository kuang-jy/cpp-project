#include <bits/stdc++.h>
using namespace std;
int n,k,a[5000001];

int partition(int a[],int low,int high,int k){
	int pivot = a[low],i = low;
	for(int j = low+1;j <= high;j++){
		if(a[j] < pivot)
			swap(a[++i],a[j]);
	}
	swap(a[i],a[low]);
	if(i == k) return i;
	if(i < k) return partition(a,i+1,high,k);
	return partition(a,low,i-1,k);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	cout << a[partition(a,0,n-1,k)] << endl;
	return 0;
}

