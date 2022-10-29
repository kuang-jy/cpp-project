#include <iostream>
using namespace std;
int n,arr[100010],temp[100010];
long long cnt;

void merge2(int low,int mid,int high){
    int i = low,j = mid+1,k = low;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {    //构成逆序
            cnt += mid-i+1;
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= high) temp[k++] = arr[j++];
    for(int i = low;i <= high;i++) arr[i] = temp[i];
}

void msort(int low,int high){
    if(low >= high) return;
    int mid = (low+high)/2;
    msort(low,mid);
    msort(mid+1,high);
    merge2(low,mid,high);
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    msort(0,n-1);
    printf("%lld\n",cnt);
    return 0;
}