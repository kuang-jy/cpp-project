#include <iostream>
using namespace std;

const int dx[] = {2,-2,1,-1,2,-2,1,-1,0},dy[] = {1,1,2,2,-1,-1,-2,-2,0};   //���λ������ 
int map[25][25],mx,my,n,m;
long long dp[25][25];

int main(){
	cin >> n >> m >> mx >> my;
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= m;j++)
			map[i][j] = 0;
	for(int i = 0;i < 9;i++)
		if(mx+dx[i] >= 0 && my+dy[i] >= 0 && mx+dx[i] <= n && my+dy[i] <= m)
			map[mx+dx[i]][my+dy[i]] = 1;  //�����ɴ��λ��	
	bool flag = false;
	for(int i = 0;i <= n;i++){
		if(map[i][0] == 1) flag = 1;
		if(flag) dp[i][0] = 0;
		else dp[i][0] = 1;
	}
	flag = false;
	for(int i = 0;i <= m;i++){
		if(map[0][i] == 1) flag = 1;
		if(flag) dp[0][i] = 0;
		else dp[0][i] = 1;
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(map[i][j] != 1)
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
			else 
				dp[i][j] = 0;
	cout << dp[n][m];
	return 0;
}















////���λ������ 
//const int dx[] = {-2,-2,-1,-1,0,1,1,2,2};
//const int dy[] = {-1,1,-2,2,0,-2,2,-1,1};
////dp���壺dp[i][j]��ʾ��(0,0)�ߵ�(i,j)�ķ�������
////״̬ת�ƣ�dp[i][j] = dp[i-1][j]+dp[i][j-1] 
//long long dp[21][21] = {1};
//bool flag[21][21];
//
//int main(){
//	int bx,by,mx,my;
//	cin >> bx >> by >> mx >> my;
//	for(int i = 0;i < 9;i++)
//		if(mx+dx[i] >= 0 && my+dy[i] >= 0 && mx+dx[i] <= 20 && my+dy[i] <= 20)
//			flag[mx+dx[i]][my+dy[i]] = 1;
//			
//	for(int i = 0;i <= bx;i++){
//		for(int j = 0;j <= by;j++){
//			if(!flag[i][j]){  //���û�б������ 
//				if(i) dp[i][j] += dp[i-1][j];
//				if(j) dp[i][j] += dp[i][j-1];
//			}
//		}
//	}
//	cout << dp[bx][by] << endl;
//	return 0;
//}

