/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    
    void dfs(TreeNode* root,bool& ans,int cnt,int sum){
        if(!root || ans) return;   //若空树，或找到过一条路径，直接返回 
        cnt += root->val;
        if(sum == cnt && !root->left && !root->right){
            ans = true;
            return;
        }
        dfs(root->left,ans,cnt,sum);
        dfs(root->right,ans,cnt,sum);
        cnt -= root->val;  //回溯
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool ans = false;
        dfs(root,ans,0,sum);
        return ans;
    }
};
