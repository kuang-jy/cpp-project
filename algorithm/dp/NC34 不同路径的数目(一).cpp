class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    
    int uniquePaths(int m, int n) {
        //dp数组定义，dp[i][j]表示从i到j共有几种不同路径
//         int dp[m][n];
        int dp1[n];
        //初始化dp数组，全部往下走那都有一条路，全部往右走都有一条路径
//         for(int i = 0;i < m;i++) dp[i][0] = 1;
        for(int j = 0;j < n;j++) dp1[j] = 1;
        for(int i = 1;i < m;i++)
            for(int j = 1;j < n;j++)
//                 dp[i][j] = dp[i-1][j]+dp[i][j-1];  //到i，j的路径数量是从左边走来的数量加从上边走来的数量
                dp1[j] = dp1[j-1]+dp1[j];
        return dp1[n-1];
    }
};
