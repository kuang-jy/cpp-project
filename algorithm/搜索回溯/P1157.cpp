#include <bits/stdc++.h>
using namespace std;
int n,r,ans[22],vis[22];

void dfs(int i){   //���ǵ�iλ����ѡ��
	if(i > r){   //�õ�һ�ִ� 
		for(int j = 1;j <= r;j++)
			cout << setw(3) << ans[j];
		cout << endl;
		return;
	}
	for(int j = 1;j <= n;j++){
		if(j > ans[i-1] && !vis[j]){   //��֤ѡ�����ǵ�������δѡ���� 
			vis[j] = 1;
			ans[i] = j;
			dfs(i+1);   //������һλ�� 
			vis[j] = 0;   //���� 
		}
	}
}

int main(){
	cin >> n >> r;
	dfs(1);
	return 0;
}

