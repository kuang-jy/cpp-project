#include <bits/stdc++.h>
using namespace std;
int n;
double sum;

struct w{
	int no;
	int time;
}a[1001];

bool cmp(w w1,w w2){
	return w1.time < w2.time;
}
 
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].time;
		a[i].no = i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i++){
		cout << a[i].no << " ";
		sum += (n-i)*a[i].time;
	}
	cout << endl;
	printf("%.2f",sum/n);
	return 0;
}

