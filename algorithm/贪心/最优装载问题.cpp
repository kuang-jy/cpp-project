#include<bits/stdc++.h>

using namespace std;

//有一轮船能装的最大重量为c，有n个集装箱，重量分别是w[i]。要求装最多的集装箱
/*
	贪心策略：先装最轻的，再装次轻的... 
*/ 

#define INF 10000
#define maxSize 20

void sort(int n,int w[],int t[]){
	int min = INF;
	int minidx = 0;
	int arr[maxSize];
	for(int i = 0;i < n;i++) arr[i] = w[i];
	//t保存w递增序列的下标 
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)
			if(arr[j] < min){
				min = w[j];
				minidx = j;
			}
		arr[minidx] = INF;
		min = INF;
		t[i] = minidx;
	}
}

void loading(int n,int c,int w[],int ans[]){
	int t[maxSize];
	sort(n,w,t);
	int i;
	for(i = 0;i < n;i++) ans[i] = 0;
	for(i = 0;i < n && w[t[i]] <= c;i++){  
		ans[t[i]] = 1;
		c -= w[t[i]];
	}
} 

int main(){
	int truck[6]={6,5,4,3,3,9},x[maxSize];
    loading(6,14,truck,x);
    for(int i=0;i<6;++i) cout<<x[i]<<endl;
    return 0;
}

