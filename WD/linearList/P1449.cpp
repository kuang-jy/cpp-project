#include <bits/stdc++.h>
using namespace std;
//后缀表达式的计算，使用数组模拟栈，操作数入栈，操作符出栈两个，计算后压入栈中 
//3.5.2.-*7.+@

char op;
int stk[51];
int k,a,b,top = -1;  //栈顶指针
int num = 0;  //记录操作数 ;

int main(){
	while((op = getchar()) != '@'){
		if(op >= '0' && op <= '9') num = num*10+(op-'0');  //计算操作数
		else if(op == '.') {   //操作数入栈 
			stk[++top] = num; 
			num = 0;
		}
		else if(op == '+'){    //操作符，计算后入栈 
			a = stk[top--],b = stk[top--];
			stk[++top] = b+a;
		}
		else if(op == '-'){
			a = stk[top--],b = stk[top--];
			stk[++top] = b-a;
		}
		else if(op == '*'){
			a = stk[top--],b = stk[top--];
			stk[++top] = b*a;
		}
		else if(op == '/'){
			a = stk[top--],b = stk[top--];
			stk[++top] = b/a;
		}
	}
	cout << stk[top];
	return 0;
}

