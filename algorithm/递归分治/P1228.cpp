#include <bits/stdc++.h>
using namespace std;
int k,r,c,tag = 1;

void solve(int size,int dr,int dc,int r,int c){
	if(size == 1) return;
	int s = size/2;
	if(r < dr+s && c < dc+s){
		printf("%d %d 1\n",dr+s,dc+s);
		solve(s,dr,dc,r,c);
		solve(s,dr,dc+s,dr+s-1,dc+s);
		solve(s,dr+s,dc,dr+s,dc+s-1);
		solve(s,dr+s,dc+s,dr+s,dc+s);
	}
	else if(r < dr+s && c >= dc+s){
		printf("%d %d 2\n",dr+s,dc+s-1);
		solve(s,dr,dc,dr+s-1,dc+s-1);
		solve(s,dr,dc+s,r,c);
		solve(s,dr+s,dc,dr+s,dc+s-1);
		solve(s,dr+s,dc+s,dr+s,dc+s);
	}
	else if(r >= dr+s && c < dc + s){
		printf("%d %d 3\n",dr+s-1,dc+s);
		solve(s,dr,dc,dr+s-1,dc+s-1);
		solve(s,dr,dc+s,dr+s-1,dc+s);
		solve(s,dr+s,dc,r,c);
		solve(s,dr+s,dc+s,dr+s,dc+s);
	}
	else{
		printf("%d %d 4\n",dr+s-1,dc+s-1);
		solve(s,dr,dc,dr+s-1,dc+s-1);
		solve(s,dr,dc+s,dr+s-1,dc+s);
		solve(s,dr+s,dc,dr+s,dc+s-1);
		solve(s,dr+s,dc+s,r,c);
	}
}

int main(){
	cin >> k >> r >> c;
	k = pow(2,k);
	solve(k,1,1,r,c);
	return 0;
}

