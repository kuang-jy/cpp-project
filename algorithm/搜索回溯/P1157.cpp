#include <bits/stdc++.h>
using namespace std;
int n,r,ans[22],vis[22];

void dfs(int i){   //考虑第i位数的选择
	if(i > r){   //得到一种答案 
		for(int j = 1;j <= r;j++)
			cout << setw(3) << ans[j];
		cout << endl;
		return;
	}
	for(int j = 1;j <= n;j++){
		if(j > ans[i-1] && !vis[j]){   //保证选的数是递增，且未选过的 
			vis[j] = 1;
			ans[i] = j;
			dfs(i+1);   //考虑下一位数 
			vis[j] = 0;   //回溯 
		}
	}
}

int main(){
	cin >> n >> r;
	dfs(1);
	return 0;
}

