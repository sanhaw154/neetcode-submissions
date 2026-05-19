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
        return buildRecu(preorder,inorder,start,end,cur_root);
    }

    TreeNode* buildRecu(vector<int>& preorder, vector<int>& inorder,int in_start,int in_end,int& cur_root)
    {   if(in_start == in_end) return nullptr;
        int root_val = preorder[cur_root++];
        int root_LDRpos;
        for(int i = in_start ; i < in_end ; i++)
        {
            if(inorder[i] == root_val)
            {
                root_LDRpos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(root_val,buildRecu(preorder,inorder,in_start,root_LDRpos,cur_root),buildRecu(preorder,inorder,root_LDRpos + 1,in_end,cur_root));
        return root;
    }
};
