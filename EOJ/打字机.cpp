#include<iostream>
#include<cstring>
using namespace std;

int n;
string str;

int main(){
    // std::ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    cin >> n;
    while(n--){
        cin >> str;
        int cnta = 0, pos = str.size()-1, flag = 0;
        for(pos = str.size()-1;pos >= 0 && str[pos] == 'a';pos--);
        str = str.substr(0,pos+1);
        for(char& ch : str){
            if(ch == 'a') cnta++;
            else if(cnta == 0) { 
                cout << "Dead Fang\n";
                flag = 1;
                break;
            }
            else 
                cnta--;
        }
        if(!flag){
            if(cnta != 0) cout << "Sad Fang\n";
            else cout << "Happy Fang\n";
        }
    }
    return 0;
}