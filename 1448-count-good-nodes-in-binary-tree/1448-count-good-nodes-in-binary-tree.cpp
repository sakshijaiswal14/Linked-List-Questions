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
    
    void func(TreeNode* node,int curr,int &cnt){
        if(node!=NULL){
            if(node->val>=curr){
                curr=node->val;
                // cout<<curr<<" "<<node->val<<endl;
                cnt++;
            } 
        }
        if(node->left) func(node->left,curr,cnt);
        if(node->right) func(node->right,curr,cnt);
        if(left==NULL && right==NULL) return;
    }
    
    int goodNodes(TreeNode* root) {
        int ans;
        int curr=root->val;
        int cnt=0;
        TreeNode* node=root;
        func(node,curr,cnt);
        return cnt;
    }
};