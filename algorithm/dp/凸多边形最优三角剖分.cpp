#include<bits/stdc++.h>

using namespace std;

/*
	给定凸多边形P，以及定义在由多边形的边和弦组成的三角形上的权函数w。要求确定该凸多边形的三角剖分，使得该三角剖分中诸三角形上权之和为最小。
	
	若凸(n+1)边形P={V0,V1……Vn}的最优三角剖分T包含三角形V0VkVn,1<=k<=n，
	则T的权为三个部分权之和：三角形V0VkVn的权，{V0,V1……Vk}的权和{Vk,Vk+1……Vn}的权之和。
	由T确定的这两个子多边形的三角剖分也是最优的。
	
	设t[i][j],1<=i<j<=n为凸多边形{Vi-1,Vi……Vj}的最优三角剖分所对应的权值函数值，即其最优值。
	最优剖分包含三角形Vi-1VkVj的权，子多边形{Vi-1,Vi……Vk}的权，子多边形{Vk，Vk+1……Vj}的权之和。
	 
*/
#define N 100
int weight[N][N] = {{0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},{3,5,2,0,6,2},
{1,2,1,6,0,1},{4,3,4,2,1,0}};  //记录各顶点间权值 
int dp[N][N];  //记录最优值 
int s[N][N];  //记录剖分策略 

//剖分三角形的周长
int get_weight(int a, int b, int c)
{
    return weight[a][b] + weight[b][c] + weight[c][a];
}

void triangleDivide(int n){
	for(int i = 1;i <= n;i++) dp[i][i] = 0;  //初始化对角线为0，只有一条边是不能被三角划分的 
	for(int l = 2;l <= n;l++){		//问题规模 
		for(int i = 1;i <= n-l+1;i++){   //起点边 
			int j = i+l-1;   	//终点边 
			dp[i][j] = dp[i][i] + dp[i+1][j] + get_weight(i-1,i,j);
			s[i][j] = i;
			for(int k = i+1;k < j;k++){
				int temp = dp[i][k] + dp[k+1][j] + get_weight(i-1,k,j);
				if(temp < dp[i][j]){
					dp[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][n-1];
}

int main(){
	triangleDivide(6);
    return 0;
}

