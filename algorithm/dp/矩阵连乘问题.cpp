#include<bits/stdc++.h>

using namespace std;


//矩阵连乘问题
//给定n个矩阵｛A1,A2,…,An｝，其中Ai与Ai+1是可乘的，i=1，2…，n-1。
//如何确定计算矩阵连乘积的计算次序，使得依此次序计算矩阵连乘积需要的相乘次数最少 
/*
	将Ai*Ai+1*...*Aj简记为A[i:j]，其中Ai的维度记为pi-1*pi
 	计算目的是求解A[1:n]的最优解，而一个最优策略的子策略也是最优的，所以题目可分解为求A[i:j]的最优计算次序
	设AiAi+1…Aj的最优计算次序在矩阵Ak和Ak+1之间将矩阵链断开得到：(Ai… Ak) (Ak+1 …Aj)
	总的计算量就是：A[i:k]的计算量＋A[k+1: j]的计算量+A[i:k]和A[k+1:j]相乘的计算量
*/ 

//p存放Ai的维数，pi个矩阵的维度是 pi-1*pi 
//m存放最小乘法次数
//s存放断链位置 

#define N 7  //N为7，实际6个矩阵 0行0列忽略 

void MatrixChain(int p[],int n,int m[][N],int s[][N]){
	for(int i = 1;i <= n;i++) m[i][i] = 0;  //矩阵链只有一个矩阵时，初始化对角线为0
	
	for(int l=2;l<=n;l++) {		//l表示矩阵链的长度
		for(int i = 1;i <= n-l+1;i++){   //根据上层循环的链长，控制连乘的起始点 
			int j = i+l-1;  //末尾矩阵编号
			m[i][j] = m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];  //默认最好的划分方案是从第一个矩阵后断开，之后有更好的再更新 
			s[i][j] = i;
			for(int k = i+1;k < j;k++){  //从i+1开始断链计算 
				int temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];  
				if(temp < m[i][j]){
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		} 
	} 
}

void TraceBack(int i, int j, int s[][N]){
	if(i == j) cout <<"A"<<i;
	else{
		cout << "(";
		TraceBack(i,s[i][j],s);
		TraceBack(s[i][j]+1,j,s);
		cout << ")";
	}
}

int main(){
	int p[N] = {30,35,15,5,10,20,25};  //矩阵维度
	int m[N][N],s[N][N];
	MatrixChain(p,N-1,m,s);
	TraceBack(1,6,s);
	cout << endl << m[1][N-1] << endl;
    return 0;
}

