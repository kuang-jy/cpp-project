#include <bits/stdc++.h>
using namespace std;
int m,ans[14],cnt; 

bool check(int n,int r){  //����n�еĻʺ��ܷ���r�� 
	for(int i = 1;i < n;i++){
		if(ans[i] == r) return false;
		if(n-r == i-ans[i]) return false;
		if(n+r == i+ans[i]) return false;
	}
	return true;
}

void dfs(int n){  //����n�еĻʺ���λ�� 
	if(n > m){   //�ҵ�һ�����н� 
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

