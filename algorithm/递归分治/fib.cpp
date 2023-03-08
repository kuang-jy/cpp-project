#include <iostream>
using namespace std;
int n,f1 = 0,f2 = 1,num;

int fib(int a){
    if(a == 0 || a == 1) return a;
    return fib(a-1)+fib(a-2);
}

int main(){
    scanf("%d",&n);
    for(int i = 2;i <= n;i++){
        num = f1+f2;
        f1 = f2;
        f2 = num;
    }
    if(n == 0) printf("%d\n",f1);
    else printf("%d\n",f2);
    printf("%d\n",fib(n));
    return 0;
}