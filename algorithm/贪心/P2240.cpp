#include <bits/stdc++.h>
using namespace std;
int n;
double t,w[101],v[101],ans;

void sortw(int n,double w[],double v[]){
	double ww[n+1];
	for(int i = 1;i <= n;i++)
		ww[i] = v[i]/w[i];  //��λ��ֵ
	
	for(int i = 1;i <= n;i++){
		int maxIdx = i;  //Ĭ�ϵ�һ�����
		for(int j = i+1;j <=n;j++)
			if(ww[maxIdx] < ww[j])	maxIdx = j;
		swap(ww[i],ww[maxIdx]);  //������ֵ����ǰ��
		swap(w[i],w[maxIdx]);
		swap(v[i],v[maxIdx]); 
	}
}

int main(){
	cin >> n>>t;
	for(int i=1 ;i <= n;i++)
		cin >> w[i] >> v[i];
	sortw(n,w,v);
	int i = 1;
	while(t >= w[i]){
		t-=w[i];
		ans+=v[i++];
	}
	ans += (t/w[i])*v[i];
	printf("%.2f",ans);
	return 0;
}

