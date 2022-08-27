//
// Created by Kjoye on 2022/8/1.
//

#include <bits/stdc++.h>

using namespace std;

//使用二路归并排序
//将[1,m]和[m+1,n]作为两个已经有序的子表
//时间：O(m+n) 空间：O(m+n)
void mergesort(int arr[],int low,int mid,int high){
    int* temp = (int*)malloc(sizeof(int)*11);  //申请长度为11的辅助数组
    int i,j,k;
    for(k = low;k <= high;k++)  //复制数组
        temp[k] = arr[k];
    for(i = low,j = mid+1,k = low;i <= mid && j <= high;){  //归并
        if(temp[i] <= temp[j]) arr[k++] = temp[i++];
        else arr[k++] = temp[j++];
    }
    while(i <= low) arr[k] = temp[i++];
    while(j <= high) arr[k] = temp[j++];
    delete temp;  //释放辅助数组
}

int main() {
    int arr[] = {NULL,1,3,5,7,9,2,4,6,8,10};
    mergesort(arr,1,5,10);
    for(int i = 1;i <= 10;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
