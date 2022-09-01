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
     * @param root TreeNode�� 
     * @param sum int���� 
     * @return bool������
     */
    
    void dfs(TreeNode* root,bool& ans,int cnt,int sum){
        if(!root || ans) return;   //�����������ҵ���һ��·����ֱ�ӷ��� 
        cnt += root->val;
        if(sum == cnt && !root->left && !root->right){
            ans = true;
            return;
        }
        dfs(root->left,ans,cnt,sum);
        dfs(root->right,ans,cnt,sum);
        cnt -= root->val;  //����
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool ans = false;
        dfs(root,ans,0,sum);
        return ans;
    }
};
