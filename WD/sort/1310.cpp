#include <iostream>
using namespace std;
int n,cnt,arr[10010];

void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
    for(int i = 0;i < n-1;i++){
        int flag = 0;
        for(int j = 0;j < n-i;j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
                cnt++;
                flag = 1;
            }
        }
        if(!flag) break;
    }
    printf("%d\n",cnt);
    return 0;
}