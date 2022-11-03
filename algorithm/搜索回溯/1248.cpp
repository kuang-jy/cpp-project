#include <iostream>
#include <cstring>
using namespace std;
int n,m,k,sx,sy,sz,ex,ey,ez;
char arr[100][100][100];
const int dx[6] = {1,-1,0,0,0,0},dy[6] = {0,0,1,-1,0,0},dz[6] = {0,0,0,0,1,-1};

struct node{
    int x,y,z,step;
}que[1000000];

int bfs(){
    int front = -1,rear = -1;
    que[++rear].x = sx;
    que[rear].y = sy;
    que[rear].z = sz;
    que[rear].step = 0;
    arr[sz][sx][sy] = '#';
    while(front < rear){
        node out = que[++front];
        if(out.x == ex && out.y == ey && out.z == ez) return out.step;
        for(int i = 0;i < 6;i++){
            int nx = out.x+dx[i],ny = out.y+dy[i],nz = out.z+dz[i];
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < k && nz < n && arr[nz][nx][ny] != '#'){
                que[++rear].x = nx;
                que[rear].y = ny;
                que[rear].z = nz;
                que[rear].step = out.step+1;
                arr[nz][nx][ny] = '#';
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    while(n&&m&&k){
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                for(int l = 0;l < k;l++){
                    cin >> arr[i][j][l];
                    if(arr[i][j][l] == 'S'){
                        sx = j;
                        sy = l;
                        sz = i;
                    }
                    if(arr[i][j][l] == 'E'){
                        ex = j;
                        ey = l;
                        ez = i;
                    }
                }
        int ans = bfs();
        if(ans != -1) printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
        scanf("%d %d %d",&n,&m,&k);
    }
    return 0;
}