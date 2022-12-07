#include <iostream>
#include <cstring>
using namespace std;
int n,m,d,tag[102][102],a,b,c,g[102][102],vis[102],dist[102],s,e,graph[102][102];
const int INF = 0x3f3f3f3f;

int main(){
    cin >>n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            graph[i][j] = INF;   //初始化距离为极大值

    for(int i = 1;i <= m;i++){
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;  //仅记录长度
        graph[a][b] = graph[b][a] = 0;   //标记所有路都是好的
    }

    cin >> d;
    for(int i = 1;i <= d;i++){
        cin >> a >> b;
        graph[a][b] = graph[b][a] = g[a][b];   //损坏的道路才更新权值
    }
        
    cin >> s >> e;
    //迪杰斯特拉
    memset(dist,0x3f,sizeof(dist));
    for(int i = 1;i <= n;i++)   //初始化dist数组
        dist[i] = graph[s][i];
    vis[s] = 1;
    for(int i = 1;i < n;i++){
        int min = INF,idx = -1;
        for(int j = 1;j <= n;j++)
            if(!vis[j] && dist[j] < min){
                min = dist[j];  //选择最小距离点
                idx = j;
            }
        if(idx == -1) break;
        vis[idx] = 1; //标记访问
        for(int j = 1;j <= n;j++)  //更新dist数组
            if(!vis[j] && dist[j] > dist[idx]+graph[idx][j])
                dist[j] = dist[idx]+graph[idx][j];
    }
    cout << dist[e] << endl;
    return 0;
}