#include<bits/stdc++.h>

using namespace std;


//������������
//����n�������A1,A2,��,An��������Ai��Ai+1�ǿɳ˵ģ�i=1��2����n-1��
//���ȷ������������˻��ļ������ʹ�����˴������������˻���Ҫ����˴������� 
/*
	��Ai*Ai+1*...*Aj���ΪA[i:j]������Ai��ά�ȼ�Ϊpi-1*pi
 	����Ŀ�������A[1:n]�����Ž⣬��һ�����Ų��Ե��Ӳ���Ҳ�����ŵģ�������Ŀ�ɷֽ�Ϊ��A[i:j]�����ż������
	��AiAi+1��Aj�����ż�������ھ���Ak��Ak+1֮�佫�������Ͽ��õ���(Ai�� Ak) (Ak+1 ��Aj)
	�ܵļ��������ǣ�A[i:k]�ļ�������A[k+1: j]�ļ�����+A[i:k]��A[k+1:j]��˵ļ�����
*/ 

//p���Ai��ά����pi�������ά���� pi-1*pi 
//m�����С�˷�����
//s��Ŷ���λ�� 

#define N 7  //NΪ7��ʵ��6������ 0��0�к��� 

void MatrixChain(int p[],int n,int m[][N],int s[][N]){
	for(int i = 1;i <= n;i++) m[i][i] = 0;  //������ֻ��һ������ʱ����ʼ���Խ���Ϊ0
	
	for(int l=2;l<=n;l++) {		//l��ʾ�������ĳ���
		for(int i = 1;i <= n-l+1;i++){   //�����ϲ�ѭ�����������������˵���ʼ�� 
			int j = i+l-1;  //ĩβ������
			m[i][j] = m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];  //Ĭ����õĻ��ַ����Ǵӵ�һ�������Ͽ���֮���и��õ��ٸ��� 
			s[i][j] = i;
			for(int k = i+1;k < j;k++){  //��i+1��ʼ�������� 
				int temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];  
				if(temp < m[i][j]){
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		} 
	} 
}

void TraceBack(int i, int j, int s[][N]){
	if(i == j) cout <<"A"<<i;
	else{
		cout << "(";
		TraceBack(i,s[i][j],s);
		TraceBack(s[i][j]+1,j,s);
		cout << ")";
	}
}

int main(){
	int p[N] = {30,35,15,5,10,20,25};  //����ά��
	int m[N][N],s[N][N];
	MatrixChain(p,N-1,m,s);
	TraceBack(1,6,s);
	cout << endl << m[1][N-1] << endl;
    return 0;
}

