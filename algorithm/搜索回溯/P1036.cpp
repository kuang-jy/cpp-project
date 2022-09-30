#include <bits/stdc++.h>
using namespace std;
long long n,k,a[21],cnt,used[21],sum;

bool check(int x){
	if(x == 1 || x == 0) return false;
	if(x == 2) return true;
	for(int i = 2;i < pow(x,0.5);i++)
		if(x % i == 0) return false;
	return true;
}

void dfs(int x,int tag){  //加第x个数 i用于标记上次选的第几个，防止重复 
	if(x == k){
		if(check(sum))
			cnt++;
		return;
	}
	else{
		for(int i = 1;i <= n;i++){
			if(!used[i] && i > tag){
				sum += a[i];
				used[i] = 1;
				dfs(x+1,i);
				//回溯 
				sum -= a[i];
				used[i] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(0,0);
	cout << cnt;
	return 0;
}

