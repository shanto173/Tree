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
    
    bool isLeaf(TreeNode* root){
        if(root->left == NULL and root->right == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void addLeftBoundary(TreeNode* root,vector<int>& res){

        TreeNode* node = root->left;

        while(node){
            if(!isLeaf(node)){
                res.push_back(node->val);
            }
            if(node->left){
                node = node->left;
            }else{
                node = node->right;
            }

        }
    }
    void addRightBoundary(TreeNode* root,vector<int>& res){

        TreeNode* node = root->right;
        vector<int> temp;
        while(node){
            if(!isLeaf(node)){
                res.push_back(node->val);
            }
            if(node->right){
                node = node->right;
            }else{
                node = node->left;
            }
        }
        for(int i=temp.size()-1;i >= 0;i--){
            res.push_back(temp[i]);
        }
    }
    void addLeafNode(TreeNode* root,vector<int>& res){


        if(isLeaf(root)){
            res.push_back(root->val);
            return;
        }
        if(root->left){
            addLeafNode(root->left);
        }
        if(root->right){
            addLeafNode(root->right);
        }
    }

public:
    
    vector<int> printBoundary(TreeNode* root) {
        
        vector<int>res;

        if(root == NULL){
            return res;
        }
        if(!isLeaf(root)){
            res.push_back(root);
        }
        addLeftBoundary(root,res);
        addLeafNode(root,res);
        addRightBoundary(root,res);
        return res;
    }
};