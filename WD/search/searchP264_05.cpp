//
// Created by Kjoye on 2022/7/26.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int *data;
    int len;
}SSTable;

//递归的折半查找
int binary_search(SSTable t,int key,int low,int high){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(t.data[mid] == key) return mid;
    else if(t.data[mid] < key) return binary_search(t,key,mid+1,high);
    return binary_search(t,key,low,mid-1);
}

int main() {
    SSTable t;
    t.data = new int[5];
    for (int i = 0; i <5 ; ++i)
        t.data[i] = (i+1)*2;
    cout << binary_search(t,100,0,4) << endl;
    return 0;
}
