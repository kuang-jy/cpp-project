#include <iostream>
using namespace std;
typedef long long ll;
ll b,p,k;

// 输入b，p，k的值，求b^pmodk的值。其中b，p，k×k为长整型数。
int main(){
    scanf("%lld %lld %lld",&b,&p,&k);
    printf("%lld^%lld mod %lld=",b,p,k);
    ll ans = 1;
    b%=k;
    while(p){
        if(p%2 == 1) ans = (ans*b)%k;
        b = (b*b)%k;
        p/=2;
    }
    printf("%lld\n",ans);
}