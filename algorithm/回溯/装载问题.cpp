#include <bits/stdc++.h>
using namespace std;

/*
	问题描述：有一批共n个集装箱要装上一艘载重量为c的船，其中集装箱i的重量为wi，且 Σwi <= c。
	现要求确定一个合理的装在方案可将这n个集装箱装上这艘船，且集装箱个数尽可能少。如果有，找出一种。 
*/
#define maxSize 10
#define INF 1000
int w[] = {0,5,2,6,4,3};
int n = 5,c = 10;
int maxW;  //存放最优解的总重量
int x[maxSize];  //存放最优解向量 
int minNum = INF;   //存放最优解的集装箱个数

void dfs(int num,int tw,int rw,int op[],int i){	  //num已选择集装箱个数，tw选择的重量总和，rw剩余的重量总和，op表示一个解向量，i正在考虑的集装箱i
	if(i > n){  //说明所有集装箱都被判断完了，一定是一个可行解，验证是否最优解 
		if(tw > maxW && num < minNum){   //判断是否更新最优解 
			maxW = tw;
			minNum = num; 
			for(int i = 1;i <= n;i++) x[i] = op[i];  //复制选择向量 
		}
	}
	else{  //判断是否拓展当前集装箱 
		if(tw+w[i] <= c){    //剪枝函数1 
			op[i] = 1;
			dfs(num+1,tw+w[i],rw-w[i],op,i+1);  //进入下一个集装箱判断 
		}
		if(tw+rw-w[i] >= c)  //剪枝函数2
			dfs(num,tw,rw-w[i],op,i+1); 
	} 
} 

void disp(){
	for(int i = 1;i <= n;i++)
		if(x[i])
			cout << "select #" << i << " ";
	cout << endl;
	cout << maxW << endl << minNum << endl; 
}

int main(){
	int op[maxSize];
	for(int i = 0;i < maxSize;i++) op[i] = 0;
	int rw = 0;
	for(int i = 1;i <= n;i++) rw += w[i];
	dfs(0,0,rw,op,1);
	disp();
	return 0;
}

