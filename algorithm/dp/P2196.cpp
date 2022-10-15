#include <algorithm>
#include <iostream>
using namespace std;
int n,num[21],dis[21][21],dp[21];

void trackback(int path[],int end){
	if(path[end] == end) {
		cout << end << " "; 
		return;
	}
	trackback(path,path[end]);
	cout << end << " ";
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> num[i];
		dp[i] = num[i];
	}
	for(int i = 1;i < n;i++)
		for(int j = i+1;j <= n;j++)
			cin >> dis[i][j];
	int ans = -1e7,path[21],end;
	for(int i = 1;i <= n;i++) path[i] = i;
	//dp[i]表示挖到i号地窖位置，可收集的最大数量 
	for(int i = 2;i <= n;i++){  //没有地窖与第一个地窖相连，从第二个地窖开始 
		int m = 0,idx = 1;
		for(int j = 1;j <= n;j++){
			if(dis[j][i] && m < dp[j]) {
				m = dp[j];
				path[i] = j;
			}
		}
		dp[i] += m;
		if(ans < dp[i]){
			ans = dp[i];
			end = i;
		}
	}
	trackback(path,end);
	cout << endl << ans;
	return 0;
}



















////dp定义 dp[i]表示以i结尾能得到的最大数量
////最后一个地窖是没有通向别的地窖的路的，所以从最后一个地窖开始向前逆推，初始化dp[n]=num[n] 
////状态转移：dp[i] = max{dp[j]}+num[i]; 
////最后遍历dp数组找到最大地雷数 
//int dp[21],link[21][21],n,num[21],path[21],ans,pos;
//
//void dfs(int i){
//	if(!i) return;
//	dfs(path[i]);
//	cout << i << " ";
//	
//}
//
//int main(){
//	cin >> n;
//	for(int i = 1;i <= n;i++){
//		cin >> num[i];
//		dp[i] = num[i];   //顺便初始化dp数组 
//	}
//
//	for(int i = 1; i <= n-1;i++)
//		for(int j = i+1;j <= n;j++)
//			cin >> link[i][j];
//			
//	for(int i = 2;i <= n;i++){    //所有终点可能 
//		for(int j = 1;j < i;j++){
//			if(link[j][i] && dp[i] < dp[j]+num[i]){   //如果两点联通，且从j挖到i可得到更大数量，那么更新dp，并记录路径 
//				dp[i] = dp[j]+num[i];
//				path[i] = j;
//			}
//		}
//		if(ans < dp[i]){    //更新答案 
//			ans = dp[i];
//			pos = i;   //记录最大的结尾 
//		}
//	}
//	dfs(pos);
//	cout << endl << ans;
//	return 0;
//}
