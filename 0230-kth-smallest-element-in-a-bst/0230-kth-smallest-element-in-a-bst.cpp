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
    void solve(TreeNode* root, int& k, int &smallest){
        if(!root)
            return;
        solve(root -> left, k, smallest);
        k--;
        if(k == 0)  smallest = root -> val;
        solve(root -> right, k, smallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int smallest = -1;
        solve(root, k, smallest);
        return smallest;
    }
};