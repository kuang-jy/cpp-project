class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        //dp数组定义，dp[i]表示在第i天卖出可得的最大利益（对dp[i][j]进行了优化） 
        int dp[prices.size()],ans = 0;
        for(int i = 0;i <= prices.size();i++) dp[i] = 0;
        for(int i = 0;i < prices.size();i++)
            for(int j = prices.size()-1;j >= 0;j--){
                if(j > i) dp[j] = max(0,prices[j]-prices[i]);
                ans = max(dp[j],ans);
            }
        return ans;
    }
};
