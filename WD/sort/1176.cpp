#include <iostream>
using namespace std;
int n,k,size = 0;

struct node{
    int id;
    double score;
}heap[110];   //大根堆

void swap(node &n1,node &n2){
    node t = n1;
    n1 = n2;
    n2 = t;
}

void adjust_up(int idx){
    while(idx != 1 && heap[idx].score < heap[idx/2].score){
        swap(heap[idx],heap[idx/2]);
        idx/=2;
    }
}

void adjust_down(int idx){
    int ch = idx*2;
    while(ch <= size){
        if(ch < size && heap[ch].score > heap[ch+1].score) ch++;
        if(heap[ch].score < heap[idx].score){
            swap(heap[ch],heap[idx]);
            idx = ch;
            ch = idx*2;
        }
        else break;
    }
}

void put(double num,int id){
    heap[++size].score = num;
    heap[size].id = id;
    adjust_up(size);
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0;i < n;i++){
        int a;double b;
        scanf("%d %lf",&a,&b);
        if(size < k)
            put(b,a);
        else if(heap[1].score < b){
            heap[1].score = b;
            heap[1].id = a;
            adjust_down(1);
        }
    }
    printf("%d %g\n",heap[1].id,heap[1].score);
    return 0;
}