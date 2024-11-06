//基于递归实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void order(vector<int>& result,TreeNode* root,int depth){
        if(root==nullptr){
            return;
        }
        if(depth==result.size()){
            result.push_back(0);
        }
        result[depth]=root->val;
        order(result,root->left,depth+1);
        order(result,root->right,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        order(result,root,0);
        return result;
    }
};
