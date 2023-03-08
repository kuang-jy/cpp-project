#include <iostream>
using namespace std;
#define ll long long
ll a,b,c,arr[25][25][25] = {0};

ll calc(ll x,ll y,ll z){
    if(x <= 0 || y <= 0 || z <= 0) return 1;
    else if(x > 20 || y > 20 || z > 20) return calc(20,20,20);
    else if(!arr[x][y][z]){
        if(x < y && y < z)
            //w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)
            arr[x][y][z] = calc(x,y,z-1)+calc(x,y-1,z-1)-calc(x,y-1,z);
        else
            //w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)
            arr[x][y][z] = calc(x-1,y,z)+calc(x-1,y-1,z)+calc(x-1,y,z-1)-calc(x-1,y-1,z-1);
    }
    return arr[x][y][z];
}

int main(){
    while(1){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,calc(a,b,c));
    }
    return 0;
}