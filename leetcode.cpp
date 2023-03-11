#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

const int N = 1e5+10;
//二叉树结点定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
        for(int j = low+1;j <= high;j++)
            if(nums[j] < nums[pivot]) 
                swap(nums[j],nums[++i]);
        swap(nums[i],nums[pivot]);
        return i;
    }
    void qsort(int low,int high,vector<int>& nums){
        if(low >= high) return;
        int pivot = partition(low,high,nums);
        qsort(low,pivot,nums);
        qsort(pivot+1,high,nums);
    }
    int binSearch(int up,vector<int>& nums){
        int left = 0, right = nums.size()-1, mid;
        while(left <= right){
            mid = left+(right-left)/2;
            if(nums[mid] <= up) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        qsort(0,n-1,nums);
        for(int i = 0;i < n;i++){   //求前缀和
            if(i == 0) continue;
            else nums[i] += nums[i-1];
        }
        for(int i = 0;i < n;i++)
            queries[i] = binSearch(queries[i],nums);
        return queries;
    }
    //1590. 使数组和能被 P 整除
    //  设全部元素求和为S，那么就要找到一个∑(l <= i <= r)ai，使得(S-∑ai)%p = 0， 并且要求∑的长度最小
    //      即：S与∑ai同余，∑ai≡S%p, ∑ai = Sr-Sl-1，故：Sr-Sl-1≡S(mod p)  ==> Sl-1≡Sr-S(mod p)
    //       Sl-1≡Sr-S(mod p)  ==>  Sl-1 % p = ((Sr-S)%p+p)%p   ==>   Sl-1%p = ((Sr%p-S%p)+p)%p
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size(), ans = n, s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i)   //前缀和
            s[i + 1] = (s[i] + nums[i]) % p;
        int x = s[n];
        if (x == 0) return 0; // 移除空子数组（这行可以不要）

        unordered_map<int, int> last;
        for (int i = 0; i <= n; ++i) {
            last[s[i]] = i;
            auto it = last.find((s[i] - x + p) % p);
            if (it != last.end())
                ans = min(ans, i - it->second);
        }
        return ans < n ? ans : -1;
    }
    //1592. 重新排列单词间的空格
    string reorderSpaces(string text) {
        int cnt = 0, n = 0, pre = 0;
        for(int i = 0;i < text.length();i++){
            if(i == 0){
                if(text[i] == ' '){
                    cnt++;
                    pre = 1;
                }
                else n++;
            }
            else{
                if(pre == 1 && text[i] != ' '){
                    n++;
                    pre = 0;
                }
                else if(pre == 1 && text[i] == ' ') cnt++;
                else if(pre == 0 && text[i] == ' ') {
                    cnt++;
                    pre = 1;
                }
            }
        }
        int w = 0;
        if(n-1 > 0)
            w = cnt/(n-1);
        int r = cnt-w*(n-1);
        int x = 0;
        string res = "";
        // cout << w << " " << r;
        for(int i = 0;i < text.length();i++){
            if(text[i] != ' '){
                while(text[i] != ' ' && i < text.length()){
                    res+=text[i++];
                }
                for(int j = 0;j < w && x < n-1;j++)
                    res += ' ';
                x++;
            }
        }
        for(int i = 0;i < r;i++)
            res += ' ';
        return res;
    }
    //1594. 矩阵的最大非负积
    long long ans = -1;
    void dfs(int i,int j,long long res,vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == 0){   //对grid=0剪枝
            ans = ans > 0 ? ans : 0;
            return;
        }
        if(i == grid.size()-1 && j == grid[0].size()-1){
            res *= grid[i][j];
            ans = max(ans,res);
            return;
        }
        dfs(i+1,j,res*grid[i][j],grid);
        dfs(i,j+1,res*grid[i][j],grid);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        dfs(0,0,1,grid);
        return ans % (int)(1e9+7);
    }
    //1608. 特殊数组的特征值
    int check(vector<int>& nums,int num){   //二分找到大于等于num的个数
        int left = 0,right = nums.size(),mid;
        while(left <= right){
            mid = left+(right-left)/2;
            if(nums[mid] < num) left = mid+1; 
            else right = mid-1;
        }
        return nums.size()-right-1;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i <= nums.back();i++)
            if(check(nums,i) == i) return i;
        return -1;
    }
    //1609. 奇偶树
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return 1;
        TreeNode* que[100010];
        TreeNode* pre = NULL;
        int front = -1,rear = -1,last = 0,flag = 0;
        que[++rear] = root;
        while(front < rear){
            TreeNode* out = que[++front];
            if(out->left) que[++rear] = out->left;
            if(out->right) que[++rear] = out->right;
            if(!pre) pre = out;
            else{
                if(!flag)
                    if(out->val % 2 == 0 || pre->val >= out->val) return 0;
                else
                    if(out->val % 2 != 0 || pre->val <= out->val) return 0;
                pre = out;
            }
            if(front == last){
                last = rear;
                flag = !flag;
                pre = NULL;
            }
        }
        return 1;
    }
    //1624. 两个相同字符之间的最长子字符串
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> a(310,-1);
        int ans = -1;
        for(int i = 0;i < s.length();i++){
            if(a[s[i]-'a'] == -1) a[s[i]-'a'] = i;  //记录第一次出现的下标
            else ans = max(ans,i-a[s[i]-'a']-1);
        }
        return ans;
    }
    //1626. 无矛盾的最佳球队
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> order(n);
        for (int i = 0; i < n; ++i)   //创建索引数组
            order[i] = i;
        sort(order.begin(), order.end(), [&](int i, int j){   //给索引数组排序，按照年龄升序，若相同就按照分数降序
            return ages[i] < ages[j] || (ages[i] == ages[j] && scores[i] < scores[j]);
        });
        vector<int> dp(n);   //dp[i]表示第i个球员为止的最大分数
        int ans = 0;
        for(int i = 0;i < n;i++){
            int idx = order[i];  //选中排i位置的人
            dp[i] = scores[idx];  //初始化dp[i]
            for(int j = 0;j < i;j++){   //遍历年龄比i小的人
                int idx2 = order[j];
                if(scores[idx2] <= scores[idx])  //如果两人不冲突
                    dp[i] = max(dp[i],dp[j]+scores[idx]);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    //面试题 16.11. 跳水板
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(!k) return vector<int>();
        if(shorter == longer) return vector<int>(1,shorter*k);
        vector<int> ans;
        for(int i = 0;i < k+1;i++)
            ans.push_back(longer*i + shorter*(k-i));
        return ans;
    }
    //面试题 17.05.  字母与数字
    /*
    输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]

    输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
    */
    //  将字母视为-1，数字视为+1，对输入数组求前缀和，要找到字母数字个数相同的最长子数组，就是要找到前缀和为0的最长子数组
    //  即s[high]-s[low] = 0，即s[high]=s[low]，则需要记录前缀和第一次出现的位置，使用map记录
    vector<string> findLongestSubarray(vector<string>& array) {
        int low = 0, high = 0, n = array.size();
        vector<int> sum(n+1,0);   //前缀和数组
        for(int i = 1;i <= n;i++)
            if(array[i-1][0] >= '0' && array[i-1][0] <= '9')  //是数字+1
                sum[i] = sum[i-1] + 1;
            else sum[i] = sum[i-1] + -1;   //是字母-1
        unordered_map<int,int> mp;  //sum[i]->i 记录前缀和的第一次出现位置
        unordered_map<int,int>::iterator it;  //map的迭代器
        for(int i = 0;i <= n;i++){
            it = mp.find(sum[i]);
            if(it == mp.end()) mp[sum[i]] = i;  //记录第一次碰到
            else if(i-it->second > high-low){   //不是第一次碰到，更新答案
                low = it->second;
                high = i;
            }
        }
        return {array.begin()+low,array.begin()+high};
    }
    //5. 最长回文子串
    string longestPalindrome(string s) {
        int n = s.length(), start = 0, maxl = 1;
        if(n <= 1) return s;
        vector<vector<int>> dp(n,vector<int>(n));  //dp数组定义：dp[i][j]表示S字符串从Si到Sj是否回文
        for(int i = 0;i < n;i++) dp[i][i] = 1;  //长度为1的都是回文
        for(int len = 2;len <= n;len++){   //枚举子串长度
            for(int i = 0;i <= n-len;i++){  //枚举起点
                int j = i+len-1;  //终点
                if(s[i] == s[j])
                    dp[i][j] = i+1 <= j-1 ? dp[i+1][j-1] : 1;
                if(dp[i][j] && maxl < len){
                    start = i;
                    maxl = len;
                }
            }
        }
        return s.substr(start,maxl);
    }
    //11. 盛最多水的容器
    int maxArea(vector<int>& height) {
        int low = 0,high = height.size()-1;
        int res = (high-low)*min(height[high],height[low]);
        while(low < high){
            if(height[low] <= height[high]) low++;
            else high--;
            res = max(res,(high-low)*min(height[high],height[low]));
        }
        return res;
    }
    //15. 三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return vector<vector<int>>();
        sort(nums.begin(),nums.end()); //排序
        vector<vector<int>> res;
        for(int i = 0;i < n;i++){  //i作为第一指针
            if(nums[i] > 0) return res;   //若起点元素大于0 那么之后的元素全部大于0 直接返回收集到的答案
            //去重，若起点值与上一个元素值相同，那会得到重复解
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;  //第二指针，第三指针
            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];
                if(!sum) {
                    res.push_back({nums[i],nums[l],nums[r]});
                    //去重
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(sum < 0) l++;
                else r--;
            }
        }
        return res; 
    }
    //17. 电话号码的字母组合
    const string grid[10]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string& digits,int i,int n,vector<string>& res,string& str){
        if(i > n){
            res.push_back(str);
            return;
        }
        int x = digits[i-1]-'0';
        for(int j = 0;j < grid[x].length();j++){
            str.push_back(grid[x][j]);
            dfs(digits,i+1,n,res,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str;
        if(!digits.length()) return res;
        dfs(digits,1,digits.length(),res,str);
        return res;
    }
    //19. 删除链表的倒数第 N 个结点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *fast = head, *slow = head, *pre = dummy;
        while(n--){
            if(!fast) return head;
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = slow->next;
        delete slow;
        return dummy->next;
    }
    //22. 括号生成
    void dfs(int l,int r,vector<string>& res,string& str,int n){
        if(l+r == 2*n){
            res.push_back(str);
            return;
        }
        if(l < n){  //还可以放左括号
            str.push_back('(');
            dfs(l+1,r,res,str,n);
            str.pop_back();
        }
        if(l > r){  //还可以放右括号
            str.push_back(')');
            dfs(l,r+1,res,str,n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        dfs(0,0,res,str,n);
        return res;
    }
    //23. 合并K个升序链表
    ListNode* merge2(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(!l1) l1 = l2;
        p->next = l1;
        return dummy->next;
    }
    ListNode* msort(vector<ListNode*>& lists, int low, int high){
        if(low > high) return NULL;
        if(low == high) return lists[low];
        int mid = low+(high-low)/2;
        ListNode* ll = msort(lists,low,mid);
        ListNode* rr = msort(lists,mid+1,high);
        return merge2(ll,rr);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return msort(lists,0,lists.size()-1);
    }
    //31. 下一个排列
    /*  
        1``从后向前找到第一对nums[i] nums[j]，满足i<j，nums[i]<nums[j]
            此时nums[j]~nums[end]一定是降序
        2``再从后向前 遍历nums[end]~nums[j] 找到一个k，满足nums[i] < nums[k]
        3``swap(nums[i],nums[k])
        4``此时nums[j]~nums[end]依然为降序
            reverse(nums[j],nums[end])
        若在第一步找不到一对递增元素，说明原序列是最大组合，直接reverse即可
    */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        int i,j;
        for(j = n,i = n-1;i >= 0;j--,i--){
            if(nums[i] < nums[j]) break;
        }
        if(i < 0) reverse(nums.begin(),nums.end());
        else{
            int k;
            for(k = n;k >= j;k--)
                if(nums[k] > nums[i])
                    break;
            swap(nums[i],nums[k]);
            reverse(nums.begin()+j,nums.end());
        }
    }
    //32. 最长有效括号
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n,0);
        /*
            dp[i]定义为：以 s[i] 结尾的最长有效括号子串的长度
            遍历s：若 s[i] = ( 那么dp[i] = 0，因为有效字串不可能以(结尾
                    若 s[i] = ) 且 s[i-1] = ( ，那么 dp[i] = dp[i-2]+2
                                且 s[i-1] = ) ，那么需要判断
        */
        for(int i = 1;i < n;i++){
            if(s[i]==')'){
                if(s[i-1] == '(') dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
                else if(s[i-1] == ')')
            }
        }
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
    // vector<int> a{1,1,1,1};
    // vector<int> b{1,1,1,50};
    // cout << s.minNumberOfHours(1,1,a,b);
    // cout << s.reorderSpaces(" practice   makes   perfect");
    // vector<int> a{0,0};
    // cout << s.specialArray(a);
    // vector<string> a{"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    // s.findLongestSubarray(a);
    // cout << s.longestPalindrome("cbbd");
    // vector<int> a{2,3,4,5,18,17,6};
    // cout << s.maxArea(a);
    // s.letterCombinations("23");
    return 0;
}