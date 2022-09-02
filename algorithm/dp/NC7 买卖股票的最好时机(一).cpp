class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param prices int����vector 
     * @return int����
     */
    int maxProfit(vector<int>& prices) {
        //dp���鶨�壬dp[i]��ʾ�ڵ�i�������ɵõ�������棨��dp[i][j]�������Ż��� 
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
