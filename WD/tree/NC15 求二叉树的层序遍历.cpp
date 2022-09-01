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
     * @param root TreeNode¿‡ 
     * @return int’˚–Õvector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> treeRow;
            int n = que.size();
            for(int i = 0;i < n;i++){
                TreeNode* temp = que.front();
                que.pop();
                treeRow.push_back(temp->val);
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            ans.push_back(treeRow);
        }
        return ans;
    }
};
