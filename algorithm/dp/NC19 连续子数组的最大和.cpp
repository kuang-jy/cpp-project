class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 1) return array[0];
        int ans = -1000000;
        int dp[array.size()];
        for(int i = 0;i < array.size();i++) dp[i] = array[i];   //dp�����ʼ��Ϊarray���������
        for(int i = 1;i < array.size();i++){
            //Ҫô�ӽ�dp[i]��Ҫô������dp[i]����������Ϊdp[i]����Ϊ������������
            dp[i] = max(dp[i-1]+array[i],dp[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
