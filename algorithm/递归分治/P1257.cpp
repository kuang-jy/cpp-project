#include <bits/stdc++.h>
using namespace std;
int n,rx,cy;

void resolve(int size,int nx,int ny,int qx,int qy){
	if(size <= 1) return;
	int s = size/2;
	if(qx < nx+s && qy < ny+s){  //�����������Ͻǵ������� 
		printf("%d %d 1\n",nx+s,ny+s);     //����1��̺��
		//�������û��ֵ��ĸ�
		resolve(s,nx,ny,qx,qy);
		resolve(s,nx,ny+s,nx+s-1,ny+s);
		resolve(s,nx+s,ny,nx+s,ny+s-1);
		resolve(s,nx+s,ny+s,nx+s,ny+s);
	}
	if(qx < nx+s && qy >= ny+s){  //�����������Ͻǵ������� 
		printf("%d %d 2\n",nx+s,ny+s-1);     //����2��̺��
		//�������û��ֵ��ĸ�
		resolve(s,nx,ny,nx+s-1,ny+s-1);
		resolve(s,nx,ny+s,qx,qy);
		resolve(s,nx+s,ny,nx+s,ny+s-1);
		resolve(s,nx+s,ny+s,nx+s,ny+s);
	}
	if(qx >= nx+s && qy < ny+s){  //�����������½ǵ������� 
		printf("%d %d 3\n",nx+s-1,ny+s);     //����3��̺��
		//�������û��ֵ��ĸ�
		resolve(s,nx,ny,nx+s-1,ny+s-1);
		resolve(s,nx,ny+s,nx+s-1,ny+s);
		resolve(s,nx+s,ny,qx,qy);
		resolve(s,nx+s,ny+s,nx+s,ny+s);
	}
	if(qx >= nx+s && qy >= ny+s){  //�����������½ǵ������� 
		printf("%d %d 4\n",nx+s-1,ny+s-1);     //����4��̺��
		//�������û��ֵ��ĸ�
		resolve(s,nx,ny,nx+s-1,ny+s-1);
		resolve(s,nx,ny+s,nx+s-1,ny+s);
		resolve(s,nx+s,ny,nx+s,ny+s-1);
		resolve(s,nx+s,ny+s,qx,qy);
	}
}

int main(){
	cin >> n >> rx >> cy;
	resolve(pow(2,n),1,1,rx,cy);
	return 0;
}

