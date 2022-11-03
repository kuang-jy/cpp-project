#include <iostream>
#include <cstring>
using namespace std;
int x,xx,y,yy,vis[105][105];
const int dx[12] = {-2,-2,-1,-1,1,1,2,2,-2,-2,2,2},dy[12] = {1,-1,2,-2,2,-2,1,-1,-2,2,-2,2};

struct node{
    int x,y,step;
}que[10100];

int bfs(int a,int b){
    int front = -1,rear = -1;
    memset(vis,0,sizeof(vis));
    que[++rear].x = a;
    que[rear].y = b;
    que[rear].step = 0;
    vis[a][b] = 1;
    while(front < rear){
        node out = que[++front];
        if(out.x == 1 && out.y == 1) return out.step;
        for(int i = 0;i < 12;i++){
            int nx = out.x+dx[i], ny = out.y+dy[i];
            if(nx >= 1 && ny >= 1 && nx <= 100 && ny <= 100 && !vis[nx][ny]) {
                que[++rear].x = nx;
                que[rear].y = ny;
                que[rear].step = out.step+1;
                vis[nx][ny] = 1;
            }
        }
    }
}

int main(){
    scanf("%d %d %d %d",&x,&y,&xx,&yy);
    int s1 = bfs(x,y);
    int s2 = bfs(xx,yy);
    printf("%d\n%d\n",s1,s2);
    return 0;
}