#include <iostream>
using namespace std;
int n,arr[100010],up[100010],down[100010];
//第一个数字表示这套系统最多能拦截多少导弹，第二个数字表示如果要拦截所有导弹最少要配备多少套这种导弹拦截系统
//最小下降子序列个数，等于最大上升子序列长度
int main(){
    while(cin >> arr[n]) n++;
    for(int i = 0;i < n;i++){
        up[i] = 1;
        for(int j = i-1;j >= 0;j--)
            if(arr[j] >= arr[i])
                up[i] = max(up[i],up[j]+1);   //最长上升子序列
    }
    return 0;
}