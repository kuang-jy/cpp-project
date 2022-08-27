#include<iostream>

//顺序表定义
#define MaxSize 10 
typedef struct{
    int data[MaxSize];
    int length = 0;
} sqList;

//P18 01
bool delMin(sqList& L,int& num){
    if(L.length == 0) return false;
    num = L.data[0];
    int idx = 0;
    for(int i = 0;i < L.length;i++){
        if(L.data[i] < num) {
            num = L.data[i];
            idx = i;
        }
    }
    L.data[idx] = L.data[L.length-1];
    L.length--;
    return true;
}

//P18 02
void reverse(sqList& L){
    int temp;
    for(int i = 0;i < L.length/2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-1-i] = temp;
    }
}

//P18 03
void delX(sqList& L,int num){
    int count = 0;
    for(int i = 0;i < L.length;i++){
        if(L.data[i] != num){
            L.data[count++] = L.data[i];
        }
    }
    L.length = count;
}

//P18 04
bool delStoT(sqList& L,int s,int t){
    if(L.length == 0 || s>=t) return false;
    int l = 0;
    for(;l < L.length && L.data[l] < s;l++); //找到第一个等于s的位置
    if(l >= L.length) return false;  //所有元素均小于s
    int r = 0;
    for(;r < L.length && L.data[r] <= t;r++); //找到最后一个等于t的位置
    for(;r < L.length;l++,r++){  //元素前移
        L.data[l] = L.data[r];
    }
    L.length = l;
    return true;
}

//P18 05
bool delStoT2(sqList& L,int s,int t){
    if(L.length == 0 || s >= t) return false;
    int pre = 0;
    for(int i = 0;i < L.length;i++){
        if(L.data[i] < s || L.data[i] > t){
            L.data[pre] = L.data[i];
            pre++;
        }
    }
    L.length = pre;
    return true;
}

//P18 06
bool dropDuplicate(sqList& L){
    if(L.length == 0) return false;
    if(L.length == 1) return true;
    int pre = 0;
    int cur = 1;
    for(;cur < L.length;cur++){
        if(L.data[pre] != L.data[cur])
            L.data[++pre] = L.data[cur];
    }
    L.length = pre+1;
    return true;
}

//P18 07
void merge2(sqList L1,sqList L2,sqList& result){
    if(L1.length+L2.length > result.length)
    if(L1.length == 0) return ;
    if(L2.length == 0) return ;
    int i=0,j=0,k=0;
    while(i < L1.length && j < L2.length){
        if(L1.data[i] <= L2.data[j]) result.data[k++] = L1.data[i++];
        else result.data[k++] = L2.data[j++];
    }
    while(i < L1.length) result.data[k++] = L1.data[i++];
    while(j < L2.length) result.data[k++] = L2.data[j++];
    result.length = k;
}

//P18 08 
void reverse(int arr[],int l,int r){
    if(l >= r) return;
    int mid = (l+r)/2;
    for(int i = l;i <= mid;i++){
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r--] = temp;
    }
}
void exchange(int arr[],int m,int n){
    reverse(arr,0,m+n-1);
    reverse(arr,0,n-1);
    reverse(arr,n,m+n-1);
}

//P18 09
void find(sqList& L,int num){
    int low = 0,high = L.length-1,mid;
    //（有序）二分查找
    while(low <= high){
        mid = (low+high)/2;
        if(num > L.data[mid]) low = mid+1;
        else if(num < L.data[mid]) high = mid-1;
        else{
            //找到了，并且不在最后一个
            if(mid != L.length-1){
                int temp = L.data[mid];
                L.data[mid] = L.data[mid+1];
                L.data[mid+1] = temp;
            }
            break;
        }
    }
    //没找到就插入
    if(low > high){
        for(int i = L.length-1;i > high;i--) L.data[i+1] = L.data[i];
        L.data[high+1] = num;
        L.length++;
    }
}

//P18 12
//由于主元素的定义是，超过半数的相同元素，所以用主元个数减去剩余元素的值一定为正数
int findMain(int* arr,int len){
    int count=1,m = *arr;
    //寻找可能的主元
    for(int i = 0;i < len;i++){
        if(m == *(arr+i)) count++;
        else{
            if(count > 0) count--;
            else{
                count = 1;
                m = *(arr+i);
            }
        }
    }
    //确定是否为主元 
    if(count > 0) {
        count = 0;
        for(int i = 0;i < len;i++)
            if(m == *(arr+i)) count++;
    }
    return count > len/2 ? m : -1;
}

void show(sqList L){
    for (size_t i = 0; i < L.length; i++)
        std::cout << L.data[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    sqList L;
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 5;
    L.data[3] = 7;
    L.length = 4;
    // sqList L2;
    // L2.data[0] = 2;
    // L2.data[1] = 4;
    // L2.data[2] = 6;
    // L2.data[3] = 8;
    // L2.length = 4;
    // dropDuplicate(L);
    // sqList L3;
    // merge2(L,L2,L3);
    // show(L3);
    // int arr[] = {1,2,3,4,5,66,77,88,99};
    // exchange(arr,5,4);
    // for(auto var : arr)
    // {
    //     std::cout << var << " " ;
    // }
    find(L,3);
    show(L);
    find(L,0);
    show(L);
    return 0;
}
