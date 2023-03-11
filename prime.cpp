#include<iostream>
#include<vector>
using namespace std;

const int N = 1e6;
int n;
vector<int> is_prime(N,1);  //标记全部是素数

vector<int> check(int n,vector<int>& is_prime){
    vector<int> primes; //存储素数
    is_prime[0] = is_prime[1] = 0;  //0，1不是素数
    for(int i = 2;i <= n;i++){  //遍历2-n所有数
        if(is_prime[i]) primes.push_back(i);  //如果i是素数，加入primes数组
        for(int j = i*2;j <= n;j+=i)  //用当前素数i去筛掉所有能被它整除的数
            is_prime[j] = 0;
    }
    return primes;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> primes = check(n,is_prime);
    for(int x : primes)
        printf("%d ", x);
    return 0;
}