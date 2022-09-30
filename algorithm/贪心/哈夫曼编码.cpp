#include<bits/stdc++.h>

using namespace std;

/*
	一般用于文件压缩，假设一个文件共有100000个字符，6种不同的字符a,b,c,d,e,f组成，这些字符出现频率如下：
	a:45 b:13 c:12 d:16 e:9 f:5  （千次） 
	
	将字符按照出现频度降序排列，每次选取最小的两个字符组成一个树，并将这两个字符从数组删掉，将组成的数的根节点放入数组，直到数组中只有一个字符为止 
*/

#define maxSize 20

typedef struct Node{
	int weight;
	char id;
	Node *left,*right;
}Node;

int partition_w(Node* t[],int low,int high){  //快排划分，升序 
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

void quickSort(Node* t[],int low,int high){  //快排 
	if(low >= high) return;
	int pivot = partition_w(t,low,high);
	quickSort(t,low,pivot-1);
	quickSort(t,pivot+1,high);
}

Node* bulidTree(int weight[],char id[],int n){
	Node *que[maxSize],*s,*p,*q;
	int rear = -1,front = -1;
	for(int i = 0;i < n;i++){  //初始化
		s = (Node*)malloc(sizeof(Node));
		s->weight = weight[i];
		s->left = s->right = NULL;
//		rear = (rear+1)%maxSize;
		que[++rear] = s;
	}
	quickSort(que,front+1,rear);
	
	while(front+1 < rear){  //队列中至少两个元素 
	
		p = que[++front];  //取出前两个最小元素
		q = que[++front];
		
		s = (Node*)malloc(sizeof(Node));  //两个最小元素组成的根节点 
		s->left = p;
		s->right = q;
		s->weight = p->weight+q->weight;
//		rear = (rear+1)%maxSize;  //进入队列 
		que[++rear] = s;
		quickSort(que,front+1,rear);  //重新排序 
		cout << s->weight << "**" << endl;
	}
//	cout << que[rear]->weight;
	return que[rear];
}

void inOrder(Node* root){  //中序遍历 
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

