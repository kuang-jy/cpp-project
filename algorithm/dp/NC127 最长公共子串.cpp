class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * longest common substring
     * @param str1 string�ַ��� the string
     * @param str2 string�ַ��� the string
     * @return string�ַ���
     */
    string LCS(string str1, string str2) {
        string ans = "";
        int n = str1.length(),m = str2.length();
        //dp���鶨�壺dp[i][j]��ʾstr1��i��β��str2��j��βʱ��������Ӵ�����
        int dp[n+1][m+1],max = 0,idx = 0;
        for(int i = 0;i <= n;i++) dp[i][0] = 0;
        for(int i = 0;i <= m;i++) dp[0][i] = 0;  //��ʼ��dp����
        
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 0;
                if(max < dp[i][j]){
                    max = dp[i][j];
                    idx = i-1;   //��¼������ִ��Ľ����±�s 
                }
            }
        }
        return str1.substr(idx-max+1,max);
    }
};
