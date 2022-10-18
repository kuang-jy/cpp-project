#include <iostream>
using namespace std;

void swap(int& a,int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

//维护堆
void heapify(int arr[],int n,int i){
    int largest = i;
    //找出根结点，左右孩子中最大的下标
    int lc = i*2 + 1;
    int rc = i*2 + 2;
    if(lc < n && arr[largest] < arr[lc]) largest = lc;
    if(rc < n && arr[largest] < arr[rc]) largest = rc;
    //把最大值换到父节点
    if(largest != i){
        swap(arr[largest],arr[i]);
        //递归维护
        heapify(arr,n,largest);
    }
}

void heap_sort(int arr[],int n){
    //从第一个非叶节点开始
    int i;
    //建堆
    for(i = n/2 -1;i >= 0;i--){
        heapify(arr,n,i);
    }
    //排序
    for(int i = n-1;i > 0;i--){
        cout << arr[0] << " ";
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,3,8,1,4,9,10,7,16,14};
    int n = 10;
    heap_sort(arr,n);
    return 0;
}
