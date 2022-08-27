#include <bits/stdc++.h>
using namespace std;
int m,ans[14],cnt; 

bool check(int n,int r){  //检查第n行的皇后能否在r列 
	for(int i = 1;i < n;i++){
		if(ans[i] == r) return false;
		if(n-r == i-ans[i]) return false;
		if(n+r == i+ans[i]) return false;
	}
	return true;
}

void dfs(int n){  //给第n行的皇后找位置 
	if(n > m){   //找到一个可行解 
		if(cnt <= 2){
			for(int i = 1;i <= m;i++)
				cout << ans[i] << " ";
			cout << endl;
		}
		cnt++;
	}
	else{
		for(int i = 1;i <= m;i++){
			if(check(n,i)){
				ans[n] = i;
				dfs(n+1);
			}
		}
	}
}

int main(){
	cin >> m;
	dfs(1);
	cout << cnt;
	return 0;
}

