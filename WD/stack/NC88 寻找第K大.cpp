class Solution {
public:
    
    void swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    int partition(vector<int>& a,int low,int high,int K){
        int pivot = a[low];  //ѡȡ����Ԫ��
        int i = low;    //��Ǵ�������Ԫ�ؽ�β
        int j = high;
        int ans = 0;
        while(i < j){
            while(i < j && a[j] <= pivot) j--;
            a[i] = a[j];
            while(i < j && a[i] >= pivot) i++;
            a[j] = a[i];
        }
//         for(int j = low+1;j <=high;j++)
//             if(a[j] > pivot) swap(a[++i],a[j]);  //�������Ļ���ǰ��
        a[i] = pivot;
        
        //���ݴ�С�ݹ�Ѱ��
        if(K == i+1) return a[i];
        else if(K < i+1) ans = partition(a, low, i-1,K);
        else ans = partition(a, i+1, high,K);
        return ans;
    }
    
    int findKth(vector<int> a, int n, int K) {
        return partition(a, 0, n-1, K);
    }
};
