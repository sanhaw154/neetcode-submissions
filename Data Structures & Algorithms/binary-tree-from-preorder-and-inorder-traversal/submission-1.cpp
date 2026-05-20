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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int start = 0;
        int end = preorder.size();
        int cur_root = 0;
        unordered_map<int,int> inorder_pos;
        for(int i = 0 ; i < inorder.size() ; i++ )
        {
            inorder_pos[inorder[i]] = i;
        }
        return buildRecu(preorder,inorder,inorder_pos,start,end,cur_root);
    }

    TreeNode* buildRecu(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> inorder_pos,int in_start,int in_end,int& cur_root)
    {   if(in_start == in_end) return nullptr;
        int root_val = preorder[cur_root++];
        int root_LDRpos = inorder_pos[root_val];
        TreeNode* root = new TreeNode(root_val,buildRecu(preorder,inorder,inorder_pos,in_start,root_LDRpos,cur_root),buildRecu(preorder,inorder,inorder_pos,root_LDRpos + 1,in_end,cur_root));
        return root;
    }
};
