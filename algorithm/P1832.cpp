#include <iostream>
#include <cstring>
using namespace std;
#define ll long long 
ll n,dp[1010],p[1010];

void isPrime(int n){
    p[0] = p[1] = 1;  //0,1非素数
    for(int i = 2;i <= n;i++)
        if(!p[i])  //若i是素数，那么他的所有倍数都不会是素数
            for(int j = i;i*j <= n;j++)
                p[i*j] = 1;  //筛掉
}

int main(){
    memset(p,0,sizeof(0));
    scanf("%d",&n);
    isPrime(n);  //筛出所有素数
    dp[0] = 1;
    for(int i = 2;i <= n;i++)  //枚举所有可选的数
        if(!p[i])  //如果当前选的是素数
            for(int j = i;j <= n;j++)   //枚举可以加得的数
                dp[j] = dp[j]+dp[j-i];
    printf("%lld\n",dp[n]);
    return 0;
}


















// #include <iostream>
// using namespace std;
// typedef long long ll;
// int n,isprime[1010];
// ll dp[1010];  //dp[i]表示将i分解成若干个素数之和的方案总数，很显然，对于一个素数j，可以有f[i]=f[i]+f[i-j]
// //完全背包问题，有一些素数，每个素数可以用无限次，求出和为n的方案数

// void prime(int n){   //素数筛法
//     isprime[0] = isprime[1] = 1;
//     for(int i = 2;i <= n;i++)
//         if(isprime[i] == 0)  //如果i是素数，那么所有i的倍数都不是素数
//             for(int j = i*2;j <= n;j+=i)
//                 isprime[j] = 1;   //不是素数，筛掉
// }

// int main(){
//     scanf("%d",&n);
//     prime(n);
//     dp[0] = 1;  //边界情况
//     for(int i = 2;i <= n;i++)  //遍历所有可选数字
//         if(isprime[i] != 1)  //如果是素数
//             for(int j = i;j <= n;j++)  //遍历数组i可能合出的数
//                 dp[j] += dp[j-i];
//     printf("%lld\n",dp[n]);
//     return 0;
// }