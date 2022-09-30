#include <bits/stdc++.h>
using namespace std;

void getMinMax(int a[],int low,int high,int& ma,int& mi){
	if(high-low <= 1){
		if(a[low] <= a[high]){
			ma = a[high];
			mi = a[low];
		}
		else{
			ma = a[low];
			mi = a[high];
		}
		return;
	}
	int m1,m2,s1,s2,mid = (low+high)/2;
	getMinMax(a,low,mid,m1,s1);
	getMinMax(a,mid+1,high,m2,s2);
	ma = m1 > m2 ? m1 : m2;
	mi = s1 < s2 ? s1 : s2;
	return;
}

int main(){
	int a[] = {1,2,3,4,5,6};
	int x,y;
	getMinMax(a,0,5,x,y);
	cout << x << " " << y << endl;
	return 0;
}

