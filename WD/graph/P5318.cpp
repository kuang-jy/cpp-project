#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m,vis[100010];
vector<int> g[100010];

void dfs(int v){
    printf("%d ",v);
    vis[v] = 1;
    if(v == n) return;
    for(int i = 0;i < g[v].size();i++)
        if(!vis[g[v][i]]) dfs(g[v][i]);
}

void bfs(){
    int que[100010],rear = -1,front = -1;
    que[++rear] = 1;vis[1] = 1;
    while(front < rear){
        int x = que[++front];
        printf("%d ",x);
        for(int i = 0;i < g[x].size();i++)
            if(!vis[g[x][i]]){
                que[++rear] = g[x][i];
                vis[g[x][i]] = 1;
            } 
    }
}

int main(int argc, const char** argv) {
    cin >> n >> m;
    int x,y;
    for(int i = 0;i < m;i++){  //记录邻接点
        cin >> x >> y;
        g[x].push_back(y);
    }
    //排序
    for(int i = 1;i <= n;i++) sort(g[i].begin(),g[i].end());
    memset(vis,0,sizeof(vis));
    dfs(1);
    printf("\n");
    memset(vis,0,sizeof(vis));
    bfs();
    printf("\n");
    return 0;
}