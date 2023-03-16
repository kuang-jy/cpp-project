#include<iostream>
#include<cmath>
using namespace std;

int n,a;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    while(n--){
        cin >> a;
        a = (a-1)*2;
        int b = sqrt(a);
        if (b*(b+1)==a) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}