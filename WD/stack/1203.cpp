#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
string str,ans;
int n,top,i;
int stk[110];

int main(){
    while(cin >> str){
        n = str.length();
        top = -1;
        ans = "";
        for(int i = 0;i < n;i++){
            if(str[i] == '('){    //左括号全部标记
                stk[++top] = i;   //栈记录左括号的下标
                ans+='$';
            }
            else if(str[i] == ')'){   //若可以和右括号匹配，修改对应左括号为空格
                if(top < 0) ans += '?';
                else {ans += ' '; ans[stk[top--]] = ' ';}
            } 
            else ans += ' ';
        }
        cout << str << endl;
        cout << ans << endl;
    }
    return 0;
}