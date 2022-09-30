#include <bits/stdc++.h>
using namespace std;

long long n,a[11][2],ans=1000000000,sour = 1,bitter = 0,used[11];

//深度优先搜索
void dfs(int i,int tag){  //考虑第i个食材 tag标识上一步选到第几位食材，去除重复计算 
	if(i > n) return;
	for(int j = 1;j <= n;j++){
		if(j > tag && !used[j]){
			sour *= a[j][0];
			bitter += a[j][1];
			ans = min(ans,abs(sour-bitter));
			used[j] = 1;
			dfs(i+1,j);
			//回溯 
			used[j] = 0;
			sour /= a[j][0];
			bitter -= a[j][1];
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1;i<= n;i++){
		cin >> a[i][0] >> a[i][1];
		ans = min(ans,abs(a[i][0]-a[i][1]));
	}
	dfs(0,0);
	cout << ans;
	return 0;
}

