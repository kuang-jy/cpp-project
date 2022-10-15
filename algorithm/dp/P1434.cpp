#include <iostream>
#include <algorithm>
using namespace std;
int r,c,dp[10010];
const int dx[] = {-1,1,0,0},dy[] = {0,0,1,-1};   //λ������  

struct node{
	int x,y,h;
}map[10010];

bool cmp(node n1,node n2){   //���߶Ƚ������� 
	return n1.h > n2.h;
}

int main(){
	cin >> r >> c;
	int k = 0,ans = 1;
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			map[k].x = i;
			map[k].y = j;
			cin >> map[k++].h;
		}
	}
	sort(map,map+k,cmp);
	for(int i = 0;i < k;i++) dp[i] = 1;  //��ʼ��ÿ����Ļ��о��붼��1
	for(int i = 1;i < k;i++){    //���µ�ǰ�� 
		for(int j = i-1;j >= 0;j--){   //ö�����и߶ȸ��ڵ�ǰ��ĵ� 
			if(map[j].h == map[i].h) continue;
			for(int l = 0;l < 4;l++){   //�ĸ����� 
				if(map[j].x+dx[l] == map[i].x && map[j].y+dy[l] == map[i].y)  //������Ի���
					dp[i] = max(dp[j]+1,dp[i]);
					ans = max(ans,dp[i]);
			}
		}	
	} 
	printf("%d",ans);
	return 0;
}





//int r,c;
//int dp[10001];  //dp[]����: dp[i]��ʶ��i���������µĳ���   dp[i] = max{dp[j]+1,dp[i]}  ��Ҫ�ӵ������ 
//int dx[4]={0,0,1,-1};//��¼��������������
//int dy[4]={1,-1,0,0};
//
//struct snow{
//	int x,y,h;  //����͸߶� 
//}a[10001];
//bool cmp(snow x,snow y){return x.h>y.h;}//���߶Ƚ�������
//
//int main(){
//	cin >> r >> c;
//	int k = 0;
//	for(int i = 1;i <= r;i++)
//		for(int j = 1;j <= c;j++){
//			cin >> a[++k].h;
//			dp[k] = 1;  //��ʼ�߶�Ϊ1 
//			a[k].x = i;
//			a[k].y = j; 
//		}
//	sort(a+1,a+1+k,cmp);//����
//		for(int i = 1;i <= k ;i++)
//		cout << a[i].h <<endl;
//	int m = 1;
//	for(int i=1;i<=k;i++){    //��ʼdp 
//        for(int j=i-1;j>0;j--){
//            for(int u=0;u<4;u++){   //ö�ٷ��򣬿�i��j�Ƿ����� 
//        		if(a[i].x+dx[u]==a[j].x && a[i].y+dy[u]==a[j].y && a[j].h>a[i].h) {
//        			dp[i]=max(dp[i],dp[j]+1);
//        			//�����ǰ��������������ڣ�����j�ĸ߶ȴ���i������Կ���״̬ת�� 
//        			m = m > dp[i] ? m : dp[i];
//				}
//        	}
//    	}
//    }
//    
//    cout << m;
//	return 0;
//}

