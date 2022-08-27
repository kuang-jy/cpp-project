#include<bits/stdc++.h>

using namespace std;
void swap(int& a,int& b);
void adjust(int arr[],int len,int root);
void buildMaxHeap(int arr[],int len);
void maxHeapSort(int arr[],int len);

void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//简单选择排序（不稳定）  时间：O(n^2)  空间：O(1) 
void chooseSort(int arr[],int len){
	int min = 0,i;
	for(int j = 0;j < len-1;j++){   //一共要选len-1次 
		min = j;  //初始化min为无序数组的第一个 
		for(i = j;i < len;i++){   //每次从第一个无序子组开始选 
			if(arr[i] < arr[min]) min = i;
		}
		swap(arr[min],arr[j]);
	}
} 

//堆排序
/*
大根堆：完全二叉树中，根 >= 左，右
小根堆：完全二叉树中，根 <= 左，右 
*/
 
//通过序列，建立大根堆
//调整大根堆 
void adjust(int arr[],int len,int root){
	arr[0] = arr[root];  //暂存root结点值 
	for(int i = 2*root;i <= len;i*=2){  //从root的左孩子开始 
		if(i < len && arr[i] < arr[i+1]) i++;  //如果有右孩子，比较左右孩子，取较大者
		if(arr[0] >= arr[i]) break;  //如果根结点最大，那么调整结束
		else{   //如果孩子比根大 
			arr[root] = arr[i];   //孩子结点变成根结点 
			root = i;   //改变root为孩子，判断是否还要继续调整 
		}
		arr[root] = arr[0];  //最后root的位置就是最终位置  
	} 
} 
//这里arr从下标1开始记录 
void buildMaxHeap(int arr[],int len){
	//完全二叉树的非终端结点是 [1,2/n]
	for(int i = len/2;i >= 1;i--)    //从最下层的分支结点开始 
		adjust(arr,len,i);     //调整大根堆 
}
//堆排序，每次选择堆顶元素交换到未排序序列的最后，并且调整大根堆 
//时间：O(nlog2n) 空间：O(1) 
//不稳定 
void maxHeapSort(int arr[],int len){  //大根堆排序得到递增序列
	buildMaxHeap(arr,len); 
	while(len){
		swap(arr[1],arr[len]);
		adjust(arr,--len,1);
	}
}

//堆的插入和删除

 
void disp(int arr[],int len){
	for(int i = 0;i <len;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[10] = { NULL,10,3,6,23,44,56,99,1,21 };
//	chooseSort(arr,9);
//	disp(arr,8);
	maxHeapSort(arr,9);
	disp(arr,10);
    return 0;
}

