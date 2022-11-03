#include <iostream>
using namespace std;
int n,m,ans;
char arr[111][111];
const int dx[8] = {1,1,1,-1,-1,-1,0,0},dy[8] = {1,0,-1,1,0,-1,1,-1};

struct node{
    int x,y;
}que[10100];

void bfs(int a,int b){
    int front = -1,rear = -1;
    que[++rear].x = a;
    que[rear].y = b;
    arr[a][b] = '.';
    while(front < rear){
        node out = que[++front];
        for(int i = 0;i < 8;i++){
            int nx = out.x+dx[i],ny = out.y+dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] != '.'){
                que[++rear].x = nx;
                que[rear].y = ny;
                arr[nx][ny] = '.';
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] == 'W'){
                ans++;
                bfs(i,j);
            }
    printf("%d\n",ans);
    return 0;
}