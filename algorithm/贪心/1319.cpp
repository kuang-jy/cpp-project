#include <iostream>
using namespace std;

struct p{
    int id,time;
    double avg;
}que[1010];

void swap(p& p1,p& p2){
    p tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int partition(int low,int high){
    p pivot = que[low];
    int i = low;
    for(int j = low+1;j <= high;j++)
        if(que[j].time < pivot.time) swap(que[j],que[++i]);
    swap(que[i],que[low]);
    return i;
}

void qsort(int low,int high){
    if(low >= high) return;
    int pivot = partition(low,high);
    qsort(low,pivot-1);
    qsort(pivot+1,high);
}

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> que[i].time;
        que[i].id = i;
    }
    qsort(1,n);
    int sum = 0,wtime = 0;
    for(int i = 1;i <= n;i++) {
        printf("%d ",que[i].id);
        sum += wtime;
        wtime += que[i].time;
    }
    printf("\n%.2f\n",sum/(n*1.0));
    return 0;
}