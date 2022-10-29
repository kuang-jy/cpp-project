#include <iostream>
using namespace std;
int a,b,c,d,e,f,arr[6],sum,cnt;

int main(){
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    while(a||b||c||d||e||f){
        sum = a+b*4+c*9+d*16+e*25+f*36;
        cnt = 0;
        while(sum >= 36){
            cnt++;
            sum/=36;
        }
        if(sum > 1) cnt++;
        printf("%d\n",cnt); 
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    }
    return 0;
}