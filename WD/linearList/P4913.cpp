#include <bits/stdc++.h>
using namespace std;
struct node{
	int no;
	int l,r;
}tree[1000001];
int n;

int dfs(int no){
	if(!no) return 0;
	int ld = dfs(tree[no].l);
	int rd = dfs(tree[no].r);
	return max(ld,rd)+1;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		tree[i].no = i;
		cin >> tree[i].l >> tree[i].r;
	}
	cout << dfs(1);
	return 0;
}

