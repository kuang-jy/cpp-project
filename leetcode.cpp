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
    //2379. 得到 K 个黑块的最少涂色次数
    int minimumRecolors(string blocks, int k) {
        int ans = 0;
        int cntw = 0;  //白色计数
        int left = 0, right = 0;
        while(right < k)  //创建一个宽度为k的滑动窗口
            if(blocks[right++] == 'W') cntw++;
        ans = cntw;
        while(right < blocks.length()){
            if(blocks[left++] == 'W') cntw--;
            if(blocks[right++] == 'W') cntw++;
            ans = min(ans,cntw);
        }
        return ans;
    }
    //2380. 二进制字符串重新安排顺序需要的时间
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int cnt0 = 0;
        int dp[n];   //dp[i]表示第i个位置调整好需要几次
        memset(dp,0,sizeof dp);
        for(int i = 0;i < n;i++){
            if(s[i] == '0') cnt0++;   //统计1前面的0
            // 对于1，若前面没有0，那么已经调整好
            //      若前面有0，那么有两种情况：
            //                         1.001 dp[i] = cnt0
            //                         2.0011 dp[i] = dp[i-1]+1
            // 对于0，dp[i] = dp[i-1];
            if(i == 0) continue;
            if(cnt0 && s[i] == '1') dp[i] = max(cnt0,dp[i-1]+1);
            else dp[i] = dp[i-1];  
        }
        return dp[n-1];
    }
    //2381. 字母移位 II
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> arr(n,0);  //差分数组
        vector<int> sum(n,0);  //前缀和数组
        for(vector<int> vec : shifts){
            arr[vec[0]] += vec[2] ? 1 : -1;
            if(vec[1]+1 < n)
                arr[vec[1]+1] += vec[2] ? -1 : 1;
        }
        for(int i = 0;i < n;i++)  //求前缀和
            if(i == 0) sum[i] = arr[i];
            else sum[i] = arr[i]+sum[i-1];
        for(int i = 0;i < n;i++){
            int c = s[i]-'a';
            c = ((c+sum[i])%26+26)%26;
            s[i] = 'a'+c;
        }
        return s;
    }
    //2383. 赢得比赛需要的最少训练时长
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int dp[n+1];
        int f = 0;
        for(int i = 1;i <= n;i++){
            if(initialEnergy > energy[i-1] && initialExperience > experience[i-1]){
                initialEnergy -= energy[i-1];
                initialExperience += experience[i-1];
            }
            else if(initialEnergy > energy[i-1]){
                f = f+experience[i-1]-initialExperience+1;
                initialExperience += 2*experience[i-1]-initialExperience+1;
                initialEnergy -= energy[i-1];
            }
            else if(initialExperience > experience[i-1]){
                f = f+energy[i-1]-initialEnergy+1;
                initialEnergy = 1;
                initialExperience += experience[i-1];
            }
            else{
                f = f+experience[i-1]-initialExperience+1+energy[i-1]-initialEnergy+1;
                initialEnergy = 1;
                initialExperience += 2*experience[i-1]-initialExperience+1;
            }
        }
        return f;
    }
    //2385. 感染二叉树需要的总时间
    const int N = 1e5+10;
    vector<int> g[N];  //图
    int vis[N];  //标记访问数组

    void dfs(TreeNode* root){  //dfs建图
        if(!root) return;
        if(root->left){
            int a = root->val, b = root->left->val;
            g[a].push_back(b);
            g[b].push_back(a);
            dfs(root->left);
        }
        if(root->right){
            int a = root->val, b = root->right->val;
            g[a].push_back(b);
            g[b].push_back(a);
            dfs(root->right);
        }
    }

    int bfs(int start){
        memset(vis,0,sizeof vis);
        int step = -1;
        int que[N], front = -1,rear = -1, last = 0;
        que[++rear] = start;
        vis[start] = 1;
        while(front < rear){
            int out = que[++front];
            for(int x : g[out]){
                if(!vis[x]) 
                    que[++rear] = x;
                vis[x] = 1;
            }
            if(front == last){
                last = rear;
                step++;
            }
        }
        return step;
    }

    int amountOfTime(TreeNode* root, int start) {
        fill(g,g+N,vector<int>());  //初始化图
        dfs(root);
        return bfs(start);
    }
    //2389. 和有限的最长子序列
    void swap(int& a,int& b){
        int c = a;
        a = b;
        b = c;
    }
    int partition(int low,int high,vector<int>& nums){
        int pivot = low;
        int i = low;
        for(int j = low+1,j <= high;j++)
            if(arr[j] < arr[pivot]) 
                swap(arr[j],arr[++i]);
        swap(arr[i],arr[pivot]);
        return i;
    }
    void qsort(int low,int high,vector<int>& nums){
        if(low >= high) return;
        int pivot = partition(low,high,arr);
        qsort(low,pivot,arr);
        qsort(pivot+1,high,arr);
    }
    int binSearch(int up,vector<int>& nums){
        int left = 0, right = nums.szie()-1, mid;
        while(left <= right){
            mid = low+(high-low)/2;
            if(nums[mid] <= up) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.szie();
        qsort(0,n-1,nums);
        for(int i = 0;i < n;i++){   //求前缀和
            if(i == 0) continue;
            else nums[i] += nums[i-1];
        }
        for(int i = 0;i < n;i++)
            queries[i] = binSearch(queries[i],nums);
        return queries;
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
    // vector<int> nums{7,5,6,4};
    // cout << s.reversePairs(nums);
    // cout << s.minimumRecolors("WBWBBBW",2);
    // cout << s.secondsToRemoveOccurrences("11100");
    // cout << s.shiftingLetters();
    vector<int> a{1,1,1,1};
    vector<int> b{1,1,1,50};
    cout << s.minNumberOfHours(1,1,a,b);
    return 0;
}