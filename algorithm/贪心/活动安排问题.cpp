#include<bits/stdc++.h>

using namespace std;

//�������ʱ���������У�ѡ���һ������������Ƚ�
//	1������һ����Ŀ�ʼʱ����ڵ������ڻ�Ľ���ʱ�䣬��ô������һ����������µ�ǰ�
//	2��������������� 
void greedyManagement(int n,int s[],int f[],bool a[]){   //n�����ÿ����Ŀ�ʼʱ�䣬����ʱ�䣬�Ƿ��� 
	a[0] = true;
	int j = 0;
	for(int i = 1;i < n;i++){
		if(s[i] >= f[j]) {
			a[i] = true;
			j = i;
		}
		else a[i] = false;
	}
}

int main(){

    return 0;
}

