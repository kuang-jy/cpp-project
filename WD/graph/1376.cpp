#include <iostream>
#include <cstring>
using namespace std;
int n,m,vis[110],dist[110],mp[110][110];

int main(){
    memset(dist,0x3f,sizeof(dist));
    memset(mp,0x3f,sizeof(mp));
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) mp[i][i] = 0;
    for(int i = 0;i < m;i++){
        int f,t,c;
        scanf("%d %d %d",&f,&t,&c);
        if(f == 1) dist[t] = c;
        mp[f][t] = min(c,mp[f][t]);
        mp[t][f] = min(c,mp[t][f]);
    }
    dist[1] = 0;
    vis[1] = 1;
    // 迪杰斯特拉
    for(int i = 0;i < n-1;i++){   //选点次数 n-1
        int minidx,min = 1000000;
        for(int j = 1;j <= n;j++)   //选代价最小点
            if(min > dist[j] && !vis[j]){
                minidx = j;
                min = dist[j];
            }
        vis[minidx] = 1;  //标记访问
        //更新dist数组
        for(int j = 1;j <= n;j++)
            if(!vis[j] && dist[j] > dist[minidx] + mp[minidx][j])
                dist[j] = dist[minidx] + mp[minidx][j];
    }
    int ans = 0;
    for(int i = 2;i <= n;i++){
        if(dist[i] == 0){
            printf("-1\n");
            return 0;
        }
        ans = max(ans,dist[i]);
    }
    printf("%d\n",ans);
    return 0;
}