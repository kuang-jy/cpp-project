#include <bits/stdc++.h>
using namespace std;
int n,dis[101][101],popu[101];
/*
	���������㷨ģ���� 
*/
int main(){
	cin >>n;
	for(int i=1; i<=n; i++) {   //���ݳ�ʼ�� 
		for(int j=1; j<=n; j++) {
			dis[i][j]=1000000;
		}
	}
	
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
		cin >> popu[i];
		int a,b;
		cin >> a>>b ;
		dis[i][a] = dis[a][i] = 1;
		dis[i][b] = dis[b][i] = 1;
	}
	
	for(int i = 1;i <= n;i++){   //������ת�ڵ� 
		for(int j = 1;j <= n;j++){  //������� 
			if(i != j){    //��Ҫ�������ת 
				for(int k = 1;k <= n;k++){  //�����յ� 
					//��㲻�����յ㣬�Ҳ����յ���ת 
					if(k != j && k != i) dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
				}
			}
		}	
	}
	
	int ans = 1000000,cnt;
	for(int i = 1;i <= n;i++){   //������������ҽԺ����� 
		cnt = 0;
		for(int j = 1;j <= n;j++){   //����ÿ���������·��֮�� 
			if(i != j) cnt += popu[j]*dis[i][j];
		}
		ans = min(ans,cnt);
	}
	cout << ans;
	return 0;
}

