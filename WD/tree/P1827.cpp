#include <bits/stdc++.h>
using namespace std;

string in,pre;

void bulid(string in,string pre,int l1,int h1,int l2,int h2){
	if(l1 > h1 || l2 > h2) return;
	int k = l1;  //�������ĸ��±� 
	while(pre[l2] != in[k]) k++;
	int lenl = k-l1;  //������������
	bulid(in,pre,l1,k-1,l2+1,l2+lenl);   //�ݹ������� 
	bulid(in,pre,k+1,h1,l2+lenl+1,h2);   //�ݹ������� 
	cout << pre[l2];  //����� 
}

int main(){
	cin >> in >> pre;
	bulid(in,pre,0,in.length()-1,0,pre.length()-1);
	return 0;
}

