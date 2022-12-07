#include <iostream>
using namespace std;

int arr[100],size = 0;

void swap(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}

void adjust_up(int idx){
    while(idx != 1 && arr[idx] < arr[idx/2]){
        swap(arr[idx],arr[idx/2]);
        idx/=2;
    }
}

void adjust_down(int idx){
    int ch = idx*2;
    while(idx <= size){
        if(idx < size && arr[ch] > arr[ch+1]) ch++;
        if(arr[idx] > arr[ch]){
            swap(arr[idx],arr[ch]);
            idx = ch;
            ch = idx*2;
        }
        else break;
    }
}

void put(int num){
    arr[++size] = num;
    adjust_up(size);
}

int main(){
    int a[10] = {NULL,23,17,72,60,25,8,68,71,52};
    for(int i = 1;i <= 9;i++) put(a[i]);
    swap(arr[1],arr[size--]);
    adjust_down(1);
    swap(arr[1],arr[size--]);
    adjust_down(1);
    for(int i = 1;i <= size;i++) cout << arr[i] << " ";
}