#include <bits/stdc++.h>
using namespace std;
#define INF 100000
int s[5],a[5][21],ans,mincost=INF,l,r;

void dfs(int n,int i){   //��n��ѧ�Ƶĵ�i�� 
	if(i > s[n]){
		mincost = min(mincost,max(l,r));   //�Ƿ���¿��н� 
		return;
	}
	else{
		l+=a[n][i];  //��i�ŷ����� 
		dfs(n,i+1);  //����һ��
		l-=a[n][i];  //���Ի���
		r+=a[n][i];  //��i�ŷ����� 
		dfs(n,i+1);  //������һ��
		r-=a[n][i];  //���Ի��� 
	}
}

int main(){
	cin >> s[1]>>s[2]>>s[3]>>s[4];
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= s[i];j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= 4;i++){
		dfs(i,1);
		ans += mincost;
		mincost = INF;	
	}
	cout << ans;
	return 0;
}

