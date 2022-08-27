//
// Created by Kjoye on 2022/8/1.
//

#include <bits/stdc++.h>

using namespace std;

int* countSort(int arr[],int len){
    int count;
    int* x = (int*)malloc(sizeof(int)*len);
    for(int i = 0;i < len;i++){
        count = 0;
        for(int j = 0;j < len;j++)
            if(arr[j] < arr[i])
                count++;
        x[count] = arr[i];
    }
    return x;
}

int main() {
    int arr[] = {1,5,3,2,4,8,6,7};
    int* x = countSort(arr,8);
    for(int i = 0;i < 8;i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}
