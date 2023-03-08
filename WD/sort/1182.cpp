#include <iostream>
#include <cstring>
using namespace std;
int n,i,j;
string s;
double h,m[40],f[40];

void swap(double &a,double &b){
    double t = a;
    a = b;
    b = t;
}

int partition(int low,int high,double arr[]){
    double pivot = arr[low];
    int i = low;
    for(int j = low+1;j <= high;j++)
        if(arr[j] < pivot)
        swap(arr[j],arr[++i]);
    swap(arr[i],arr[low]);
    return i;
}

void qsort(int low,int high,double arr[]){
    if(low >= high) return;
    int pivot = partition(low,high,arr);
    qsort(low,pivot-1,arr);
    qsort(pivot+1,high,arr);
}

int main(){
    scanf("%d",&n);
    while(n--){
        cin >> s >> h;
        if(s[0] == 'm') m[i++] = h;
        else f[j++] = h;
    }
    qsort(0,i-1,m);
    qsort(0,j-1,f);
    for(int k = 0;k < i;k++) printf("%.2f ",m[k]);
    for(int k = j-1;k >= 0;k--) printf("%.2f ",f[k]);
    return 0;
}