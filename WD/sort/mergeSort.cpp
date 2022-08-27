//
// Created by Kjoye on 2022/7/31.
//

#include <bits/stdc++.h>

using namespace std;

//二路归并排序
int* arr = (int*) malloc(sizeof(int)*(10));  //与待排序数组同大小的辅助数组
void merge(int x[],int low,int mid, int high){  //第一个有序组开始，第一个有序组结束，第二个有序组结束
    int i,j,k;
    for(k = low;k <= high;k++)  //将待排序数组复制到辅助数组中
        arr[k] = x[k];
    for(i = low,j = mid+1,k = low;i <= mid && j <= high;k++){  //归并
        if(arr[i] <= arr[j]) x[k] = arr[i++];  //保证稳定性，取等号
        else x[k] = arr[j++];
    }
    while (i <= mid) x[k] = arr[i++];  //将剩余数组直接顺序放入
    while (j <= high) x[k] = arr[j++];
}

//时间：O(nlog2n) 空间：O(n)
void mergeSort(int x[],int low,int high){
    if(low >= high) return;
    int mid = (high+low)/2;  //划分
    mergeSort(x,low,mid);
    mergeSort(x,mid+1,high);
    merge(x,low,mid,high);
}

void disp(int x[],int len){
    for(int i = 0;i < len;i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int x[] = {-1,3,2,1,5,6,2};
    mergeSort(x,0,6);
    disp(x,7);
    return 0;
}
