class Solution {
public:
    /**
     * 
     * @param m int���� 
     * @param n int���� 
     * @return int����
     */
    
    int uniquePaths(int m, int n) {
        //dp���鶨�壬dp[i][j]��ʾ��i��j���м��ֲ�ͬ·��
//         int dp[m][n];
        int dp1[n];
        //��ʼ��dp���飬ȫ���������Ƕ���һ��·��ȫ�������߶���һ��·��
//         for(int i = 0;i < m;i++) dp[i][0] = 1;
        for(int j = 0;j < n;j++) dp1[j] = 1;
        for(int i = 1;i < m;i++)
            for(int j = 1;j < n;j++)
//                 dp[i][j] = dp[i-1][j]+dp[i][j-1];  //��i��j��·�������Ǵ���������������Ӵ��ϱ�����������
                dp1[j] = dp1[j-1]+dp1[j];
        return dp1[n-1];
    }
};
