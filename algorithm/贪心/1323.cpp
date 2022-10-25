#include <iostream>
using namespace std;
int n,arr[1010][2],pre,cnt;

void swap(int a[1010][2],int i,int j){
    int t1 = a[i][0],t2 = a[i][1];
    a[i][0] = a[j][0];a[i][1] = a[j][1];
    a[j][0] = t1;a[j][1] = t2;
}

int partition(int low,int high){
    int pivot = arr[low][1];
    int i = low;
    for(int j = low+1;j <= high;j++)
        if(arr[j][1] < pivot) swap(arr,++i,j);
    swap(arr,i,low);
    return i;
}

void qsort(int low,int high){
    if(low >= high) return;
    int pivot = partition(low,high);
    qsort(low,pivot-1);
    qsort(pivot+1,high);
}

int main(){
    scanf("%d",&n);
    if(!n) {
        printf("0\n");
        return 0;
    }
    for(int i = 0;i < n;i++)
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    qsort(0,n-1);
    pre = 0;
    cnt = 1;
    for(int i = 1;i < n;i++)
        if(arr[i][0] >= arr[pre][1]){
            pre = i;
            cnt++;
        }
    printf("%d\n",cnt);
    return 0;
}