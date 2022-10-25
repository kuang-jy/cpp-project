#include <iostream>
using namespace std;
int n,arr[110],up[110],down[110];

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    for(int i = 1;i <= n;i++){
        up[i] = 1;
        for(int j = 1;j < i;j++)
            if(arr[j-1] < arr[i-1])
                up[i] = max(up[i],up[j]+1);
    }
   for(int i = n;i >= 1;i--){
        down[i] = 1;
        for(int j = n;j > i;j--)
            if(arr[j-1] < arr[i-1])
                down[i] = max(down[i],down[j]+1);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
        ans = max(ans,up[i]+down[i]-1);
    printf("%d\n",n-ans);
    return 0;
}