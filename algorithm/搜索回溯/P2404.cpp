#include <bits/stdc++.h>
using namespace std;
int n,cnt,ans[8];

void dfs(int sum,int k){   //k���ڼ�¼��һ����������� 
	if(sum == n && cnt != 1){
		for(int i = 0;i < cnt-1;i++)
			cout << ans[i] << "+";
		cout << ans[cnt-1]<< endl; 
		return;
	}
	if(sum > n) return;  //�ӹ�ͷ 
 	for(int i = 1;i <= 9;i++){
 		if(i >= k){   	//�ֵ������ 
 			ans[cnt++] = i;
			dfs(sum+i,i);
			cnt--;
		}
	}
}

int main(){
	cin >> n;
	dfs(0,0);
	return 0;
}

