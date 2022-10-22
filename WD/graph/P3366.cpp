#include <iostream>
using namespace std;
int n,m,set[5100];
struct edge{
    int a,b,w;
}edges[200010];

void swap(int& a,int& b){
    int tmp = a;
    a = b;b = tmp;
}

int find(int a){
    while(set[a] != a) a = set[a];
    return a;
}

void Union(int a,int b){
    set[find(b)] = find(a);
}

int partition(int low,int high){
    int pivot = edges[low].w;
    int i = low;
    for(int j = low+1;j <= high;j++){
        if(edges[j].w < pivot) swap(edges[++i],edges[j]);
    }
    swap(edges[low],edges[i]);
    return i;
}

void qsort(int low,int high){
    if(low > high) return;
    int pivot = partition(low,high);
    qsort(low,pivot-1);
    qsort(pivot+1,high);
}

int main(int argc, char const *argv[])
{
    int ans = 0;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int aa,bb,cc;
        cin >> aa>>bb>>cc;
        edges[i].a = aa;
        edges[i].b = bb;
        edges[i].w = cc;
    }
    qsort(0,m-1);  //边权排序
    //初始化并查集
    for(int i = 1;i <= n;i++) set[i] = i;
    //Kruskal
    for(int i = 0;i < m;i++){
        int x = edges[i].a,y = edges[i].b,w = edges[i].w;
        if(find(x) != find(y)){
            ans += w;
            Union(x,y);
        }        
    }
    //判断是否连通
    int tag = find(1);
    for(int i = 2;i <= n;i++)
        if(find(i) != tag){
            printf("orz");
            return 0;
        }
    cout << ans;
    return 0;
}
