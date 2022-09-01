/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    
    TreeNode* reverse(TreeNode* root){
        if(!root) return root;
        TreeNode *l =  reverse(root->left);
        TreeNode *r = reverse(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
    
    TreeNode* Mirror(TreeNode* pRoot) {
        return reverse(pRoot);
    }
};
