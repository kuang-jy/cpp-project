#include <iostream>
using namespace std;
int n,m,grid[1510][1510],dp[1510][1510][2],ans = 0;
//dp数组定义：行，列，黑白，dp[i][j][0] = min(dp[i-1][j-1][0],dp[i][j-1][1],dp[i-1][j][1]) + 1
//                        dp[i][j][1] = min(dp[i-1][j-1][1],dp[i][j-1][0],dp[i-1][j][0]) + 1 

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            scanf("%d",&grid[i][j]);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(grid[i][j] == 0)
                dp[i][j][0] = min(min(dp[i-1][j][1],dp[i][j-1][1]),dp[i-1][j-1][0]) + 1;
            else 
                dp[i][j][1] = min(min(dp[i-1][j][0],dp[i][j-1][0]),dp[i-1][j-1][1]) + 1;
            ans = max(max(dp[i][j][0],dp[i][j][1]),ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}

























// #include <iostream>
// using namespace std;
// int n,m,grid[1510][1510],flag = 0,ans,dp[1510][1510][2];

// int main(){
//     scanf("%d %d",&n,&m);
//     for(int i = 1;i <= n;i++)
//         for(int j =1;j <= m;j++)
//             scanf("%d",&grid[i][j]);
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(grid[i][j] == 1){
//                 dp[i][j][1] = min(min(dp[i-1][j][0],dp[i][j-1][0]),dp[i-1][j-1][1])+1;
//                 ans = max(ans,dp[i][j][1]);
//             }
//             else{
//                 dp[i][j][0] = min(min(dp[i-1][j][1],dp[i][j-1][1]),dp[i-1][j-1][0])+1;
//                 ans = max(ans,dp[i][j][0]);
//             }
//         }
//     }
//     printf("%d\n",ans);
//     return 0;
// }