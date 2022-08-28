#include <bits/stdc++.h>
using namespace std;
#define max 200001
int n,a[max];

int maxsum(int a[],int low,int high){
	if(low == high) return a[low] > 0 ? a[low] : 0;
	int mid = low+(high-low)/2;
	int l = maxsum(a,low,mid);
	int r = maxsum(a,mid+1,high);
	int sum = 0,temp1 = -19260817,temp2 = -19260817;
	for(int i = mid;i >= low;i--){
		sum += a[i];
		if(temp1 < sum) temp1 = sum;
	}
	sum = 0;
	for(int i = mid+1;i <= high;i++){
		sum += a[i];
		if(temp2 < sum) temp2 = sum;
	}
	sum = temp1+temp2;
	return sum > l ? (sum > r ? sum : r) : (l > r ? l : r); 
} 

int main(){
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >>a[i];
	cout << maxsum(a,0,n-1) << endl;
	return 0;
}
