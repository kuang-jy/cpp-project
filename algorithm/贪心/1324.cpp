#include <iostream>
using namespace std;
int n,s[10010],e[10010],pre,cnt;

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

int partition(int low,int high){
    int pivot = s[low];
    int i = low;
    for(int j = low+1;j <= high;j++)
        if(s[j] < pivot){
            swap(s[++i],s[j]);
            swap(e[i],e[j]);
        }
    swap(s[i],s[low]);
    swap(e[i],e[low]);
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
    for(int i = 0;i < n;i++) scanf("%d %d",&s[i],&e[i]);
    qsort(0,n-1);
    pre = e[0];  //第一个选的点
    cnt++;
    for(int i = 1;i < n;i++){
        if(pre >= s[i]) continue;
        pre = e[i];
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

