#include<iostream>
using namespace std;

int n,m,k;

int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    //初始化队列
    int quem[m+1],quewm[n+1];
    int f1 = 0,t1 = 0,f2 = 0,t2 = 0;
    for(int i = 0;i < m;i++) quem[t1++] = i+1;
    for(int j = 0;j < n;j++) quewm[t2++] = j+1;
    while(k--){
        //循环队列
        cout << quem[f1] << " " << quewm[f2] << endl;
        quem[t1] = quem[f1];
        quewm[t2] = quewm[f2];
        t1 = (t1+1)%(m+1);
        t2 = (t2+1)%(n+1);
        f1 = (f1+1)%(m+1);
        f2 = (f2+1)%(n+1);
    }
    return 0;
}