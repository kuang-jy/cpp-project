#include <iostream>
#include <cstring>
using namespace std;
int n,arr[110][110],degrees[110];

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        while(x){
            arr[i][x] = 1;
            degrees[x]++;
            scanf("%d",&x);
        }
    }
    //拓扑排序
    int que[110],front = -1,rear = -1;
    for(int i = 1;i <= n;i++)
        if(degrees[i] == 0)
            que[++rear] = i;
    while(front < rear){
        int out = que[++front];
        printf("%d ",out);
        for(int i = 1;i <= n;i++)
            if(arr[out][i] == 1 && --degrees[i] == 0)
                que[++rear] = i;
    }
    return 0;
}