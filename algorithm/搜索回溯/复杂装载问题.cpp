#include <bits/stdc++.h>
using namespace std;

/*
	问题描述：有一批共n个集装箱要装上一艘载重量分别为c1,c2的船，其中集装箱i的重量为wi，且 Σwi <= c1+c2。
	现要求确定一个合理的装在方案可将这n个集装箱装上这2艘船。如果有，找出一种。

	步骤：
		1、将尽可能多的集装箱装到第一艘船上，得到解向量x 
		2、累计第一艘装完后剩余集装箱重量sum
		3、如果sum <= c2,返回true，否则返回false 
*/
#define maxSize 10
int maxW=0,c1=50,c2=50,n=3;
int w[] = {0,10,40,40};
int x[maxSize];

void dfs(int tw,int rw,int op[],int i){
	if(i > n){
		if(tw <= c1 && tw > maxW) maxW = tw;
		for(int i = 1;i <= n;i++) x[i] = op[i];		
	}
	else{
		if(tw+w[i] <= c1){
			op[i] = 1;
			dfs(tw+w[i],rw-w[i],op,i+1);
		}
		else{
			if(tw + rw - w[i] > maxW)
				dfs(tw,rw-w[i],op,i+1);
		}
	}
}

bool solve(){
	int sum = 0;
	for(int i = 1;i <= n;i++) 
		sum += x[i]*w[i];
	if(sum <= c2) return true;
	return false;
}

void disp(){
	for(int i = 1;i <=n;i++)
		if(x[i])
			cout << "choose #" << i << " ";
	cout << "to boat 1" << endl;
	for(int i = 1;i <=n;i++)
		if(!x[i])
			cout << "choose #" << i << " ";
	cout << "to boat 2" << endl;	
}

int main(){
	int op[maxSize];
	for(int i = 0;i < maxSize;i++)
		op[i] = 0;
	int rw = 0;
	for(int i = 1;i <= n;i++)
		rw+=w[i];
	dfs(0,rw,op,1);
	if(solve()) disp();
	else cout << "无解" << endl; 
	return 0;
}

