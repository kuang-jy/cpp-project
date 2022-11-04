#include <iostream>
using namespace std;
long long n,b,h[20010];

void swap(int &a,int &c){
    int t = a;
    a = c;
    c = t;
}

int main(){
    scanf("%lld %lld",&n,&b);
    for(int i = 0;i < n;i++) scanf("%lld",&h[i]);
    //冒泡排序
    for(int i = 0;i < n-1;i++)
        for(int j = n-1;j > i;j--)
            if(h[j-1] < h[j]) 
                swap(h[j-1],h[j]);  //大的往上冒
    long long ans = 0,i = 0;
    while(b > 0){
        b -= h[i++];
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}