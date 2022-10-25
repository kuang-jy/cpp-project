#include <iostream>
using namespace std;
int n,m,degree[10010],g[10010][10010],cost,pre = 100,cnt,que[10010],front = -1,rear = -1,last;

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[b][a] = 1;
        degree[a]++;
    }
    for(int i = 1;i <= n;i++)
        if(degree[i] == 0)
            que[++rear] = i;
    last = rear;
    while(front < rear){
        int temp = que[++front];
        cost += pre;
        cnt++;
        for(int i = 1;i <= n;i++)
            if(g[temp][i] == 1 && --degree[i] == 0)
                que[++rear] = i;
        if(front == last){
            pre++;
            last = rear;
        }
    }
    if(cnt < n) printf("Poor Xed");
    else printf("%d\n",cost);
    return 0;
}