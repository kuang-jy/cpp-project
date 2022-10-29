#include <iostream>
#include <cstring>
using namespace std;
int n,m,arr[110],down[110],ans,up[110];

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        memset(arr,0,sizeof(arr));
        memset(down,0,sizeof(down));
        ans = 0;
        for(int i = 1 ;i <= m;i++) scanf("%d",&arr[i]);
        for(int i = 1;i <= m;i++){
            down[i] = 1;
            up[i] = 1;
            for(int j = i-1;j >= 1;j--)
                if(arr[i] < arr[j]) down[i] = max(down[i],down[j]+1);
                else if(arr[i] > arr[j]) up[i] = max(up[i],up[j]+1);
            ans = ans > down[i] ? ans : down[i];
            ans = ans > up[i] ? ans : up[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}