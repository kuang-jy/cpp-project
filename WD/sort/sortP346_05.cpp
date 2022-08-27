//
// Created by Kjoye on 2022/8/1.
//

#include <bits/stdc++.h>

using namespace std;

//将数组作为完全二叉树，扫描所有分支结点，如果有父结点大于子结点返回false，扫描完成返回true
bool judgeMinHeap(int arr[],int len){
    //len为偶数时，有一个单分支结点
    if(len % 2 == 0){  //先把最后一个单分支结点判断
        if(arr[len/2] > arr[len]) return false;
        for(int i = len/2-1;i >= 1;i--)  //从倒数第二个双分支结点到第一个双分支结点
            if(arr[i] > arr[i*2] || arr[i] > arr[i*2+1]) return false;
    }
    //len为奇数是，全是双分支结点
    else{
        for(int i = len/2;i >= 1;i--)  //从倒数第二个双分支结点到第一个双分支结点
            if(arr[i] > arr[i*2] || arr[i] > arr[i*2+1]) return false;  //从最后一个双分支到第一个
    }
    return true;
}

int main() {
    int arr[] = {NULL,1,3,4,5,9,7,6};
    cout << judgeMinHeap(arr,7) << endl;
    return 0;
}
