#include<bits/stdc++.h>

using namespace std;

/*
	һ�������ļ�ѹ��������һ���ļ�����100000���ַ���6�ֲ�ͬ���ַ�a,b,c,d,e,f��ɣ���Щ�ַ�����Ƶ�����£�
	a:45 b:13 c:12 d:16 e:9 f:5  ��ǧ�Σ� 
	
	���ַ����ճ���Ƶ�Ƚ������У�ÿ��ѡȡ��С�������ַ����һ�����������������ַ�������ɾ��������ɵ����ĸ��ڵ�������飬ֱ��������ֻ��һ���ַ�Ϊֹ 
*/

#define maxSize 20

typedef struct Node{
	int weight;
	char id;
	Node *left,*right;
}Node;

int partition_w(Node* t[],int low,int high){  //���Ż��֣����� 
	Node* pivot = t[low];  
	while(low < high){
		while(low < high && t[high]->weight >= pivot->weight) high--;
		t[low] = t[high];
		while(low < high && t[low]->weight <= pivot->weight) low++;
		t[high] = t[low];
	}
	t[low] = pivot;
	return low;
}

void quickSort(Node* t[],int low,int high){  //���� 
	if(low >= high) return;
	int pivot = partition_w(t,low,high);
	quickSort(t,low,pivot-1);
	quickSort(t,pivot+1,high);
}

Node* bulidTree(int weight[],char id[],int n){
	Node *que[maxSize],*s,*p,*q;
	int rear = -1,front = -1;
	for(int i = 0;i < n;i++){  //��ʼ��
		s = (Node*)malloc(sizeof(Node));
		s->weight = weight[i];
		s->left = s->right = NULL;
//		rear = (rear+1)%maxSize;
		que[++rear] = s;
	}
	quickSort(que,front+1,rear);
	
	while(front+1 < rear){  //��������������Ԫ�� 
	
		p = que[++front];  //ȡ��ǰ������СԪ��
		q = que[++front];
		
		s = (Node*)malloc(sizeof(Node));  //������СԪ����ɵĸ��ڵ� 
		s->left = p;
		s->right = q;
		s->weight = p->weight+q->weight;
//		rear = (rear+1)%maxSize;  //������� 
		que[++rear] = s;
		quickSort(que,front+1,rear);  //�������� 
		cout << s->weight << "**" << endl;
	}
//	cout << que[rear]->weight;
	return que[rear];
}

void inOrder(Node* root){  //������� 
	if(!root) return;
	inOrder(root->left);
	cout << root->weight << " " ;
	inOrder(root->right);
}

int main(){
	Node *root;
    int weight[6]={45,13,12,16,9,5};
    char name[6]={'a','b','c','d','e','f'};
    root = bulidTree(weight,name,6);
    inOrder(root);	
    return 0;
}

