#include <bits/stdc++.h>
using namespace std;

/*
	问题描述：在nxn棋盘上放置n个皇后，任何两个皇后不可以在同一行，同一列或统一斜线上。
	
	定义数组a[]，a[i]表示第i个皇后放在哪一个位置
	 
*/

#define N 10
int a[N];   //a[i]表示第i行的皇后，放在第a[i]列上
int cnt,n;

bool check(int row,int c){   //检查row行的皇后是否可以放在n列 
	for(int i = 1;i < row;i++){
		if(a[i] == c) return 0;   //检查同列 
		if(i+a[i] == row+c) return 0;   //检查副对角线 
		if(i-a[i] == row-c) return 0;    //检查主对角线 
	}
	return true;
}

void dfs(int row){  //第row行放在哪里 
	if(row > n){   //达到边界，找到了可行解 
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

