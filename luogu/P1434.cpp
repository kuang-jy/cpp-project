#include <bits/stdc++.h>
using namespace std;

int r,c;
int dp[10001];  //dp[]����: dp[i]��ʶ��i���������µĳ���   dp[i] = max{dp[j]+1,dp[i]}  ��Ҫ�ӵ������ 
int dx[4]={0,0,1,-1};//��¼��������������
int dy[4]={1,-1,0,0};

struct snow{
	int x,y,h;  //����͸߶� 
}a[10001];
bool cmp(snow x,snow y){return x.h>y.h;}//���߶Ƚ�������

int main(){
	cin >> r >> c;
	int k = 0;
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++){
			cin >> a[++k].h;
			dp[k] = 1;  //��ʼ�߶�Ϊ1 
			a[k].x = i;
			a[k].y = j; 
		}
	sort(a+1,a+1+k,cmp);//����
		for(int i = 1;i <= k ;i++)
		cout << a[i].h <<endl;
	int m = 1;
	for(int i=1;i<=k;i++){    //��ʼdp 
        for(int j=i-1;j>0;j--){
            for(int u=0;u<4;u++){   //ö�ٷ��򣬿�i��j�Ƿ����� 
        		if(a[i].x+dx[u]==a[j].x && a[i].y+dy[u]==a[j].y && a[j].h>a[i].h) {
        			dp[i]=max(dp[i],dp[j]+1);
        			//�����ǰ��������������ڣ�����j�ĸ߶ȴ���i������Կ���״̬ת�� 
        			m = m > dp[i] ? m : dp[i];
				}
        	}
    	}
    }
    
    cout << m;
	return 0;
}

