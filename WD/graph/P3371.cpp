#include <iostream>
#include <string.h>
using namespace std;
int n,m,s,dist[10010],vis[10010],g[10010][10010];

int main(int argc, char const *argv[])
{
    memset(dist,0x3f,sizeof(dist));
    memset(g,0x3f,sizeof(g));
    cin >>n>>m>>s;
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        g[a][b] = c;
        if(a == s) dist[b] = c;
    }
    vis[s] = 1;
    dist[s] = 0;
    for(int i = 2;i <= n;i++){  //控制次数
        //选最小代价点
        int idx=1,m = 1e7;
        for(int j = 1;j <= n;j++)
            if(!vis[j] && dist[j] < m) {
                idx = j;
                m = dist[j];
            }
        vis[idx] = 1;
        //更新dist数组
        for(int j = 1;j <= n;j++){
            if(!vis[j] && dist[j] > dist[idx]+g[idx][j]) dist[j] = dist[idx]+g[idx][j];
        }
    }
    for(int j = 1;j <=n;j++) printf("%d ",dist[j]);
    printf("\n");
    return 0;
}
