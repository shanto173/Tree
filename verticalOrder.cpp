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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> todo;
        map<int,map<int,multiset<int>>> nodes;

        todo.push({root,{0,0}});

        while(!todo.empty()){
            auto it = todo.front();
            todo.pop();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;

            nodes[vertical][level].insert(node->val);
            if(node->left){
                todo.push({node->left,{vertical-1,level+1}});
            }
            if(node->right){
                todo.push({node->right,{vertical+1,level+1}});
            }
        }

        vector<vector<int> > ans;

        for(auto p : nodes){
            vector<int> col;
            for(auto q:nodes.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    
};