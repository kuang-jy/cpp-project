#include <bits/stdc++.h>
using namespace std;
int n,i;
string m = "",x;

int main(){
	cin >> n;
	for(int j = 0;j < n;j++){
		cin >> x;
		int s1 = m.size();
		int s2 = x.size();
		if(s2 > s1 || (s2 == s1 && m < x)){
			m = x;
			i = j+1;
		}
	}
	cout << i << endl << m << endl;
	return 0;
}

