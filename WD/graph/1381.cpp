#include <iostream>
#include <vector>
#include <cstring>
#define INF 11000
using namespace std;
int n,m,dist[2010],a,b,c,vis[2010];
int G[2010][2010];   //邻接矩阵

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){   //初始化G和dist数组为极大值
        dist[i] = INF;
        for(int j = 1;j <= n;j++)
            G[i][j] = INF;
    }
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&a,&b,&c);
        G[a][b] = G[b][a] = min(c,G[a][b]);   //取最小值
        if(a == 1 || b == 1)
            dist[max(a,b)] = min(c,dist[max(a,b)]);   //记录距离 
    }
    vis[1] = 1;  //标记访问起点
    //单源最短路径
    for(int j = 1;j < n;j++){
        int idx,min = INF;
        for(int i = 1;i <= n;i++)
            if(!vis[i] && min > dist[i]){
                idx = i;
                min = dist[i];  //选择最小距离点
            }
        if(min == INF) break;
        vis[idx] = 1;
        for(int i = 1;i <= n;i++)
            if(!vis[i] && G[idx][i]!=0 && dist[i] > dist[idx]+G[idx][i])
                dist[i] = dist[idx]+G[idx][i];
    }
    if(dist[n] < INF) printf("%d\n",dist[n]);
    else printf("-1");
    return 0;
}