#include <iostream>
#include <algorithm>
using namespace std;
int n;

struct node{
    int s,e;
}nodes[50010];

bool cmp(node n1,node n2){
    if(n1.s == n2.s) return n1.e < n2.e;
    return n1.s < n2.s;
}

// int partition(int low,int high){
//     int pivot = s[low],tmp = e[low];
//     while(low < high){
//         while(low < high) {
//             if(s[high] > pivot) high--;
//             else if(s[high] == pivot && e[high] < tmp) high--;
//             else break;
//         }
//         s[low] = s[high];
//         e[low] = e[high];
//         while(low < high){
//             if(s[low] < pivot) low++;
//             else if(s[low] == pivot && e[low] > tmp) low++;
//             else break;
//         } 
//         s[high] = s[low];
//         e[high] = e[low];
//     }
//     e[low] = tmp;
//     s[low] = pivot;
//     return low;
// }

// void qsort(int low,int high){
//     if(low >= high) return;
//     int pivot = partition(low,high);
//     qsort(low,pivot-1);
//     qsort(pivot+1,high);
// }

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d %d",&nodes[i].s,&nodes[i].e);
    // qsort(0,n-1);
    sort(nodes,nodes+n,cmp);
    int end = nodes[0].e;
    for(int i = 1;i < n;i++)
        if(nodes[i].s > end){
            printf("no\n");
            return 0;
        }
        else if(nodes[i].e > end) end = nodes[i].e;
    printf("%d %d\n",nodes[0].s,end);
    return 0;
}