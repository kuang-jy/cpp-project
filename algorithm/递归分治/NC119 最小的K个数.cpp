class Solution {
public:
    
    int partition(vector<int>& arr,int low,int high,int k){
        int pivot = arr[low];
        int i = low;
        for(int j = low+1;j <= high;j++)
            if(arr[j] < pivot) swap(arr[++i],arr[j]);
        swap(arr[low], arr[i]);
        
        if(i+1 == k) return i;
        else if(i+1 > k) return partition(arr, low, i-1, k);
        else return partition(arr, i+1, high, k);
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ans;
        if(!k || !input.size()) return ans;
        int pivot = partition(input, 0, input.size()-1, k);
        for(int i = 0;i <= pivot;i++) ans.push_back(input[i]);
        return ans;
    }
};
