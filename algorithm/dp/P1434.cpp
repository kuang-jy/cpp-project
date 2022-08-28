#include <bits/stdc++.h>
using namespace std;

int r,c;
int dp[10001];  //dp[]定义: dp[i]标识第i个点的最长滑坡的长度   dp[i] = max{dp[j]+1,dp[i]}  需要从低向高算 
int dx[4]={0,0,1,-1};//记录方向增量的数组
int dy[4]={1,-1,0,0};

struct snow{
	int x,y,h;  //坐标和高度 
}a[10001];
bool cmp(snow x,snow y){return x.h>y.h;}//按高度降序排序

int main(){
	cin >> r >> c;
	int k = 0;
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++){
			cin >> a[++k].h;
			dp[k] = 1;  //初始高度为1 
			a[k].x = i;
			a[k].y = j; 
		}
	sort(a+1,a+1+k,cmp);//排序
		for(int i = 1;i <= k ;i++)
		cout << a[i].h <<endl;
	int m = 1;
	for(int i=1;i<=k;i++){    //开始dp 
        for(int j=i-1;j>0;j--){
            for(int u=0;u<4;u++){   //枚举方向，看i与j是否相邻 
        		if(a[i].x+dx[u]==a[j].x && a[i].y+dy[u]==a[j].y && a[j].h>a[i].h) {
        			dp[i]=max(dp[i],dp[j]+1);
        			//如果当前处理的两个点相邻，并且j的高度大于i，则可以考虑状态转移 
        			m = m > dp[i] ? m : dp[i];
				}
        	}
    	}
    }
    
    cout << m;
	return 0;
}

