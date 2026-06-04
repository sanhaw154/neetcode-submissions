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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        unordered_map<int,int> mapping;
        for(int i = 0 ; i < len ; i++) //每次尋找root的位置需要遍歷整個inorder(O(n^2)) 但改成我直接用hash table記錄某個root在第幾個index就好（O(n)）
        {
            mapping.insert({inorder[i],i});
        }
        return build(preorder,inorder,mapping,0,0,len);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& mapping,int preL, int inoL, int len)
    {
        if( len <= 0 )return nullptr;
        int root = preorder[preL];
        TreeNode* newNode = new TreeNode(root);
        int inPos = mapping[root];
        
        int left_size = inPos - inoL;
        int right_size = len - left_size - 1;
        newNode->left = build(preorder,inorder, mapping,preL+1,inoL,left_size);
        newNode->right = build(preorder, inorder, mapping, preL+left_size+1,inPos+1,right_size);
        return newNode;
    }
};
