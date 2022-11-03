#include <iostream>
using namespace std;
int n,arr[501];

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

int partition(int low,int high){
    int i = low,pivot = arr[low];
    for(int j = low+1;j <= high;j++)
        if(arr[j] < pivot) swap(arr[++i],arr[j]);
    swap(arr[i],arr[low]);
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
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    qsort(0,n-1);
    int i = 0;
    while(i < n)
        if(arr[i] % 2 != 0){
            printf("%d",arr[i++]);
            break;
        }
        else i++;
    for(;i < n;i++) 
        if(arr[i] % 2 != 0)
            printf(",%d",arr[i]);
    return 0;
}