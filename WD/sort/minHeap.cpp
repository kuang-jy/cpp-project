#include <iostream>
using namespace std;

void swap(int& a,int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void heapify(int arr[],int n,int i){
    int minium = i;
    int lc = i*2+1;
    int rc = i*2+2;
    if(lc < n && arr[minium] > arr[lc]) minium = lc;
    if(rc < n && arr[minium] > arr[rc]) minium = rc;
    if(minium != i){
        swap(arr[minium],arr[i]);
        heapify(arr,n,minium);
    } 
}

void heap_sort(int arr[],int n){
    //建立小顶堆
    int i;
    for(int i = n/2-1;i >= 0;i--){
        heapify(arr,n,i);
    }
    //排序
    for(int i = n-1;i > 0;i--){
        cout << arr[0] << " ";
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {2,3,8,1,4,9,10,7,16,14};
    int n = 10;
    heap_sort(arr,n);
    return 0;
}
