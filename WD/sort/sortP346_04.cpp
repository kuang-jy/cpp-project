#include<bits/stdc++.h>

using namespace std;

typedef struct lNode{
	int data;
	lNode *next;
}lNode,*linkList;

//����ͷ���ĵ����� 
//�ҵ����Ľ�㣬ͷ�巨�������� 
void chooseSort(linkList& L){
	
	lNode* p = L;  //����ԭ���ָ�� 
	lNode* cur;    //����ָ��
	lNode* pre;    //����ָ���ǰ�� 
	lNode* max;   //����� 
	lNode* maxPre;   //������ǰ�� 
	
	L = NULL;   //��L�ÿգ���Ϊ������� 
	
	while(p){   //����ѡ������ ����ԭ���ָ�� 
	
		cur = p;  //��ʼ������ָ��Ϊԭ��ĵ�һ����� 
		pre = NULL;  
		max = p;  //Ĭ���������ԭ���һ����� 
		maxPre = NULL;
		
		while(cur){  //��ͷ��β���� 
			if(cur->data > max->data){  //�����ֵ 
				max = cur;
				maxPre = pre;
			}
			pre = cur;
			cur = cur->next;
		}  // end while 
		
		if(max == p) p = p->next;  //����������Ǳ�ͷ����Ϊ��Ҫժ��max�������ñ���ԭ���ָ���Ⱥ��� 
		else maxPre->next = max->next;  //��max���ժ�� 
		max->next = L;   //ͷ���������� 
		L = max;  //�����±�ͷ 
	}  //end while
	
}

//β�巨���������� 
linkList genList(){
	int data;
	cin >> data;
	lNode* node = (lNode*)malloc(sizeof(lNode));
	node->next = NULL;
	lNode* r = node;
	while(data != -1){
		lNode* p = (lNode*)malloc(sizeof(lNode));
		p->data = data;
		r->next = p;
		r = p;
		cin >> data;
	}
	r->next = NULL;
	return node->next;
}

void disp(linkList L){
	while(L){
		cout << L->data << "->";
		L = L->next;
	}
	cout << endl;
}

int main(){
	linkList L = genList();
	disp(L);
	chooseSort(L);
	disp(L);
    return 0;
}

