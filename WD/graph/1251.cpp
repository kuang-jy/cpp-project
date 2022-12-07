#include <iostream>
using namespace std;
int n,m,sx,sy,ex,ey;
char g[21][21];
const int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};

struct node{
    int x,y,step;
}que[450];

int bfs(){
    int front = -1,rear = -1;
    que[++rear].x = sx;
    que[rear].y = sy;
    que[rear].step = 0;
    g[sx][sy] = '#';
    while(front < rear){
        node vis = que[++front];
        if(vis.x == ex && vis.y == ey) return vis.step;
        for(int i = 0;i < 4;i++){
            int nx = vis.x+dx[i],ny = vis.y+dy[i];
            if(nx >= 1 && ny >= 1 && nx <= m && ny <= n && g[nx][ny] != '#'){
                g[nx][ny] = '#';
                que[++rear].x = nx;
                que[rear].y = ny;
                que[rear].step = vis.step+1;
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d",&m,&n);
    while(m && n){
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++){
                cin >> g[i][j];
                if(g[i][j] == '@'){
                    sx = i;sy = j;
                }
                if(g[i][j] == '*'){
                    ex = i;ey = j;
                }
            }
        printf("%d\n",bfs());
        scanf("%d %d",&m,&n);
    }
    return 0;
}