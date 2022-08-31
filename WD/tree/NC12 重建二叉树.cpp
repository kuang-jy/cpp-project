/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* rebulid(vector<int> pre,vector<int> vin,int l1,int h1,int l2,int h2){
        if(l1 > h1 || l2 > h2) return NULL;  //空结点
        //在中序中找到根
        int k=l2;
        while(vin[k] != pre[l1]) k++;
        int lenL = k-l2;  //计算左子树结点数
        TreeNode *root = new TreeNode(pre[l1]);
        root->left = rebulid(pre, vin, l1+1, l1+lenL, l2, k-1);
        root->right = rebulid(pre, vin, l1+lenL+1, h1, k+1, h2);
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(!pre.size()) return NULL;  //空树
        return rebulid(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
};
