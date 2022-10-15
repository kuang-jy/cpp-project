#include <bits/stdc++.h>
using namespace std;
int n,rx,cy;

void resolve(int size,int nx,int ny,int qx,int qy){
	if(size <= 1) return;
	int s = size/2;
	if(qx < nx+s && qy < ny+s){  //若公主在左上角的子棋盘 
		printf("%d %d 1\n",nx+s,ny+s);     //放置1号毯子
		//继续放置划分的四个
		resolve(s,nx,ny,qx,qy);
		resolve(s,nx,ny+s,nx+s-1,ny+s);
		resolve(s,nx+s,ny,nx+s,ny+s-1);
		resolve(s,nx+s,ny+s,nx+s,ny+s);
	}
	if(qx < nx+s && qy >= ny+s){  //若公主在右上角的子棋盘 
		printf("%d %d 2\n",nx+s,ny+s-1);     //放置2号毯子
		//继续放置划分的四个
		resolve(s,nx,ny,nx+s-1,ny+s-1);
		resolve(s,nx,ny+s,qx,qy);
		resolve(s,nx+s,ny,nx+s,ny+s-1);
		resolve(s,nx+s,ny+s,nx+s,ny+s);
	}
	if(qx >= nx+s && qy < ny+s){  //若公主在左下角的子棋盘 
		printf("%d %d 3\n",nx+s-1,ny+s);     //放置3号毯子
		//继续放置划分的四个
		resolve(s,nx,ny,nx+s-1,ny+s-1);
		resolve(s,nx,ny+s,nx+s-1,ny+s);
		resolve(s,nx+s,ny,qx,qy);
		resolve(s,nx+s,ny+s,nx+s,ny+s);
	}
	if(qx >= nx+s && qy >= ny+s){  //若公主在右下角的子棋盘 
		printf("%d %d 4\n",nx+s-1,ny+s-1);     //放置4号毯子
		//继续放置划分的四个
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

