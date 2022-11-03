#include <iostream>
#include <cstring>
using namespace std;
int n,size;
struct node{
    string name;
    int sc;
}arr[22];

void swap(node &n1,node &n2){
    node t = n1;
    n1 = n2;
    n2 = t;
}

int partition(int low,int high){
    node pivot = arr[low];
    int i = low;
    for(int j = low+1;j <= high;j++){
        if(arr[j].sc > pivot.sc) swap(arr[j],arr[++i]);
        else if(arr[j].sc == pivot.sc && arr[j].name < pivot.name) swap(arr[j],arr[++i]);
    }
    swap(arr[i],arr[low]);
    return i;
}

void qsort(int low,int high){
    if(low >= high) return;
    int pivot = partition(low,high);
    qsort(low,pivot-1);
    qsort(pivot+1,high);
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) cin >> arr[i].name >> arr[i].sc;
    qsort(0,n-1);
    for(int i = 0;i < n;i++) cout << arr[i].name << " " << arr[i].sc << endl;
    return 0;
}