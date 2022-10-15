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
	//dp[i]��ʾ�ڵ�i�ŵؽ�λ�ã����ռ���������� 
	for(int i = 2;i <= n;i++){  //û�еؽ����һ���ؽ��������ӵڶ����ؽѿ�ʼ 
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



















////dp���� dp[i]��ʾ��i��β�ܵõ����������
////���һ���ؽ���û��ͨ���ĵؽѵ�·�ģ����Դ����һ���ؽѿ�ʼ��ǰ���ƣ���ʼ��dp[n]=num[n] 
////״̬ת�ƣ�dp[i] = max{dp[j]}+num[i]; 
////������dp�����ҵ��������� 
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
//		dp[i] = num[i];   //˳���ʼ��dp���� 
//	}
//
//	for(int i = 1; i <= n-1;i++)
//		for(int j = i+1;j <= n;j++)
//			cin >> link[i][j];
//			
//	for(int i = 2;i <= n;i++){    //�����յ���� 
//		for(int j = 1;j < i;j++){
//			if(link[j][i] && dp[i] < dp[j]+num[i]){   //���������ͨ���Ҵ�j�ڵ�i�ɵõ�������������ô����dp������¼·�� 
//				dp[i] = dp[j]+num[i];
//				path[i] = j;
//			}
//		}
//		if(ans < dp[i]){    //���´� 
//			ans = dp[i];
//			pos = i;   //��¼���Ľ�β 
//		}
//	}
//	dfs(pos);
//	cout << endl << ans;
//	return 0;
//}
