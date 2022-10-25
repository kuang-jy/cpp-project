#include <iostream>
using namespace std;
int n,arr[100000];

void dfs(int k,int size,int pre,int target){
    if(k == 0){
        if(size == 1) return;
        printf("%d=%d",target,arr[0]);
        for(int i = 1;i < size;i++) printf("+%d",arr[i]);
        printf("\n");
        return;
    }
    for(int i = 1;i <= k;i++)
        if(k-i >= 0 && pre <= i) {
            arr[size] = i;
            dfs(k-i,size+1,i,target);
        }
}

int main(){
    scanf("%d",&n);
    dfs(n,0,-1,n);
}