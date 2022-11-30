#include <iostream>
using namespace std;
int n,arr[11][11],r,c,num;

int solve(){
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];
        }
}

int main(){
    scanf("%d",&n);
    scanf("%d %d %d",&r,&c,&num);
    while(r && c && num){
        arr[r][c] = num;
        scanf("%d %d %d",&r,&c,&num);
    }

    return 0;
}