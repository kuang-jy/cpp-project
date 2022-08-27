//
// Created by Kjoye on 2022/7/29.
//

#include <bits/stdc++.h>

using namespace std;

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

 int randPartition(int arr[],int low,int high){
    //rand() 返回一个从0到最大随机数的任意整数
    int randIndex = low + rand() % (high-low+1);  //low加上一个随机数，左闭右开
    swap(arr[randIndex],arr[low]);  //将随机取的元素放到第一个
    int pivot = arr[low];
    int i = low;  //i是小于基准值组的尾下标
    for (int j = low+1; j <= high; ++j) {  //j用于遍历数组
        if(arr[j] < pivot) swap(arr[++i],arr[j]);  //如果j小于基准值，那就把j的数据和++i的数据交换
    }
    swap(arr[i],arr[low]); //最后把pivot换到两组中间
    return i;
}

void quickSort(int arr[],int low,int high){
    if(low >= high) return;
    int pivot = randPartition(arr,low,high);
    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot+1,high);
}

void show(int arr[],int len){
    for(int i = 0;i < len;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[]{-1,3,2,5,6,2};
    quickSort(arr,0,5);
    show(arr,6);
    return 0;
}
