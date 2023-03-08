#include <iostream>
using namespace std;
#define ll long long
ll t,m,w[10010],v[10010],dp[10000010];

int main(){
	scanf("%d %d",&t,&m);
	for(int i = 1;i <= m;i++)
		scanf("%d %d",&w[i],&v[i]);
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= t;j++)
			if(w[i] <= j)
				dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
	printf("%lld\n",dp[t]);
	return 0;
}






























// #include <bits/stdc++.h>
// using namespace std;

// /*
// 题目描述
// LiYuxiang 是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同种类的草药，采每一种都需要一些时间，每一种也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

// 如果你是 LiYuxiang，你能完成这个任务吗？

// 此题和原题的不同点：

// 11. 每种草药可以无限制地疯狂采摘。

// 22. 药的种类眼花缭乱，采药时间好长好长啊！师傅等得菊花都谢了！
// */
// #define N 10001
// #define NN 100000002
// long long dp[NN],w[N],v[N],m,n;
// int main(){
// 	//完全背包问题
// 	cin >> m>>n;
// 	for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
// 	for(int i = 1;i <= n;i++){
// 		for(int j = 1;j <= m;j++){  //与0-1背包不同的是，完全背包的递推需要用到同行的之前状态，所以正推 
// 			if(j >= w[i]) dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
// 		}
// 	}
// 	cout << dp[m];
// 	return 0;
// }

