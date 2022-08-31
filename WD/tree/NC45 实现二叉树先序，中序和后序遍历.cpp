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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    //先序
    void preOrder(TreeNode *root,vector<int>& ans){
        if(root){
            ans.push_back(root->val);
            preOrder(root->left, ans);
            preOrder(root->right, ans);
        }
    }
    //中序
    void inOrder(TreeNode *root,vector<int>& ans){
        if(root){
            inOrder(root->left, ans);
            ans.push_back(root->val);
            inOrder(root->right, ans);
        }
    }
    //后序
    void postOrder(TreeNode *root,vector<int>& ans){
        if(root){
            postOrder(root->left, ans);
            postOrder(root->right, ans);
            ans.push_back(root->val);
        }
    }
    
    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> a;
        preOrder(root, a);
        ans.push_back(a);
        a.clear();
        inOrder(root, a);
        ans.push_back(a);
        a.clear();
        postOrder(root, a);
        ans.push_back(a);
        a.clear();
        return ans;
    }
};
