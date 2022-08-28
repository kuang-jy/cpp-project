#include <bits/stdc++.h>
using namespace std;
int n,a[1001],b[101],cnt;

void qsort(int b[],int low,int high){
	if(high <= low) return;
	int pivot = b[low],i = low;
	for(int j = low +1;j <= high;j++){
		if(b[j] < pivot)
			swap(b[++i],b[j]);
	}
	swap(b[i],b[low]);
	qsort(b,low,i-1);
	qsort(b,i+1,high);
}

int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		int temp;cin >> temp;
		if(a[temp] == 0){
			a[temp] = 1;
			b[cnt++] = temp;
		}
	}
	cout << cnt << endl;
	qsort(b,0,cnt-1);
	for(int i = 0;i < cnt;i++)
		cout << b[i] << " ";
	return 0;
}

