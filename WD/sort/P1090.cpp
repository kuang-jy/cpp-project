#include <iostream>
using namespace std;
int heap[10010],size = 0;

void disp(){
    for(int i = 1;i <= size;i++) printf("%d,",heap[i]);
    printf("\n");
}

void swap(int& a,int& b){
    int tmp = a;
    a = b;b = tmp;
}

//向上调整，插入
void adjust_up(int num){
    int i = ++size;
    heap[i] = num;
    while(i != 1 && heap[i] < heap[i/2]){
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}

//向下调整
void adjust_down(int k){
    int mininum = k;
    int lc = k*2,rc = k*2+1;
    if(lc <= size && heap[lc] < heap[mininum]) mininum = lc;
    if(rc <= size && heap[rc] < heap[mininum]) mininum = rc;
    if(mininum != k){
        swap(heap[k],heap[mininum]);
        adjust_down(mininum);
    }
}

//取出，删除堆顶元素
int gettop(){
    swap(heap[1],heap[size]);
    size--;
    adjust_down(1);
    return heap[size+1];
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n;
    while(n--){
        cin >> m;
        adjust_up(m);
    }
    int ans = 0;
    while(size > 1){
        int n1 = gettop(),n2 = gettop();
        ans += n1+n2;
        adjust_up(n1+n2);
    }
    cout << ans;
    return 0;
}
