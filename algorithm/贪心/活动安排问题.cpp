#include<bits/stdc++.h>

using namespace std;

//将活动结束时间升序排列，选择第一个活动，依次向后比较
//	1、若下一个活动的开始时间大于等于现在活动的结束时间，那么安排下一个活动，并更新当前活动
//	2、否则继续向后遍历 
void greedyManagement(int n,int s[],int f[],bool a[]){   //n个活动，每个活动的开始时间，结束时间，是否安排 
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

