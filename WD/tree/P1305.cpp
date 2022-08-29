#include <bits/stdc++.h>
using namespace std;

struct tNode{
	char data;
	int l,r;
}tree[27];

int n;

void preOrder(int root){
	cout << tree[root].data;
	if(tree[root].l != 0) preOrder(tree[root].l);
	if(tree[root].r != 0) preOrder(tree[root].r);
}

int main(){
	cin >> n;
	int root;
	char a,b,c;
	for(int i = 1;i<=n;i++){
		cin >> a>> b>> c;
		if(i == 1) 
			root = a-'a'+1;
		tree[a-'a'+1].data = a;
		if(b != '*')
			tree[a-'a'+1].l = b-'a'+1;
		if(c != '*')
			tree[a-'a'+1].r = c-'a'+1;
	}
	preOrder(root);
	return 0;
}

