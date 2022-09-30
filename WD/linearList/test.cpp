#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int data[10];
	int len;
}sqList;

void reverse(sqList& l){
	int low = 0, high = l.len-1;
	int mid = l.len/2;
	while(low < mid){
		swap(l.data[low++],l.data[high--]);
	}
}

void reverse(int a[],int low,int high,int len){
	int l = low,r = high,mid = low+len/2;
	while(low < mid){
		swap(a[low++],a[high--]);
	}
}

bool del(sqList& l,int s,int t){
	int q = 0,p = 1;
	while(p < l.len){
		if(l.data[p] != l.data[q]){
			l.data[++q] = l.data[p];
//			cout << l.data[p] << endl;
		}
			
		p++;
	}
	l.len = q+1;
	return true;
}


int main(){
	sqList l;
	l.len = 6;
	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 2;
	l.data[3] = 3;
	l.data[4] = 3;
	l.data[5] = 5;
	int a[] = {1,2,3,4,5};
	reverse(a,1,4,5);
//	del(l,3,5);
	for(int i = 0;i < l.len;i++)
		cout << a[i];
	return 0;
}

