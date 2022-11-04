#include <iostream>
using namespace std;
int n,arr[202];

int find(int a){
    if(arr[a] != a)
        arr[a] = find(arr[a]);   //压缩路径
    return arr[a];
}

void merge(int a,int b){
    arr[find(a)] = arr[find(b)];
}

int main(){
    scanf("%d",&n);
    int cnt = n;
    for(int i = 1;i <= n;i++) arr[i] = i;
    for(int i = 1;i <= n;i++){
        int x;
        scanf("%d",&x);
        while(x){
            if(find(i) != find(x)){
                merge(i,x);
                cnt--;   //维护连通块
            }
            scanf("%d",&x);
        }
    }
    printf("%d\n",cnt);
    return 0;
}