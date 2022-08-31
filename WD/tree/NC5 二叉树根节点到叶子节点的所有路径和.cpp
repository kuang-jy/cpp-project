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
     * @param root TreeNodeÀà 
     * @return intÕûÐÍ
     */
    int dfs(TreeNode* root,int sum){
        if(!root->left && !root->right) return sum;
        int l=0,r=0;
        if(root->left) l = dfs(root->left,sum*10+root->left->val);
        if(root->right) r = dfs(root->right,sum*10+root->right->val);
        return l+r;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        return dfs(root,root->val);
    }
};
