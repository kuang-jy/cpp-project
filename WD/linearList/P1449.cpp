#include <bits/stdc++.h>
using namespace std;
//��׺���ʽ�ļ��㣬ʹ������ģ��ջ����������ջ����������ջ�����������ѹ��ջ�� 
//3.5.2.-*7.+@
char a[51];
double stk[51];
int k,n=1;

int main(){
	int top = -1;  //ջ��ָ��
	while(cin >> a[++k]) if(a[k] == '@') break;
	for(int i = 1;i <= k;i++){
		switch(a[i]){
			double n1,n2;
			case '.':break;
			case '@':cout << stk[top] << endl;
					return 0;
			case '+':
				n1 = stk[top--];
				n2 = stk[top--];
				stk[++top] = n2+n1;
				break;
			case '-':
				n1 = stk[top--];
				n2 = stk[top--];
				stk[++top] = n2-n1;	
				break;
			case '*':
				n1 = stk[top--];
				n2 = stk[top--];
				stk[++top] = n2*n1;	
				break;
			case '/':
				n1 = stk[top--];
				n2 = stk[top--];
				stk[++top] = n2/n1;	
				break;
			default:stk[++top] = a[i]-'0';
		}
	}
	return 0;
}

