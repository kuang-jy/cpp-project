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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param pRoot TreeNode�� 
     * @return TreeNode��
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
