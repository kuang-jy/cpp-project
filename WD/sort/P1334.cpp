#include <iostream>
using namespace std;
long long heap[20010];
int size = 0;

void swap(int& a,int& b){
    int tmp = a;
    a = b;b = a;
}

void adjust_down(int idx){
    //选择左右中最小者 
    int minimum = idx*2;
    while(minimum <= size){
        if(minimum < size && heap[minimum] > heap[minimum+1]) minimum++;  //如存在右孩子，进行比较
        if(heap[minimum] < heap[idx]){    //不满足小根堆
            swap(heap[minimum],heap[idx]);
            idx = minimum;   //根变为较小的孩子
            minimum = idx*2;  //minimum变为左孩子
        }
        else break;
    }
}

void adjust_up(int idx){
    int i = idx;
    while(i != 1 && heap[i] < heap[i/2]){
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}

void put(int num){
    heap[++size] = num;
    adjust_up(size);
}

int deltop(){
    swap(heap[1],heap[size--]);
    adjust_down(1);
    return heap[size+1];
}

int main(int argc, char const *argv[])
{
    int n,m;
    long long ans = 0;
    cin >> n;
    while(n--){
        cin >> m;
        put(m);
    }
    while(size != 1){
        int n1 = deltop(),n2 = deltop();
        ans += n1+n2;
        put(n1+n2);
    }
    cout << ans;
    return 0;
}
