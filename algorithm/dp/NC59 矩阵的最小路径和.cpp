class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        //dp数组定义：dp[i][j]表示从i到j的最小距离
        int n = matrix.size(),m = matrix[0].size(),dp[n][m];
        dp[0][0] = matrix[0][0];
        for(int i = 1;i < m;i++) dp[0][i] = dp[0][i-1] + matrix[0][i];  //初始化数组第一列
        for(int i = 1;i < n;i++) dp[i][0] = dp[i-1][0] + matrix[i][0];  //初始化数组第一行
        for(int i = 1;i < n;i++)
            for(int j = 1;j < m;j++)
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
        return dp[n-1][m-1];
    }
};
