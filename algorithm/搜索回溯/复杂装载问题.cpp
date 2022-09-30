#include <bits/stdc++.h>
using namespace std;

/*
	������������һ����n����װ��Ҫװ��һ���������ֱ�Ϊc1,c2�Ĵ������м�װ��i������Ϊwi���� ��wi <= c1+c2��
	��Ҫ��ȷ��һ�������װ�ڷ����ɽ���n����װ��װ����2�Ҵ�������У��ҳ�һ�֡�

	���裺
		1���������ܶ�ļ�װ��װ����һ�Ҵ��ϣ��õ�������x 
		2���ۼƵ�һ��װ���ʣ�༯װ������sum
		3�����sum <= c2,����true�����򷵻�false 
*/
#define maxSize 10
int maxW=0,c1=50,c2=50,n=3;
int w[] = {0,10,40,40};
int x[maxSize];

void dfs(int tw,int rw,int op[],int i){
	if(i > n){
		if(tw <= c1 && tw > maxW) maxW = tw;
		for(int i = 1;i <= n;i++) x[i] = op[i];		
	}
	else{
		if(tw+w[i] <= c1){
			op[i] = 1;
			dfs(tw+w[i],rw-w[i],op,i+1);
		}
		else{
			if(tw + rw - w[i] > maxW)
				dfs(tw,rw-w[i],op,i+1);
		}
	}
}

bool solve(){
	int sum = 0;
	for(int i = 1;i <= n;i++) 
		sum += x[i]*w[i];
	if(sum <= c2) return true;
	return false;
}

void disp(){
	for(int i = 1;i <=n;i++)
		if(x[i])
			cout << "choose #" << i << " ";
	cout << "to boat 1" << endl;
	for(int i = 1;i <=n;i++)
		if(!x[i])
			cout << "choose #" << i << " ";
	cout << "to boat 2" << endl;	
}

int main(){
	int op[maxSize];
	for(int i = 0;i < maxSize;i++)
		op[i] = 0;
	int rw = 0;
	for(int i = 1;i <= n;i++)
		rw+=w[i];
	dfs(0,rw,op,1);
	if(solve()) disp();
	else cout << "�޽�" << endl; 
	return 0;
}

