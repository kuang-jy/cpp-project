#include<bits/stdc++.h>

using namespace std;

/*
	有一个容量为V的背包，还有n个物体。现在忽略物体实际几何形状，我们认为只要背包的剩余容量大于等于物体体积，那就可以装进背包里。
	每个物体都有两个属性，即体积w和价值v。
	每个物体是可以切分的 
	问：如何向背包装物体才能使背包中物体的总价值最大？

	使用贪婪策略：每次都选择 单位价值最大 的物品放入背包 
*/ 
#define N 100
int w[N],v[N];
float x[N];
float ans[N];

//将物品按照单位价值降序排列 
int partition(int low,int high){
	float pivot = x[low];
	int a = w[low];
	int b = v[low];
	while(low < high){
		while(low < high && x[high] <= pivot) high--;
		x[low] = x[high];
		w[low] = w[high];
		v[low] = v[high];
		while(low < high && x[low] >= pivot) low++;
		x[high] = x[low];
		w[high] = w[low];
		v[high] = v[low];
	}
	x[low] = pivot;
	w[low] = a;
	v[low] = b;
	return low;
}

void sort(int low,int high){
	if(low >= high) return;
	int pivot = partition(low,high);
	sort(low,pivot-1);
	sort(pivot+1,high);
}


void greedyKnap(int n,int weight){
	int i;
	sort(0,n-1);
	for(i = 0;i < n;i++) ans[i] = 0;
	for(i = 0;i < n;i++){
		if(w[i] > weight) break;
		ans[i] = 1;
		weight -= w[i];
	}
	if(i < n) ans[i] = weight*1.0/w[i];
}

int main(){
	int n,weight;
	cin >> n >> weight;
	for(int i = 0;i < n;i++){
		cin >> w[i] >> v[i];
	}
	//计算单位价值 
	for(int i = 0;i < n;i++)
		x[i] = v[i]*1.0/w[i];
	greedyKnap(n,weight);
	for(int i = 0;i < n;i++) cout << ans[i] << " ";
    return 0;
}

