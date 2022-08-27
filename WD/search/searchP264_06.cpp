//
// Created by Kjoye on 2022/7/26.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int *data;
    int len;
}SSTable;

int seqSearch(SSTable t,int key){
    int i = 0;
    for(;i < t.len && t.data[i] != key;i++);
    if(i < t.len && i-1 >= 0){  //如果找到了，并且存在前一个元素  xiao'lü
        int temp = t.data[i];
        t.data[i] = t.data[i-1];
        t.data[i-1] = temp;
        return --i;
    } else return -1;
}

int main() {

    return 0;
}
