#include<bits/stdc++.h>

using namespace std;

//插入排序：直接插入排序，折半插入排序，希尔排序
 
//直接插入排序（不带哨兵） 时间：O(n^2) 空间：O(1) 
void insertSort(int arr[],int len){
	int j;
	for(int i = 1;i < len;i++)  //每次选中一个未排序的元素 
		if(arr[i] < arr[i-1]){  //比较当前数据和前一个数据大小 
			int temp = arr[i];   //保存当前数据，防止数据后移覆盖 
			for(j = i-1;j >= 0 && temp < arr[j];j--)  //循环比较，后移 
				arr[j+1] = arr[j];  //后移 
			arr[j+1] = temp;  //最后将该数据插入 
		}
}
//直接插入排序（带哨兵） 时间：O(n^2) 空间：O(1) 
void insertSortTag(int arr[],int len){
	int j;
	for(int i = 2;i < len;i++){  //0是哨兵 
		if(arr[i] < arr[i-1]){
			arr[0] = arr[i];
			for(j = i-1;arr[0] < arr[j];j--)  //不用判断 j>=0，因为0位置上是等于的 
				arr[j+1] = arr[j];
			arr[j+1] = arr[0];
		}
	}
}

//折半插入排序（带哨兵） 时间：O(n^2) 空间：O(1) 
void binaryInsertSort(int arr[],int len){
	for(int i =2;i < len;i++){
		int low = 1;
		int high = i-1;
		while(low <= high){  //二分查找 
			int mid = (low+high)/2;
			if(arr[mid] <= arr[i]) low = mid+1;  //保证稳定性，等号在此处取 
			else high = mid-1;
		}
		//要将low到i-1的数据后移
		arr[0] = arr[i];  //哨兵保存待排数据
		for(int j = i-1;j >= low;j--)  //后移 
			arr[j+1] = arr[j];
		arr[low] = arr[0];
	}
}

//希尔排序，不稳定  时间最坏：O(n^2)，当len在某个范围内O(n^1.3) 空间：O(1)
//不能用于链表排序 
//arr[0]是暂存单元，不是哨兵 
void shellSort(int arr[],int len){
	int j;
	for(int d = len/2;d >= 1;d/=2){  //步长变化
		for(int i=d+1; i <= len; i++){  //直接插入排序，每个子表中的元素交替进行，并不是一次排一个子表 
			if(arr[i] < arr[i-d]){
				arr[0] = arr[i];
				for(j = i-d; j > 0 && arr[0] < arr[j]; j-=d){  //后移元素 
					arr[j+d] = arr[j];
				}
				arr[j+d] = arr[0]; 
			}  //end if 
		} 
	}
} 
//*************** 插入排序end ************** 

//交换排序：冒泡排序，快速排序

//冒泡排序 时间：O(n^2) 空间：O(1) 
void bubbleSort(int arr[],int len){
	int temp;
	bool flag;
	for(int i = 0;i < len;i++){
		flag = false;  //标识本次交换是否产生交换 
		for(int j = len-1;j > i;j--){  //每趟都从最后一个元素开始 ，并且只需要比较到i后面一个元素即可 
			if(arr[j-1] > arr[j]){  //保证稳定性，不取等号 
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
		if(!flag) return;  //如果某次排序未产生交换，那么一定是已经有序，直接返回 
	}
} 

//快速排序（不稳定） 最好时间：O(nlog2n)  最坏时间：O(n^2)  平均时间：O(nlog2n) 
//		             最好空间：O(log2n)  最坏空间：O(n)  
int partition(int arr[],int low,int high){  //数组的划分函数 
	int pivot = arr[low];  //选择基准数
	while(low < high){
		while(low < high && arr[high] >= pivot) high--;  //若右子表元素比基准数大，则high指针不断前移
		arr[low] = arr[high];    //若是由于 arr[high] >= pivot 退出while，那么表示high指向的数据小于基准数，那么high指向的数据应放在low指向的位置，如果已经有序 high和low指向同一位置 
		while(low < high && arr[low] <= pivot) low++;  
		arr[high] = arr[low];
	}
	arr[low] = pivot;  //将基准数放在左右子表中间 
	return low;  //返回基准数位置 
}
void quickSort(int arr[],int low,int high){
	if(low >= high) return;  //只剩1个元素，已经有序，直接返回 
	int pivot = partition(arr,low,high);  //划分子表
	quickSort(arr,low,pivot-1);
	quickSort(arr,pivot+1,high); 
} 

//************* 交换排序end *************** 

void show(int arr[],int len){
	for(int i = 0;i <len;i++) 
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[]{-1,1,3,2,4,6,4,2,1,3};
//	insertSortTag(arr,9);
//	binaryInsertSort(arr,10);
//	shellSort(arr,9);
//	bubbleSort(arr,10);
	quickSort(arr,0,9);
	show(arr,10);
    return 0;
}

