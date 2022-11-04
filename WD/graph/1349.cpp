#include <iostream>
using namespace std;
int n,arr[110],k,ans;

struct node{
    int from,to,cost;
}edges[10010];

int find(int a){
    if(a != arr[a])
        arr[a] = find(arr[a]);  //路径压缩
    return arr[a];
}

void Union(int a,int b){
    arr[find(a)] = arr[find(b)];
}

void swap(node &a,node &b){
    node t = a;
    a = b;
    b = t;
}

int partition(int low,int high){
    node pivot = edges[low];
    int i = low;
    for(int j = low+1;j <= high;j++)
        if(edges[j].cost < pivot.cost)
            swap(edges[j],edges[++i]);
    swap(edges[i],edges[low]);
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
    for(int i = 1;i <= n;i++) arr[i] = i;  //并查集初始化
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++){
            int cost;
            cin >> cost;
            if(cost != 0){   //建边
                edges[k].from = i;
                edges[k].to = j;
                edges[k++].cost = cost;
            }
        }
    //边权排序
    qsort(0,k-1);
    //选边
    for(int i = 0;i < k;i++){
        if(find(edges[i].from) != find(edges[i].to)){
            Union(edges[i].from,edges[i].to);
            ans += edges[i].cost;
        }
    }
    printf("%d\n",ans);
    return 0;
}