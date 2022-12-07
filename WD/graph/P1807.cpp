#include <iostream>
#include <vector>
using namespace std;
int n,m,u,v,w,dp[1510],indeg[1510];
const int MIN = -1e7;

typedef struct edge{
    int from,to,w;
}edge;

vector<edge> G[1510];

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) dp[i] = MIN;
    dp[1] = 0;
    for(int i = 1;i <= m;i++){
        edge e;
        scanf("%d %d %d",&e.from,&e.to,&e.w);
        indeg[e.to]++;  //记录入度
        G[e.from].push_back(e);   //建图
    }
    //拓扑
    int que[1510],front = -1,rear = -1;
    for(int i = 1;i <= n;i++)
        if(!indeg[i])
            que[++rear] = i;
    while(front < rear){
        int out = que[++front];
        for(int i = 0;i < G[out].size();i++){
            dp[G[out][i].to] = max(dp[G[out][i].to],dp[out] + G[out][i].w);   //状态转移
            if(!--indeg[G[out][i].to])
                que[++rear] = G[out][i].to;
        }
    }
    if(dp[n] == MIN) printf("-1\n");
    else printf("%d\n",dp[n]);
    return 0;
}