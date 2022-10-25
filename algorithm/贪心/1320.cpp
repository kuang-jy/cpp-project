#include <iostream>
using namespace std;
int n,cards[110],cnt,avg;

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&cards[i]);
        cnt += cards[i];
    }
    avg = cnt/n;
    cnt = 0;
    for(int i = 1;i <= n;i++) cards[i]-=avg;
    int low = 1,high = n;
    while(cards[low] == 0) low++;
    while(cards[high] == 0) high--;
    for(int i = low;i < high;i++)
        if(cards[i] == 0) continue;
        else {
            cards[i+1] += cards[i];
            cards[i] = 0;
            cnt++;
        }
    printf("%d",cnt);
    return 0;
}