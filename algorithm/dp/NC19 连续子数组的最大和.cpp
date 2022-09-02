class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 1) return array[0];
        int ans = -1000000;
        int dp[array.size()];
        for(int i = 0;i < array.size();i++) dp[i] = array[i];   //dp数组初始化为array本身的数据
        for(int i = 1;i < array.size();i++){
            //要么加进dp[i]，要么不加入dp[i]，将其重置为dp[i]，因为是连续子数组
            dp[i] = max(dp[i-1]+array[i],dp[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
