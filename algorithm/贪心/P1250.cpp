#include <iostream>
using namespace std;
int n,h,used[30010];

struct req{
    int s,e,num;
}reqs[5010];

void swap(int& a,int& b){
    int tmp = a;
    a = b;b = tmp;
}

int partition(int low,int high){
    int i = low;
    req pivot = reqs[low];
    for(int j = low+1;j <= high;j++){
        if(reqs[j].e < pivot.e) swap(reqs[++i],reqs[j]);
        else if(reqs[j].e == pivot.e && reqs[j].s > pivot.s) swap(reqs[++i],reqs[j]);
    }
    swap(reqs[i],reqs[low]);
    return i;
}

void qsort(int low,int high){
    if(low >= high) return;
    int pivot = partition(low,high);
    qsort(low,pivot-1);
    qsort(pivot+1,high);
}

int main(int argc, char const *argv[])
{
    cin >> n >> h;
    for(int i = 0;i < h;i++)
        cin >> reqs[i].s >> reqs[i].e >> reqs[i].num;
    qsort(0,h-1);
    int cnt,ans = 0;
    for(int i = 0;i < h;i++){
        cnt = 0;
        //统计当前区间种了几棵树
        for(int j = reqs[i].s;j <= reqs[i].e;j++)
            if(used[j] == 1) cnt++;
        if(cnt < reqs[i].num)  //如果种的不够当前区间
            for(int j = reqs[j].e;j >= reqs[i].s;j--)
                if(!used[j]){
                    cnt++;
                    used[j] = 1;
                    ans++;
                    if(cnt == reqs[i].num) break;
                }
    }
    cout << ans;
    return 0;
}
