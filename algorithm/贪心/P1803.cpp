#include <bits/stdc++.h>
using namespace std;
int n,cnt=1;
struct a{
	int s,e;
}aa[1000001];

bool cmp(a a1,a a2){
	return a1.e < a2.e;
}

int main(){
	cin >> n;
	for(int i =1;i<= n;i++)
		cin >> aa[i].s >> aa[i].e;
	sort(aa+1,aa+1+n,cmp);
	int pre = 1;
	for(int i = 2;i<=n;i++){
		if(aa[pre].e <= aa[i].s){
			cnt++;
			pre = i;
		}
	}
	cout << cnt;
	return 0;
}

