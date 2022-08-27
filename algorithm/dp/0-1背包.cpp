#include<bits/stdc++.h>

using namespace std;
/*
	01背包问题可描述为如下问题：
	有一个容量为V的背包，还有n个物体。现在忽略物体实际几何形状，我们认为只要背包的剩余容量大于等于物体体积，那就可以装进背包里。每个物体都有两个属性，即体积w和价值v。
	问：如何向背包装物体才能使背包中物体的总价值最大？
	
	Vi表示第 i 个物品的价值，Wi表示第 i 个物品的体积
	定义V(i,j)：当前背包容量 j，前 i 个物品最佳组合对应的价值，同时背包问题抽象化（X1，X2，…，Xn，其中 Xi 取0或1，表示第 i 个物品选或不选）。
	
	dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
	
	要到达V(i,j)这一个状态
		第一种是第i件商品没有装进去，第二种是第i件商品装进去了。
		没有装进去，就是V(i-1,j)；
		装进去了，那么装入之前是什么状态，肯定是V(i-1,j-w(i))。由于最优性原理，V(i-1,j-w(i))就是前面决策造成的一种状态，后面的决策就要构成最优策略。两种情况进行比较，得出最优。

	
*/

#define N 100
int dp[N][N];
int w[N],v[N];

void knap(int n,int weight){
	//初始化dp数组 
	for(int i = 0;i <= n;i++) dp[i][0] = 0;
	for(int i = 0;i <= weight;i++) dp[0][i] = 0;
	
	for(int i = 1;i <= n;i++){  //遍历物品 
		for(int j = 1;j <= weight;j++){  //遍历容量 
			if(w[i-1] > j) dp[i][j] = dp[i-1][j];  //当前物品装不下 
			else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
		}
	}
	cout << dp[n][weight] << endl;
}

int dpdp[N];
//后无效性 优化0/1背包
void bestKnap(int n,int weight){
	for(int i = 1;i <= n;i++){
		for(int j = weight;j >= 0;j--){   //0-1背包需要用到上一物品的状态，需要从后向前推 
			if(j >= w[i-1]) dpdp[j] = max(dpdp[j],dpdp[j-w[i-1]]+v[i-1]);
		}
		
		for(int j = 0;j <= weight;j++)   //打印数组 
			cout << dpdp[j] << " ";
		cout << endl; 
	}
	cout << dpdp[weight] << endl;
} 

void traceBack(int i,int j){
	if(i == 0 || j == 0) return;
	if(dp[i][j] == dp[i-1][j]){
		traceBack(i-1,j);
	}
	else if(dp[i][j] == dp[i-1][j-w[i-1]]+v[i-1]){
		traceBack(i-1,j-w[i-1]);
		cout << i << " ";
	}
}
 
int main(){
	/*
	3 4
	1 15
	3 20
	4 30
	*/
	int n, weight;  //n个物品，背包最大容量weight 
	cin >> n >> weight;
	for(int i = 0;i < n;i++){
		cin >> w[i] >> v[i];  //输入重量和价值 
	}
	knap(n,weight);
	traceBack(n,weight);
	bestKnap(n,weight);
    return 0;
}

