#include <iostream>
using namespace std;
int n,arr[201],mp[201][201],dp[201],maxn,pos,path[201];

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1;i <= n ;i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    while(1){
        int a,b;
        cin >> a >> b;
        if(a==0&&b==0) break;
        mp[a][b] = 1;
    }
    for(int i = 1;i <= n;i++) path[i] = i;
    for(int i = 2;i <= n;i++){
        int num = 0;
        for(int j = 1;j < i;j++){
            if(mp[j][i] == 1 && num < dp[j]){
                num = dp[j];
                path[i] = j;
            }
        }
        dp[i] += num;
        if(maxn < dp[i]){
            maxn = dp[i];
            pos = i;
        }
    }
    int k = 0;
    while(path[pos] != pos){
        arr[k++] = pos;
        pos = path[pos];
    }
    printf("%d",pos);
    for(int i = k-1;i >=0;i--) printf("-%d",arr[i]);
    printf("\n%d\n",maxn);
    return 0;
}
