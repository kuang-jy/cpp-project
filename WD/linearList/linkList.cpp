//
// Created by Kjoye on 2022/7/17.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct linkNode{
    int data;
    linkNode* next;
}linkNode, *linkList;

typedef struct doubleNode{
    int data;
    doubleNode *prior,*next;
    int freq;
}doubleNode, *DLinkList;

linkList init(linkList& L){
    L = (linkList)malloc(sizeof(linkNode));
    L->next = nullptr;
    linkNode* node;
    linkNode* r = L;
    int j;
    scanf("%d",&j);
    for (int i = 1; i <= j; i++)
    {
        int k;
        scanf("%d",&k);
        node = (linkNode*)malloc(sizeof(linkNode));
        node->data = k;
        node->next = nullptr;
        r->next = node;
        r = r->next;
    }
    return L;
}

//P40 01
void delX(linkList& L,int x){
    if(L == nullptr) return;
    linkNode *temp;
    if(L->data == x){
        temp = L;
        L = L->next;
        free(temp);
        delX(L,x);
    }
    else delX(L->next,x);
}

//P40 02
void delX2(linkList& L,int x){
    if(L->next == nullptr) return;
    linkNode *pre = L;
    linkNode *cur = L->next;
    linkNode *temp;
    while(cur){
        if(cur->data == x) {
            temp = cur;
            pre->next = cur->next;
            cur = cur->next;
            free(temp);
        } else{
            pre = cur;
            cur = cur->next;
        }
    }//while
}

//P40 03
void revPrint(linkList L){
    if(L->next != nullptr) revPrint(L->next);
    cout << L->data << "->";
}

//P40 04
void delMin(linkList& L){
    linkNode *pre=L,*cur=L->next;
    linkNode *min=cur,*minpre=pre;
    while (cur){
        if(cur->data < min->data){
            min = cur;
            minpre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    minpre->next = min->next;
    free(min);
}

//P40 05
void reverse_1(linkList& L){
    linkNode *pre = L,*cur = L->next,*q = L->next->next;
    cur->next = nullptr; //第一个结点
    while (q){
        pre = cur;
        cur = q;
        q = q->next;
        cur->next = pre;
    }
    L->next = cur;
}
//P40 05
void reverse_2(linkList& L){
    linkNode *cur= L->next,*curnext;
    L->next = nullptr;  //断开头结点
    while (cur){
         curnext = cur->next;
         cur->next = L->next;
         L->next = cur;
         cur = curnext;
    }
}

//P40 06
void sortList(linkList& L){
    linkNode *cur = L->next,*r = cur->next;
    linkNode *p;
    cur->next = nullptr;  //第一个元素摘下
    cur = r;
    while (cur){
        //先保存当前结点的后继
        r = r->next;
        //从摘下的链表头开始遍历
        p = L;
        //找到插入的元素位置，插入在P的后面
        while (p->next && p->next->data < cur->data){
            p = p->next;
        }
        //插入
        cur->next = p->next;
        p->next = cur;
        //cur后移
        cur = r;
    }
}

//P40 07
void delx2y(linkList& L,int x,int y){
    linkNode *cur = L->next;
    linkNode *pre = L;
    while (cur){
        if(cur->data < y && cur->data > x){
            pre->next = cur->next;
            cur = cur->next;
        }
        else{
            pre = cur;
            cur = cur->next;
        }
    }
}

//P40 08
linkNode* getCommon(linkList L1,linkList L2){
    linkNode *p1 = L1->next;
    linkNode *p2 = L2->next;
    while(p1 != p2){
        p1 = p1 ? p1->next : L2->next;
        p2 = p2 ? p2->next : L1->next;
    }
    return p1;
}

//P40 09
void outList(linkList L){
    while (L->next){
        linkNode *cur=L->next,*pre=L;
        while (cur->next){
            if(cur->next->data < pre->next->data){
                pre = cur;
            }
            cur = cur->next;
        }
        cout << pre->next->data << "->";
        linkNode *temp = pre->next;
        pre->next = temp->next;
        free(temp);
    }
    free(L);
    cout << '\n';
}

//P40 10
linkList divide2(linkList& L){
    //将链表中按序奇偶分成两个链表A，B
    int tag = 0;  //标识奇偶
    linkList B = (linkList) malloc(sizeof (linkNode));
    B->next = nullptr;
    linkNode *ra = L,*rb = B,*p = L->next;
    L->next = nullptr;
    while (p){
        tag++;
        if(tag%2 == 0){
            rb->next = p;
            rb = p;
        }
        else{
            ra->next = p;
            ra = p;
        }
        p = p->next;
    }
    ra->next = nullptr;
    rb->next = nullptr;
    return B;
}

//P40 11
linkList divide2_1(linkList& L){
    linkList B = (linkList) malloc(sizeof(linkNode));
    B->next = nullptr;
    linkNode *p = L->next; //工作指针，初始为奇
    linkNode *ra = L;  //a的尾指针
    linkNode *q;  //记录下一元素，防止断链
    while(p){
        ra->next = p;
        ra = p;
        p = p->next;  //偶结点
        if(p){
            q = p->next; //记录偶节点的下一结点
            //头插法
            p->next = B->next;
            B->next = p;

            p = q;  //奇结点
        }
    }
    ra->next = nullptr;
    return B;
}

//P40 12
void del(linkList& L){
    linkNode *fast = L->next->next;
    linkNode *slow = L->next;
    while (fast){
        if(slow->data != fast->data) slow = fast;
        else slow->next = fast->next;
        fast = fast->next;
    }
}

//P40 13
void merge2(linkList &l1,linkList l2){
    linkNode *pa = l1->next;
    linkNode *pb = l2->next;
    linkNode *temp;
    l1->next = nullptr;  //将表1作为合并后的新表
    while(pa && pb){
        //头插法
        if(pa->data <= pb->data){
            temp = pa->next;
            pa->next = l1->next;
            l1->next = pa;
            pa = temp;
        }
        else{
            temp = pb->next;
            pb->next = l1->next;
            l1->next = pb;
            pb = temp;
        }
    }//while
    //处理剩余的一个表
    if(pa) pb = pa;
    while (pb){
        temp = pb->next;
        pb->next = l1->next;
        l1->next = pb;
        pb = temp;
    }
}

//P40 15
void Union(linkList &l1,linkList &l2){
    //两个表的工作指针
    linkNode *pa = l1->next;
    linkNode *pb = l2->next;
    linkNode *ra = l1; //新表的尾指针
    ra->next = nullptr;  //断链，作为新表的表头
    while (pa && pb){
        if(pa->data == pb->data){
            //尾插
            ra->next = pa;
            ra = pa;
            //指针都后移
            pa = pa->next;
            pb = pb->next;
        }
        else if(pa->data < pb->data) pa = pa->next;
        else pb = pb->next;
    }//while
}

//P40 16
bool isSubSquence(linkList l1,linkList l2){
    linkNode *p1 = l1->next;
    linkNode *p2 = l2->next;
    linkNode *pre = p1;  //记录当前比较的元素
    while (p1 && p2){
        if(p1->data == p2->data){
            p1 = p1->next;
            p2 = p2->next;
        } else{
            p1 = pre->next;  //原始序列回到pre的下一个
            p2 = l2->next;  //子序列回到开头
            pre = p1;  //pre后移到当前比较元素
        }
    }
    if(p2 == nullptr) return true;
    return false;
}

//P40 17
bool isDuichen(DLinkList L){
    doubleNode *l = L->next;  // 指向开头
    doubleNode *r = L->prior; // 指向结尾
    while(l != r && l->next != r){  //奇数和偶数的终止条件
        if(l->data == r->data){  //如果相同则继续比较
            l = l->next;  //l向后
            r = r->prior;  //r向前
        } else return false;
    }
    return true; //比较到最后，说明是对称的
}

//P40 18
linkList merge2(linkList &h1,linkList &h2){
    linkNode *t1 = h1->next,*t2 = h2->next;  //分别指向尾结点
    //找到尾结点
    while (t1->next != h1) t1 = t1->next;
    while (t2->next != h2) t2 = t2->next;
    t1->next = h2->next;
    t2->next = h1;
    return h1;
}

//P41 19
void getDdelmin(linkList &L){
    linkNode *min,*minp,*cur,*pre;
    while (L->next){
        //每趟都需要先初始化
        min = L->next;
        minp = L;
        cur = L->next;
        pre = L;
        //找到最小元素和前驱
        while (cur != L){
            if(cur->data < min->data){
                min = cur;
                minp = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        printf("%d ",min->data);  //输出最小值
        minp->next = min->next;  //将最小值断开
        free(min); //释放空间
    }
    free(L);  //释放头结点
}

//P41 20
DLinkList Locate(DLinkList &L,int x){
    doubleNode *cur = L->next,*pre = L;
    //查找x
    while (cur && cur->data != x){
        cur = cur->next;
    }
    //没找到
    if(!cur) return nullptr;
    //找到了
    else{
        cur->freq++;   //访问次数加一
        //当查找结点为第一个结点 或 查找结点的前驱结点freq比他大 不需要移动
        if(cur->prior == L || cur->freq < cur->prior->freq) return cur;
        //将查找结点摘下
        if(cur->next) cur->next->prior = cur->prior;
        cur->prior->next = cur->next;
        //向前查找cur的位置
        pre = cur->prior;
        while (pre != L && pre->data <= cur->data) pre = pre->prior;  //指针前移
        //将cur插入到按递减插入到同频率的第一个
        cur->next = pre->next;
        pre->next->prior = cur;
        cur->prior = pre;
        pre->next = cur;
    }
    return cur;
}

//P41 21
linkNode* hasCircle(linkList L){
    linkNode *slow = L,*fast = L;  //快慢指针都从头出发
    while (fast && fast->next){
        slow = slow->next;  //慢指针一次一步
        fast = fast->next->next;  //快指针一次两步
        if(fast == slow) break;  //相遇 或 没有环
    }
    if(!fast || !fast->next) return nullptr;  //没有环
    fast = L;  //fast回到第一个结点
    while (fast != slow){   //同时向前走
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

//P41 22
linkNode* getRevK(linkList L,int k){
    linkNode *fast = L->next,*slow = L->next;
    while (k--) {  //快指针先行k步
        if(fast->next) fast = fast->next;
        else return nullptr;  //若走不到k步 说明链表不存在导数第k个
    }
    //同时向后遍历
    while (fast){
        fast = fast->next;
        slow = slow->next;
    }
    //最后slow指向的就是导数第k个结点
    return slow;
}

//P41 23
linkNode* getCommen23(linkList L1,linkList L2){
    linkNode *p1 = L1;  //初始化p1指向链表1的头结点
    linkNode *p2 = L2;  //初始化p2指向链表2的头结点
    while (p1 != p2){   //p1 p2指向同一位置 即为第一个共同结点，或是没有共同结点
        p1 = p1 ? p1->next : L2; //如果p1已经完成遍历L1，那就让p1开始遍历L2，否则继续遍历L1
        p2 = p2 ? p2->next : L1; //如果p2已经完成遍历L2，那就让p2开始遍历L1，否则继续遍历L2
    }
    return p1;
}

//P41 24
void delDuplicate(linkList& L,int n){
    linkNode *p = L;  //工作指针
    int *arr = (int*) malloc(sizeof (int)*(n+1));  //辅助数组，标记元素是否出现
    for(int i = 0;i < n+1;i++){  //初始化数组
        arr[i] = 0;  //初始化为0
    }
    int num;
    linkNode *temp;
    while (p->next){  //遍历链表
        num = p->next->data > 0 ? p->next->data : -p->next->data ;  //取绝对值
        if(arr[num] == 0){  //如果还没出现过
            arr[num]++;
            p = p->next;
        } else{     //如果已经出现过
            temp = p->next;  //删除
            p->next = temp->next;
            free(temp); //释放内存
        }
    }
    free(arr);  //释放数组内存
}

void change_list(linkNode* head){
    linkNode *fast = head,*slow = head;
    //找到中间结点
    while (fast->next){
        fast = fast->next;
        fast = fast->next ? fast->next : fast; //防止fast为null
        slow = slow->next;
    }
    //此时slow指向中间结点的前一个，fast指向最后一个结点
    fast = slow->next;  //fast指向逆转链表的第一个结点
    slow->next = nullptr;  //断开前半部分
    linkNode *temp;
    while (fast){
        temp = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        fast = temp;
    }
    linkNode *p = head;  //前半部分的第一个数据结点
    fast = slow->next;   //后半部分的第一个数据结点
    slow->next = nullptr;
    while (fast){
        temp = fast->next;  //记录后半部分的下一个结点
        fast->next = p->next->next;  //插入前部
        p->next = fast; //插入前部
        p = fast->next;  //下一插入位置
        fast = temp;  //下一插入结点
    }
}

void show(linkList L){
    L = L->next;
    while(L) {
        printf("%d->",L->data);
        L = L->next;
    }
    printf("\n");
}

int main() {
    linkList L;
    init(L);
    cout << "*****" << endl;
    linkList A;
    init(A);
//    delX(L,2);
//    delX2(L,2);
//    revPrint(L->next);
//    cout<<'\n';
//    delMin(L);
//    reverse_1(L);
//    reverse_2(L);
//    sortList(L);
//    delx2y(L,2,5);
//    show(getCommon(L,A));
//    outList(L);
    show(L);
    show(A);
//    linkList B = divide2_1(L);
//    del(L);
//    merge2(A,L);
//    Union(A,L);
//    cout << isSubSquence(L,A);
//    show(A);

//    show(B);
    return 0;
}
