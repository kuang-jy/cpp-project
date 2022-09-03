class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        string ans = "";
        int n = str1.length(),m = str2.length();
        //dp数组定义：dp[i][j]表示str1以i结尾，str2以j结尾时的最长公共子串长度
        int dp[n+1][m+1],max = 0,idx = 0;
        for(int i = 0;i <= n;i++) dp[i][0] = 0;
        for(int i = 0;i <= m;i++) dp[0][i] = 0;  //初始化dp数组
        
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 0;
                if(max < dp[i][j]){
                    max = dp[i][j];
                    idx = i-1;   //记录最长公共字串的结束下标s 
                }
            }
        }
        return str1.substr(idx-max+1,max);
    }
};
