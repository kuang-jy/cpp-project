#include <iostream>
#include <algorithm>
using namespace std;
int r,c,dp[10010];
const int dx[] = {-1,1,0,0},dy[] = {0,0,1,-1};   //位置增量  

struct node{
	int x,y,h;
}map[10010];

bool cmp(node n1,node n2){   //按高度降序排列 
	return n1.h > n2.h;
}

int main(){
	cin >> r >> c;
	int k = 0,ans = 1;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			map[k].x = i;
			map[k].y = j;
			cin >> map[k++].h;
		}
	}
	sort(map,map+k,cmp);
	for(int i = 0;i < k;i++) dp[i] = 1;  //初始化每个点的滑行距离都是1
	for(int i = 1;i < k;i++){    //更新当前点 
		for(int j = i-1;j >= 0;j--){   //枚举所有高度高于当前点的点 
			if(map[j].h == map[i].h) continue;
			for(int l = 0;l < 4;l++){   //四个方向 
				if(map[j].x+dx[l] == map[i].x && map[j].y+dy[l] == map[i].y)  //如果可以滑到
					dp[i] = max(dp[j]+1,dp[i]);
					ans = max(ans,dp[i]);
			}
		}	
	} 
	printf("%d",ans);
	return 0;
}





//int r,c;
//int dp[10001];  //dp[]定义: dp[i]标识第i个点的最长滑坡的长度   dp[i] = max{dp[j]+1,dp[i]}  需要从低向高算 
//int dx[4]={0,0,1,-1};//记录方向增量的数组
//int dy[4]={1,-1,0,0};
//
//struct snow{
//	int x,y,h;  //坐标和高度 
//}a[10001];
//bool cmp(snow x,snow y){return x.h>y.h;}//按高度降序排序
//
//int main(){
//	cin >> r >> c;
//	int k = 0;
//	for(int i = 1;i <= r;i++)
//		for(int j = 1;j <= c;j++){
//			cin >> a[++k].h;
//			dp[k] = 1;  //初始高度为1 
//			a[k].x = i;
//			a[k].y = j; 
//		}
//	sort(a+1,a+1+k,cmp);//排序
//		for(int i = 1;i <= k ;i++)
//		cout << a[i].h <<endl;
//	int m = 1;
//	for(int i=1;i<=k;i++){    //开始dp 
//        for(int j=i-1;j>0;j--){
//            for(int u=0;u<4;u++){   //枚举方向，看i与j是否相邻 
//        		if(a[i].x+dx[u]==a[j].x && a[i].y+dy[u]==a[j].y && a[j].h>a[i].h) {
//        			dp[i]=max(dp[i],dp[j]+1);
//        			//如果当前处理的两个点相邻，并且j的高度大于i，则可以考虑状态转移 
//        			m = m > dp[i] ? m : dp[i];
//				}
//        	}
//    	}
//    }
//    
//    cout << m;
//	return 0;
//}

