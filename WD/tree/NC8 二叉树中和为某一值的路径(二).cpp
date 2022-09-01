/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void dfs(TreeNode *root,int sum,int expectNumber,vector<vector<int>>& ans,vector<int> path){
        if(!root) return;
        path.push_back(root->val);
        sum += root->val;
        if(sum == expectNumber && !root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        dfs(root->left,sum,expectNumber,ans,path);
        dfs(root->right,sum,expectNumber,ans,path);
        sum-=root->val;   //»ØËÝ
        path.pop_back();  //»ØËÝ
    }
    
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, 0, expectNumber, ans, path);
        return ans;
    }
};
