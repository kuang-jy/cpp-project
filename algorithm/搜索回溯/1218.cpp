#include <iostream>
using namespace std;

// 假设石子数目为(a,b)且a >= b,如果[a/b] >= 2则先手必胜,如果[a/b]<2,那么先手只有唯一的一种取法。[a/b]表示a除以b取整后的值。
// 所以如果先手要赢，那么就必须把[a/b]<2的情况改变为[a/b]>=2，因此如果在某一时刻为[a/b]<2，下一次拿会变成[a/b]>=2且是后手改变的，先手就必胜
// 也就是说，在[a/b]<2变成[a/b]>=2时，

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    while(a && b){
        if(a < b){
            int temp = a;
            a = b;b = temp;
        }
        int cnt = 0;
        if(a/b >= 2) printf("win\n");
        else{
            while(a/b == 1){
                int num = a/b;
                a = a - b*num;
                cnt++;
                int temp = a;
                a = b;
                b = temp;
            }
            if(cnt%2 == 0) printf("win\n");
            else printf("lose\n");
        }
        scanf("%d %d",&a,&b);
    }
    return 0;
}