#include <bits/stdc++.h>
using namespace std;

/*
	������������һ����n����װ��Ҫװ��һ��������Ϊc�Ĵ������м�װ��i������Ϊwi���� ��wi <= c��
	��Ҫ��ȷ��һ�������װ�ڷ����ɽ���n����װ��װ�����Ҵ����Ҽ�װ������������١�����У��ҳ�һ�֡� 
*/
#define maxSize 10
#define INF 1000
int w[] = {0,5,2,6,4,3};
int n = 5,c = 10;
int maxW;  //������Ž��������
int x[maxSize];  //������Ž����� 
int minNum = INF;   //������Ž�ļ�װ�����

void dfs(int num,int tw,int rw,int op[],int i){	  //num��ѡ��װ�������twѡ��������ܺͣ�rwʣ��������ܺͣ�op��ʾһ����������i���ڿ��ǵļ�װ��i
	if(i > n){  //˵�����м�װ�䶼���ж����ˣ�һ����һ�����н⣬��֤�Ƿ����Ž� 
		if(tw > maxW && num < minNum){   //�ж��Ƿ�������Ž� 
			maxW = tw;
			minNum = num; 
			for(int i = 1;i <= n;i++) x[i] = op[i];  //����ѡ������ 
		}
	}
	else{  //�ж��Ƿ���չ��ǰ��װ�� 
		if(tw+w[i] <= c){    //��֦����1 
			op[i] = 1;
			dfs(num+1,tw+w[i],rw-w[i],op,i+1);  //������һ����װ���ж� 
		}
		if(tw+rw-w[i] >= c)  //��֦����2
			dfs(num,tw,rw-w[i],op,i+1); 
	} 
} 

void disp(){
	for(int i = 1;i <= n;i++)
		if(x[i])
			cout << "select #" << i << " ";
	cout << endl;
	cout << maxW << endl << minNum << endl; 
}

int main(){
	int op[maxSize];
	for(int i = 0;i < maxSize;i++) op[i] = 0;
	int rw = 0;
	for(int i = 1;i <= n;i++) rw += w[i];
	dfs(0,0,rw,op,1);
	disp();
	return 0;
}

