#include <iostream>
#include <cstring>
using namespace std;
int a,n,v0,g[82][82];


//弗洛伊德 最短路
void floyd(){
    for(int k = 1;k <= n;k++)  // 中转点
        for(int i = 1;i <= n;i++) // 起点
            for(int j = 1;j <= n;j++)  // 终点
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]); 
}

int main(){
    scanf("%d",&n);
    scanf("%d",&v0);
    memset(g,0x3f,sizeof(g));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(scanf("%d",&a))
                g[i][j] = a;
        
    floyd();
    for(int i = 1;i <= n;i++)
        if(i != v0) printf("(%d -> %d) = %d\n",v0,i,g[v0][i]);
    return 0;
} 