#include <bits/stdc++.h>
using namespace std;

//马的位置增量 
const int dx[] = {-2,-2,-1,-1,0,1,1,2,2};
const int dy[] = {-1,1,-2,2,0,-2,2,-1,1};
//dp定义：dp[i][j]表示从(0,0)走到(i,j)的方案总数
//状态转移：dp[i][j] = dp[i-1][j]+dp[i][j-1] 
long long dp[21][21] = {1};
bool flag[21][21];

int main(){
	int bx,by,mx,my;
	cin >> bx >> by >> mx >> my;
	for(int i = 0;i < 9;i++)
		if(mx+dx[i] >= 0 && my+dy[i] >= 0 && mx+dx[i] <= 20 && my+dy[i] <= 20)
			flag[mx+dx[i]][my+dy[i]] = 1;
			
	for(int i = 0;i <= bx;i++){
		for(int j = 0;j <= by;j++){
			if(!flag[i][j]){  //如果没有被马控制 
				if(i) dp[i][j] += dp[i-1][j];
				if(j) dp[i][j] += dp[i][j-1];
			}
		}
	}
	cout << dp[bx][by] << endl;
	return 0;
}

