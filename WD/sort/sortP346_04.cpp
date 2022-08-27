#include<bits/stdc++.h>

using namespace std;

typedef struct lNode{
	int data;
	lNode *next;
}lNode,*linkList;

//不带头结点的单链表 
//找到最大的结点，头插法插入链表 
void chooseSort(linkList& L){
	
	lNode* p = L;  //遍历原表的指针 
	lNode* cur;    //工作指针
	lNode* pre;    //工作指针的前驱 
	lNode* max;   //最大结点 
	lNode* maxPre;   //最大结点的前驱 
	
	L = NULL;   //将L置空，作为结果链表 
	
	while(p){   //控制选择趟数 遍历原表的指针 
	
		cur = p;  //初始化工作指针为原表的第一个结点 
		pre = NULL;  
		max = p;  //默认最大结点是原表第一个结点 
		maxPre = NULL;
		
		while(cur){  //从头到尾遍历 
			if(cur->data > max->data){  //找最大值 
				max = cur;
				maxPre = pre;
			}
			pre = cur;
			cur = cur->next;
		}  // end while 
		
		if(max == p) p = p->next;  //如果最大结点就是表头，因为将要摘下max，所以让遍历原表的指针先后移 
		else maxPre->next = max->next;  //将max结点摘下 
		max->next = L;   //头插入新链表 
		L = max;  //设置新表头 
	}  //end while
	
}

//尾插法建立单链表 
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

