#include <iostream>
using namespace std;
int n,e,i,a,b,c,uni[110];

struct node{
	int f,t,w;
}edges[10010];

int find(int a){
	if(uni[a] == a) return a;
	uni[a] = find(uni[a]);
	return uni[a];
}
void Union(int a,int b){
	uni[find(a)] = uni[find(b)];
}

void swap(node& n1,node& n2){
	node n = n1;
	n1 = n2; 
	n2 = n;
}

int partition(int low,int high){
	int k = low;
	node pivot = edges[k];
	for(int j = low+1;j <= high;j++)
		if(edges[j].w < pivot.w)
			swap(edges[++k],edges[j]);
	swap(edges[low],edges[k]);
	return k;
}

void qsort(int low,int high){
	if(low >= high) return ;
	int pivot = partition(low,high);
	qsort(low,pivot-1);
	qsort(pivot+1,high);
}

int main(){
	scanf("%d%d",&n,&e);
	for(int j = 1;j <= n;j++) uni[j] = j;
	for(int j = 1;j <= e;j++){
		scanf("%d%d%d",&a,&b,&c);
		if(a > b){
			int temp = a;
			a = b;
			b = temp;
		}
		edges[j].f = a;
		edges[j].t = b;
		edges[j].w = c;
	}
	//克鲁斯卡尔
	qsort(1,e);
	for(int j = 1;j <= e;j++){
		int a = edges[j].f, b = edges[j].t;
		if(find(a) != find(b)){
			printf("%d %d\n",a,b);
			Union(a,b);
		}
	}
	return 0;
}





















// #include <bits/stdc++.h>
// #include <algorithm>
// using namespace std;
// int n,e,s[110],num;

// struct node{
// 	int from,to,w;
// }path[1000000],ans[1000000];

// int find(int a){
// 	while(s[a] != a) a= s[a];
// 	return a;
// }

// void Union(int a,int b){
// 	s[find(a)] = find(b);
// }

// void swap(node& a,node& b){
// 	node tmp = a;
// 	a = b;
// 	b = tmp;
// }

// int partition(int low,int high){
// 	node pivot = path[low];
// 	int i = low;
// 	for(int j = low+1;j <= high;j++)
// 		if(path[j].w < pivot.w) swap(path[++i],path[j]);
// 	swap(path[i],path[low]);
// 	return i;
// }

// void qsort(int low,int high){
// 	if(low >= high) return;
// 	int pivot = partition(low,high);
// 	qsort(low,pivot-1);
// 	qsort(pivot+1,high);
// }

// bool cmp(node a,node b){
// 	if(a.from == b.from) return a.to < b.to;
// 	return a.from < b.from;
// }

// int main(){
// 	cin >> n >> e;
// 	for(int i = 0;i < e;i++){
// 		int f,t;
// 		cin >>f >>t;
// 		if(f > t){
// 			int temp = f;
// 			f = t;
// 			t = temp;
// 		}
// 		path[i].from = f;
// 		path[i].to = t;
// 		cin >> path[i].w;
// 	}
// 	qsort(0,e-1);
// 	for(int i = 1;i <= n;i++) s[i] = i;
// 	for(int i = 0;i < e;i++)
// 		if(find(path[i].from) != find(path[i].to)){
// 			Union(path[i].from,path[i].to);
// 			ans[num++] = path[i];
// 		}
// 	sort(ans,ans+num,cmp);
// 	for(int i =0;i < num;i++)
// 		printf("%d %d\n",ans[i].from,ans[i].to);
// 	return 0;
// }

