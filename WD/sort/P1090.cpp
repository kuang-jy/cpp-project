#include <iostream>
using namespace std;
int n,minHeap[10010],size,x;

void swap(int& a,int &b){
    int t = a;
    a = b;
    b = t;
}

void adjust_up(int idx){
    while(idx != 1 && minHeap[idx] < minHeap[idx/2]){
        swap(minHeap[idx],minHeap[idx/2]);
        idx /= 2;
    }
}

void adjust_down(int idx){
    int ch = idx*2;
    while(ch <= size){
        if(ch < size && minHeap[ch] > minHeap[ch+1]) ch++;
        if(minHeap[ch] < minHeap[idx]){
            swap(minHeap[ch],minHeap[idx]);
            idx = ch;
            ch = idx*2;
        }
        else break;
    }    
}

void put(int num){
    minHeap[++size] = num;
    adjust_up(size);
}

int pop(){
    swap(minHeap[1],minHeap[size--]);
    adjust_down(1);
    return minHeap[size+1];
}

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        put(x);
    }
    x = 0;
    while(size > 1){
        int a = pop(),b = pop();
        x += a+b;
        put(a+b);
    }
    printf("%d\n",x);
    return 0;
}