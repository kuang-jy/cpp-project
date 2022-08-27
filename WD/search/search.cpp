//
// Created by Kjoye on 2022/7/26.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct{  //查找表结构（顺序表）
    int *elem;  //动态数组
    int len;  //查找表长度
}SSTable;

//顺序查找
//ASL: Σ(1/n)*(每个元素比较次数) = (n+1)/2 --> O(n)
int search_seq(SSTable t,int key){
    int i;
    for (i = 0; i < t.len && t.elem[i] != key; i++);
    return i == t.len ? -1 : i;
}

//折半查找，适用于有序的顺序表
// O(log2n)
int binary_search(SSTable t,int key){
    int low = 0,high = t.len-1,mid;
    while (low < high){
        mid = (low+high)/2;
        if(t.elem[mid] == key) return mid;   //查找成功
        else if(t.elem[mid] < key) low = mid+1;
        else high = mid-1;
    }
    return -1;  //查找失败
}


int main() {

    return 0;
}
