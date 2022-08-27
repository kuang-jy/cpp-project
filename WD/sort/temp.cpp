#include <bits/stdc++.h>
using namespace std;

struct a{
    int x,y,h;
}b[10001];

int r,c,dp[101][101],n[101][101];
int dx[] = {0,0,1,-1};//方向增量
int dy[] = {1,-1,0,0};

bool cmp(a a1,a a2){
    return a1.h > a2.h;
}

int main(){
    cin >> r >> c;
    int k = 0;
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++){
            cin >> n[i][j];
            dp[i][j] = 1;  //初始长度1
            b[++k].h = n[i][j];
            b[k].x = i;
            b[k].y = j;
        }
    sort(b+1,b+1+k,cmp);  //高度升序排列
    int m = 1;
    for(int i = 1;i <= k;i++){
        for(int j = 0;j < 4;j++){  //四个方向
            int xx = b[i].x+dx[j];
            int yy = b[i].y+dy[j];
            if(xx >= 1 && yy >= 1 && xx <= r && yy <= c && b[i].h > n[xx][yy]){
                dp[b[i].x][b[i].y] = max(dp[xx][yy]+1,dp[b[i].x][b[i].y]);
                m = m > dp[b[i].x][b[i].y] ? m : dp[b[i].x][b[i].y];
            }
        }
    }
    cout << m;
    return 0;
}
