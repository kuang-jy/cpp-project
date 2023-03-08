#include <cstring>
#include <iostream>
using namespace std;

const int size[4] = {10,100,5,50};
int dp[3][3],s[3][3];

int w(int a,int b,int c){
    return size[a]*size[b]*size[c];
}

void martixChain(){
    memset(dp,0x3f,sizeof(dp));
    for(int i = 0;i < 3 ;i++) dp[i][i] = 0;
    for(int i = 1;i < 3;i++){
        for(int j = 0;j < 3-i;j++){
            int e = j+i;
            dp[j][e] = dp[j][j]+dp[j+1][e]+w(j,j+1,e);
            s[j][e] = j;
            for(int k = j+1;k < e;k++){
                int num = dp[j][k]+dp[k+1][e]+w(j,k,e);
                if(dp[j][e] > num){
                    dp[j][e] = num;
                    s[j][e] = k;
                }
            }
        }
    }
}

void traceBack(int i,int j){
    if(i == j){
        printf("A%d",i);
        return;
    }
    printf("(");
    traceBack(i,s[i][j]);
    traceBack(s[i][j]+1,j);
    printf(")");
}


int main(){
    martixChain();
    printf("%d\n",dp[0][2]);
    traceBack(0,2);
    return 0;
}