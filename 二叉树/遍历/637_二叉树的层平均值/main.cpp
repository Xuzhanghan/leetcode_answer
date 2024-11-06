//使用迭代法
/*
1.如何理解迭代法？
* 首先，利用队列先进先出的特点存储根节点
* 可以做到，每一层的最后一个队列出队之后，队列中的剩余节点均为同一层的节点
*/
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
    vector<double> order(TreeNode* root){
        queue<TreeNode*> que;
        if(root!=nullptr){
            que.push(root);
        }
        vector<double> result;
        while(!que.empty()){
            long sum=0;
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* tmp=que.front();
                que.pop();
                sum=sum+tmp->val;
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
            double avg=sum*1.0/size;
            result.push_back(avg);
        }
        return result;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        result=order(root);
        return result;
    }
};
