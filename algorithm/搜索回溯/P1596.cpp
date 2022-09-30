#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
char a[101][101];
//λ������ 
const int dx[] = {-1,-1,-1,1,1,1,0,0};
const int dy[] = {-1,0,1,-1,0,1,-1,1};

bool check(int x,int y){
	if(x >= 1 && x <= n && y >= 1 && y <= m) return true;
	return false;
}

void dfs(int x,int y){   //����һ�������ѵ��ף��߲���ȥ�˻������������Խ�������ͨ��ˮ�����½�� 
	a[x][y] = '.';   //���½�� 
	for(int i = 0;i < 8;i++){   //8���������� 
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(check(nx,ny) && a[nx][ny] == 'W')   //����ɴ� ���� ��ˮ���Ǿͼ����� 
			dfs(nx,ny);
	}
}

int main(){
	cin >> n >> m;
	for(int i =1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> a[i][j];
	
	for(int i =1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(a[i][j] == 'W'){
				dfs(i,j);
				cnt++;
			}
	cout << cnt;
	return 0;
}

