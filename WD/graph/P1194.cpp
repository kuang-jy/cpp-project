#include <iostream>
using namespace std;
int b,set[260000];

struct node{
    int s,e,w;
}edges[260000];

void swap(int& a,int& b){
    int tmp = a;
    a = b;b = tmp;
}

int partition(int low,int high){
    int pivot = edges[low].w;
    int i = low;
    for(int j = low+1;j <= high;j++){
        if(edges[j].w < pivot) swap(edges[++i],edges[j]);
    }
    swap(edges[i],edges[low]);
    return i;
}

void qsort(int low,int high){
    if(low >= high) return;
    int pivot = partition(low,high);
    qsort(low,pivot-1);
    qsort(pivot+1,high);
}

int find(int a){
    while(set[a] != a) a = set[a];
    return a;
}

void Union(int a,int b){
    set[find(b)] = find(a);
}

int main(int argc, char const *argv[])
{
    int ans;
    cin >> ans >> b;
    int k = 0,w;
    for(int i = 1;i <= b;i++)
        for(int j = 1;j <= b;j++){
            cin >> w;
            if(!w || j <= i) continue;
            edges[k].s = i;
            edges[k].e = j;
            edges[k++].w = w;
        }
    qsort(0,k-1);
    for(int i = 1;i <= b;i++) set[i] = i;
    for(int i = 0;i < k;i++){
        int s = edges[i].s,e = edges[i].e,w = edges[i].w;
        if(find(s) != find(e)){
            ans += w;
            Union(s,e);
        }
    }
    cout << ans;
    return 0;
}