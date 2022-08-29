#include <bits/stdc++.h>
using namespace std;
int a[30],k = 0;
long long s =0;

int main(){
	while(cin >> a[k++]);
	for(int j=0;j<k;j++){
        s+=a[j];
    }
    s*=pow(2,k-2);
    cout<<s;
	return 0;
}

