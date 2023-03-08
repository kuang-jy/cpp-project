#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;

string in = "a+b-a*((c+d)/e-f)+g";
string pre = "+-+ab*a-/+cdefg";
string post = "ab+acd+e/f-*-g+";

int getPriority(char n){
    if(n == '+' || n == '-') return 0;
    return 1;
}

//中缀转后缀
void in2post(){
    char stk[MAX],ans[MAX];
    int len = in.length();
    int top1 = -1,top2 = -1;
    int i = 0;
    while(in[i] != '\0'){
        if(in[i] >= 'a' && in[i] <= 'z') ans[++top2] = in[i++];
        else if(in[i] == '(') stk[++top1] = in[i++];
        else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/'){
            if(top1 == -1 || getPriority(in[i]) > getPriority(stk[top1]) || stk[top1] == '(') stk[++top1] = in[i++];
            else ans[++top2] = stk[top1--];
        }
        else if(in[i] == ')'){
            while(stk[top1] != '(')
                ans[++top2] = stk[top1--];
            top1--;
            i++;
        }
    }
    while(top1 >= 0) ans[++top2] = stk[top1--];
    for(int i = 0;i <= top2;i++) printf("%c ",ans[i]);
    printf("\n");
}

//中缀转前缀
void in2pre(){
    char stk[MAX],ans[MAX];
    int top1 = -1,top2 = -1;
    int len = in.length();
    int i = len-1;
    while(i >= 0){
        if(in[i] >= 'a' && in[i] <= 'z')  //如果是操作数，直接进结果栈
            ans[++top2] = in[i--];
        //栈空，右括号，当前操作符优先级小于等于栈顶优先级直接进操作符栈
        else if(in[i] == ')') stk[++top1] = in[i--];
        else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' ){  //如果是操作符，进行判断
                if(top1 == -1 || getPriority(in[i]) >= getPriority(stk[top1]) || stk[top1] == ')') stk[++top1] = in[i--];
                else ans[++top2] = stk[top1--];
        }
        else if(in[i] == '('){  //左括号
            while(stk[top1] != ')'){
                ans[++top2] = stk[top1--];
                // cout << ans[top2] << " ";
            }
            top1--;
            i--;
        }
    }
    while(top1 >= 0)
        ans[++top2] = stk[top1--];
    for(int i = top2;i >= 0;i--) printf("%c ",ans[i]);
    printf("\n");
}

//中缀表达式计算
string exp = "3+4*5*(2+3)";

int calc(float a,char exp,float b,float& ans){
    if(exp == '/' && b == 0) return 0;
    if(exp == '+') ans = a+b;
    else if(exp == '-') ans = a-b;
    else if(exp == '*') ans = a*b;
    else ans = a/b;
    return 1;
}

float calcIn(){
    float stk1[MAX],ans;
    char stk2[MAX];
    int top1 = -1,top2 = -1;
    int i = 0;
    while(exp[i] != '\0'){
        if(exp[i] >= '0' && exp[i] <= '9') stk1[++top1] = exp[i++] - '0';  //操作数直接入栈
        else if(exp[i] == '(') stk2[++top2] = exp[i++];  //左括号直接入栈
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){  //操作符判断直接入栈还是先计算
            if(top2 == -1 || stk2[top2] == '(' || getPriority(exp[i]) > getPriority(stk2[top2]))  //直接入栈
                stk2[++top2] = exp[i++];
            else{
                float a = stk1[top1--], b = stk1[top1--],result;
                int flag = calc(b,stk2[top2--],a,result);
                if(!flag) {
                    printf("ERROR!\n");
                    return -1;
                }
                stk1[++top1] = result;
            }
        }
        else if(exp[i] == ')'){
            while(top2 >= 0 && stk2[top2] != '('){
                float b = stk1[top1--],a = stk1[top1--];
                int flag = calc(a,stk2[top2--],b,ans);
                if(!flag) { printf("exp error!\n"); return 0;}
                stk1[++top1] = ans;
            }
            top2--;
            i++;
        } 
    }
    while(top2 >= 0){
        float b = stk1[top1--],a = stk1[top1--];
        int flag = calc(a,stk2[top2--],b,ans);
        if(!flag) { printf("exp error!\n"); return 0;}
        stk1[++top1] = ans;
    }
    printf("%.2f\n",stk1[0]);
}

//后缀表达式计算
string postexp = "34523+**+";

void calcPost(){
    float stk[MAX];
    int top = -1, i = 0;
    while(postexp[i] != '\0'){
        if(postexp[i] >= '0' && postexp[i] <= '9') stk[++top] = postexp[i++] - '0';
        else {
            float b = stk[top--],a = stk[top--],c;
            int flag = calc(a,postexp[i++],b,c);
            if(!flag) { printf("exp error!\n"); return;}
            stk[++top] = c;
        }
    }
    printf("%.2f\n",stk[top]);
}

//前缀表达式计算
string preexp = "+3*4*5+23";

void calcPre(){
    int top = -1,i = preexp.length()-1;
    float stk[MAX];
    while(i >= 0){
        if(preexp[i] >= '0' && preexp[i] <= '9') stk[++top] = preexp[i--] - '0';
        else {
            float c;
            int flag = calc(stk[top--],preexp[i--],stk[top--],c);
            if(!flag) return;
            stk[++top] = c;
        }
    }
    printf("%.2f\n",stk[0]);
}

int main(){
    // in2pre();
    // in2post();
    calcIn();
    // calcPost();
    // calcPre();
}