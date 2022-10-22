#include <iostream>
using namespace std;
int n,k,set[110];

struct node{
    int s,e,w;
}edges[100000];

int partition(int low,int high){
    node pivot = edges[low];
    while (low < high)
    {
        while(low < high && edges[high].w >= pivot.w) high--;
        edges[low] = edges[high];
        while(low < high && edges[low].w <= pivot.w) low++;
        edges[high] = edges[low];
    }
    edges[low] = pivot;
    return low;
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
    int ans = 0;
    cin >> n>>k;
    for(int i = 0;i < k;i++){
        int a,b,c;
        cin >> a>>b>>c;
        edges[i].s = a;
        edges[i].e = b;
        edges[i].w = c;
    }
    qsort(0,k-1);  //边权升序排列
    for(int i = 1;i <= n;i++) set[i] = i;
    for(int i = 0;i < k;i++){
        int s = edges[i].s,e = edges[i].e,w = edges[i].w;
        if(find(s) == find(e)) ans += w;
        else Union(s,e); 
    }
    cout << ans;
    return 0;
}
