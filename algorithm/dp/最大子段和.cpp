#include<bits/stdc++.h>

using namespace std;

/*
	������n������(����Ϊ������)��ɵ�����a1��a2�� a3�� �� an�� Ѱ������ĳ�������ӶΣ�ʹ������������( -2,11,-4,13,-5,-2 )����Ӷ���{ 11,-4,13 }���Ϊ20��
	
*/ 


//������
void solve1(int a[],int n){
	int start = 0;//��ʼλ��
	int end = 0;//����λ��
	int max = 0;
	for(int i = 0; i <= n; ++i){
    	int sum = 0;
	    for(int j = i; j <= n;++j){
	        sum += a[j];
	        if(sum > max){
	           start = i;
	           end = j;
	           max = sum;
	        }
	    }
	} 
	cout << max << endl;
} 

//���η�
//������a[1:n]��Ϊ a[1:2/n] a[2/n+1,n]
//��ô����Ӷκ�ֻ���������������
//								1����[1, n/2]���������
//								2����[n/2+1, n]���������
//								3�����λ��[1,n/2],�յ�λ��[n/2+1,n]�� 
int solve2(int a[],int left,int right){
	if(left == right) return a[left] > 0 ? a[left] : 0;  //���ֻ��һ�����ˣ����һ��Ǹ�������ֱ�Ӳ���
	int mid = (left+right)/2;
	//���һ 
	int leftmax = solve2(a,left,mid); 
	//����� 
	int rightmax = solve2(a,mid+1,right);
	//���������Ҫ�������
	int sum = 0;
	int lefttemp = 0,righttemp = 0;
	for(int i = mid;i >= left;i--){
		sum += a[i];
		if(lefttemp < sum) lefttemp = sum;
	} 
	sum = 0;
	for(int i = mid+1;i <= right;i++){
		sum += a[i];
		if(righttemp < sum) righttemp = sum;
	} 
	sum = lefttemp+righttemp;
	if(sum < leftmax) sum = leftmax;
	if(sum < rightmax) sum = rightmax;
	return sum;
} 

//��̬�滮��
/*
	��b[j]��ʾ��λ�� j Ϊ�յ�������������к�����һ��
	������:��jΪ�յ����������������λ��j-1,����j-1Ϊ�յ������������Ȼ����������
	���b[j-1] >0, ��ô��Ȼb[j] = b[j-1] + a[j]����֮ǰ����һ������a[j]����
	���b[j-1]<=0,��ôb[j] = a[j] ,��Ϊ��Ȼ���ǰ��ĸ�����Ȼ����ʹ�����
*/
int solve3(int a[],int n){
	int max = 0,b = 0;
	for(int i = 0;i < n;i++){
		if(b > 0) b+= a[i];
		else b = a[i];
		if(b > max) max = b;
	}
	return max;
} 

int main(){
	int a[] = {-2,11,-4,13,-5,-2};
	solve1(a,5);
	cout << solve2(a,0,5) << endl;
	cout << solve3(a,6) << endl;
    return 0;
}

