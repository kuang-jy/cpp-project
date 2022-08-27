#include <bits/stdc++.h>
using namespace std;

#define maxSize 20
#define INF 1000
int g[maxSize][maxSize];   //�ڽӾ��� 
int color[maxSize];    //��¼ÿ��������ɫ
int cnt,m,n;  //��������m����ɫ��n������ 

bool check(int num,int i){   //����num���������ɫ�Ƿ����Ϊi 
	for(int j = 1;j <= n;j++){
		if(g[num][j] == 1 && color[j] == i) return 0;   //�ڽӲ�����ɫ��ͬ 
	}
	return 1;
}

void GraphColor(int num){   //�Ե�num������ɫ 
	if(num > n){    //���Ѿ�����߽磬�������һ����н�
		for(int i = 1;i <= n;i++)
			cout << color[i] << " ";
		cout << endl;
		cnt++;
		return;
	}
	else{    //�жϵ�ǰ�����ɫ 
		for(int i = 1;i <= m;i++){   //����������ɫ 
			if(check(num,i)){
				color[num] = i;
				GraphColor(num+1);
			}
		}
	}
}

int main(){
	/*
5 3
0 1 1 0 0
1 0 0 1 1
1 0 0 0 0
0 1 0 0 1
0 1 0 1 0
	*/
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> g[i][j];
	GraphColor(1);
	cout << cnt << endl;
	return 0;
}

