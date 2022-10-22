#include <bits/stdc++.h>
using namespace std;
int n,m,q,rela[20010];

int find(int a){
	while(a != rela[a]) a = rela[a];
	return a;
}

void Union(int a,int b){
	rela[find(a)] = find(b);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++) rela[i] = i;
	for(int i = 1;i <= m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		Union(x,y);
	}
	cin >> q;
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(find(x) != find(y)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

