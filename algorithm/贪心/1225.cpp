#include <iostream>
using namespace std;
int k,w,s,a[110],b[110];  //a重量 b价值
double ab[110];  //单位价值

int main(){
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&w,&s);
        for(int i = 0;i < s;i++) {
            scanf("%d %d",&a[i],&b[i]);
            ab[i] = b[i]*1.0/(a[i]*1.0);
        }
        //插入排序 降序
        for(int i = 1;i < s;i++)
            if(ab[i-1] < ab[i]){
                double temp = ab[i];  //暂存该元素
                int t1 = a[i],t2 = b[i];
                int j;
                for(j = i-1;j >= 0 && temp > ab[j];j--){  //找到插入位置
                    ab[j+1] = ab[j];  //移出空位
                    a[j+1] = a[j];
                    b[j+1] = b[j];
                }
                ab[j+1] = temp;
                a[j+1] = t1;
                b[j+1] = t2;
            }
        double ans = 0;
        for(int i = 0;i < s;i++)
            if(a[i] <= w){
                w -= a[i];
                ans += b[i];
            }
            else{
                ans += ab[i]*w;
                break;
            }
        printf("%.2lf\n",ans);
    }
    return 0;
}