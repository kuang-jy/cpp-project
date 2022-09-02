class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    
    string traceback(string x,int i,int j,vector<vector<int>> path){
        string ans = "";
        if(i == 0 || j == 0) return ans;
        if(path[i][j] == 1){
            ans += traceback(x,i-1, j-1, path);
            ans += x[i-1];
        }
        else if(path[i][j] == 2) ans += traceback(x,i, j-1, path);
        else ans += traceback(x,i-1, j, path);
        return ans;
    }
    
    string LCS(string s1, string s2) {
        if(s1.length() == 0 || s2.length() == 0) return "-1";
        //dp数组定义：dp[i][j]表示s1以i结尾，s2以j结尾的最长公共子序列长度
        int n = s1.length(),m = s2.length();
        int dp[n+1][m+1];
        vector<vector<int>> path(n + 1, vector<int>(m + 1, 0));  //path记录路径
        //dp数组初始化
        for(int i = 0;i <= n;i++) dp[i][0] = path[i][0] = 0;
        for(int i = 0;i <= m;i++) dp[0][i] = path[0][i] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    path[i][j] = 1;  //来自左上
                }
                else if (dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                    path[i][j] = 2;  //来自左边
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    path[i][j] = 3;  //来自上边
                }
            }
        }
        string ans = traceback(s1,n,m, path);
        return ans == "" ? "-1" : ans;
    }
};
