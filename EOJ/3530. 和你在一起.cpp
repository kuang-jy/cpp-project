#include<iostream>
#include<cstring>
using namespace std;
int n;
string arr[20];


bool check(string& a,string& b){
    return a+b > b+a;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> arr[i];
    string res = "";
    for(int i = 1;i < n;i++){   //冒泡排序
        for(int j = n-1;j >= i;j--){
            if(check(arr[j],arr[j-1]))
                swap(arr[j],arr[j-1]);
        }
    }
    for(int i = 0;i < n;i++) res+=(arr[i]);
    cout << res;
    return 0;
}