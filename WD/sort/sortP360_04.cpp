//
// Created by Kjoye on 2022/8/1.
//

#include <bits/stdc++.h>

using namespace std;

//以Kn作为枢轴进行一次快排划分
//选取最后一个元素作为数轴
//那么先从low开始，再从high开始
void partition(int arr[],int n){
    int pivot = arr[n];
    int low = 0,high = n;
    while(low < high){
        while (low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
        while(low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
    }
    arr[low] = pivot;
}

int main() {
    int arr[] = {0,7,8,1,7,3,5};
    partition(arr,6);
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
