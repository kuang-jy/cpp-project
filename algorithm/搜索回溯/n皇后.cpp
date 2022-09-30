#include <bits/stdc++.h>
using namespace std;

/*
	������������nxn�����Ϸ���n���ʺ��κ������ʺ󲻿�����ͬһ�У�ͬһ�л�ͳһб���ϡ�
	
	��������a[]��a[i]��ʾ��i���ʺ������һ��λ��
	 
*/

#define N 10
int a[N];   //a[i]��ʾ��i�еĻʺ󣬷��ڵ�a[i]����
int cnt,n;

bool check(int row,int c){   //���row�еĻʺ��Ƿ���Է���n�� 
	for(int i = 1;i < row;i++){
		if(a[i] == c) return 0;   //���ͬ�� 
		if(i+a[i] == row+c) return 0;   //��鸱�Խ��� 
		if(i-a[i] == row-c) return 0;    //������Խ��� 
	}
	return true;
}

void dfs(int row){  //��row�з������� 
	if(row > n){   //�ﵽ�߽磬�ҵ��˿��н� 
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(a[i] == j) cout << " # ";
				else cout << " O ";
			}
			cout << endl;
		}
		cnt++;
		return;		
	}
	for(int i = 1;i <= n;i++){
		if(check(row,i)){
			a[row] = i;
			dfs(row+1);
		}
	}
} 

int main(){
	cin >> n;
	dfs(1);
	cout << cnt << endl;
	return 0;
}

