#include <bits/stdc++.h>
using namespace std;
//��׺���ʽ�ļ��㣬ʹ������ģ��ջ����������ջ����������ջ�����������ѹ��ջ�� 
//3.5.2.-*7.+@

char op;
int stk[51];
int k,a,b,top = -1;  //ջ��ָ��
int num = 0;  //��¼������ ;

int main(){
	while((op = getchar()) != '@'){
		if(op >= '0' && op <= '9') num = num*10+(op-'0');  //���������
		else if(op == '.') {   //��������ջ 
			stk[++top] = num; 
			num = 0;
		}
		else if(op == '+'){    //���������������ջ 
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

