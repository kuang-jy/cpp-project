#include <iostream>
using namespace std;
long long heap[1000010];
int size = 0;

void swap(int& a,int& b){
    int tmp = a;
    a = b;b = tmp;
}

void adjust_up(int idx){
    int i = idx;
    while(i != 1 && heap[i] < heap[i/2]){
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}

void adjust_down(int idx){
    int minimum = idx,lc = idx*2,rc = idx*2+1;
    if(lc <= size && heap[minimum] > heap[lc]) minimum = lc;
    if(rc <= size && heap[minimum] > heap[rc]) minimum = rc;
    if(minimum != idx){
        swap(heap[minimum],heap[idx]);
        adjust_down(minimum);
    }
}

void deltop(){
    swap(heap[1],heap[size--]);
    adjust_down(1);
}

int gettop(){ return heap[1]; }

void put(int num){
    heap[++size] = num;
    adjust_up(size);
}

int main(int argc, char const *argv[])
{
    int n,op,num;
    cin >> n;
    while(n--){
        cin >> op;
        switch(op){
            case 1: cin >> num;put(num);break;
            case 2: printf("%lld\n",gettop());break;
            case 3: deltop();
        }
    }
    return 0;
}
