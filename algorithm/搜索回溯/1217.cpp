#include <iostream>
using namespace std;
int n,k,ans,pos[10];
char board[10][10];

bool check(int row,int col){
    for(int i = row;i >= 1 ;i--)
        if(pos[i] == col || board[row][col] == '.') return false;
    return true;
}

void dfs(int row,int num){
    if(num == 0) ans++;
    for(int i = row;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(check(i,j)){
                pos[i] = j;
                dfs(i+1,num-1);
                pos[i] = 0;
            }
}

int main(){
    scanf("%d %d",&n,&k);
    while(n != -1 && k != -1){
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                cin >> board[i][j];
        ans = 0;
        for(int i = 1;i <= n;i++) pos[i] = 0;
        dfs(1,k);
        printf("%d\n",ans);
        scanf("%d %d",&n,&k);
    }
    return 0;
}