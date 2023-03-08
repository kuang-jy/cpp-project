#include <iostream>
using namespace std;
int n,k,arr[5000010];

void swap(int& a,int& b){
	int t = a;
	a = b;
	b = t;
}

int partition(int low,int high){
	//一趟划分
	int pivot = arr[low],i = low;
	for(int j = low+1;j <= high;j++)
		if(arr[j] < pivot)
			swap(arr[j],arr[++i]);
	swap(arr[i],arr[low]);
	//递归分治求解
	if(i == k) return i;
	else if(i > k) return partition(low,i-1);
	return partition(i+1,high);
}

int main(){
	scanf("%d %d",&n,&k);
	k++;
	for(int i = 1;i <= n;i++) scanf("%d",&arr[i]);
	printf("%d\n",arr[partition(1,n)]);
	return 0;
}