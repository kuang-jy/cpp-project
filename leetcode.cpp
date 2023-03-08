#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    //剑指 Offer 47. 礼物的最大价值
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof dp);
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++)
                if(i == 1 && j == 1) dp[i][j] = grid[0][0];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
        return dp[m][n];
    }
    //剑指 Offer 48. 最长不含重复字符的子字符串
    int lengthOfLongestSubstring(string s) {   //同向双指针
        int left = 0, right = 0, ans = 0, n = s.length();
        int used[256];
        memset(used,0,sizeof used);
        while(right < n){
            used[s[right]]++;
            while(used[s[right]] > 1) used[s[left++]]--;
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
    //剑指 Offer 49. 丑数
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int a = 0,b = 0,c = 0;
        for(int i = 1;i < n;i++){
            int aa = dp[a]*2, bb = dp[b]*3, cc = dp[c]*5;
            dp[i] = min(min(aa,bb),cc);
            if(dp[i] == aa) a++;
            if(dp[i] == bb) b++;
            if(dp[i] == cc) c++;
        }
        return dp[n-1];
    }
    //剑指 Offer 50. 第一个只出现一次的字符
    char firstUniqChar(string s) {
        int used[26];
        memset(used,0,sizeof used);
        for(char x: s) used[x-'a']++;
        for(char x: s) 
            if(used[x-'a'] == 1)
                return x;
        return ' ';
    }
    // 剑指 Offer 51. 数组中的逆序对
    void merge2(vector<int>& nums,int low,int mid,int high,int& cnt){
        int temp[50010];
        int k = low,i = low,j = mid+1;
        for(int h = low;h <= high;h++) temp[h] = nums[h];
        while(i <= mid && j <= high){
            if(temp[i] <= temp[j]) nums[k++] = temp[i++];
            else {  //产生逆序
                nums[k++] = temp[j++];
                cnt += (mid-i+1);
            }
        }
        while(i <= mid) nums[k++] = temp[i++];
        while(j <= high) nums[k++] = temp[j++];
    }    
    void mSort(vector<int>& nums,int low,int high,int& cnt){
        if(low >= high) return;
        int mid = low+(high-low)/2;
        mSort(nums,low,mid,cnt);
        mSort(nums,mid+1,high,cnt);
        merge2(nums,low,mid,high,cnt);
    }
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        mSort(nums,0,nums.size()-1,cnt);
        return cnt;
    }
    //2099. 找到和最大的长度为 K 的子序列
    struct node{
        int val,idx;
    };
    node* getHeap(int k){
        node heap[k+1];
        return heap; 
    }
    void swap(node& n1,node& n2){
        node t = n1;
        n1 = n2;
        n2 = t;
    }
    void adjust_up(int idx,node*& heap){
        while(idx <= 1){
            if(heap[idx].val > heap[idx/2].val)
                swap(heap[idx],heap[idx/2]);
            idx /= 2;
        }
    }
    void adjust_down(int idx,int k,node*& heap){
        int ch = idx*2;
        while(idx <= k){
            if(idx < k && heap[ch].val < heap[ch+1].val) ch++;
            if(heap[ch].val > heap[idx].val){
                swap(heap[ch],heap[idx]);
                idx = ch;
                ch = idx*2;
            }
            else return;
        }
    }
    void put(int num,int idx,node*& heap){
        heap[idx].val = num;
        adjust_up(idx,heap);
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        node* heap = getHeap(k);
        int i = 0;
        for(int x : nums){
            if(i == k && heap[1].val < x)
                heap[1].val = x;
            if(i < k) {put(x,i+1,heap); i++;}
        }
        vector<int> ans;
        return ans;
    }
    //剑指 Offer 52. 两个链表的第一个公共节点
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(NULL){}
    };
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1 != p2){
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
    //剑指 Offer 53 - I. 在排序数组中查找数字 I
    int search(vector<int>& nums, int target) {
        int low = 0,high  = nums.size()-1,mid,ll,rr;
        //二分左边界
        while(low <= high){
            mid = low+(high-low)/2;
            if(nums[mid] < target) high = mid-1;
            else low = mid+1;
        }
        ll = high;
        //二分右边界
        low = 0,high = nums.size()-1;
        while(low <= high){
            mid = low+(high-low)/2;
            if(nums[mid] <= target) low = mid+1;
            else high = mid-1;
        }
        rr = low;
        return high-low+1;
    }
    //剑指 Offer 53 - II. 0～n-1中缺失的数字
    int missingNumber(vector<int>& nums) {
        int low = 0,high = nums.size()-1,mid;
        while(low <= high){
            mid = low+(high-low)/2;
            if(nums[mid] > mid) high = mid - 1;
            else low = mid+1;
        }
        return low;
    }
    //剑指 Offer 54. 二叉搜索树的第k大节点
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    void dfs(TreeNode* root,int& val,int& k){
        if(!root) return;
        dfs(root->right,val,k);
        if(!k) return;
        if(!--k){
            val = root->val;
            return;
        }
        dfs(root->left,val,k);
    }
    int kthLargest(TreeNode* root, int k) {
        int val;
        dfs(root,val,k);
        return val;
    }
};

int main(){
    Solution s;
//     vector<vector<int>> grid({
//      {1,3,1},
//      {1,5,1},
//      {4,2,1} });
    // cout << s.maxValue(grid);
    // cout << s.lengthOfLongestSubstring("bbbbb");
    // cout << s.nthUglyNumber(7);
    // cout << s.firstUniqChar("abaccdeff");
    vector<int> nums{7,5,6,4};
    cout << s.reversePairs(nums);
    return 0;
}