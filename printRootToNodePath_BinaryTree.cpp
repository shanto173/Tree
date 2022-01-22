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
    bool getPath(TreeNode* root,vector<int>& ans,int x){

        if(root == NULL){
            return false;
        }
        ans.push_back(root->val);

        if(root->val == x){
            return true;
        }

        if(getPath(root->left,ans,x) or getPath(root->right,ans,x)){
            return true;
        }
        ans.pop_back();
        return false;

    }
public:
    vector<int> solve(TreeNode* root,int x) {
        vector<int> res;

        if(root == NULL){
            return res;
        }

        getPath(root,res,x);
        return res;
    }
    
};