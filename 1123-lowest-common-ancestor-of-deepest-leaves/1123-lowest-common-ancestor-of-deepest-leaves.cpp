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
    TreeNode* ans;
    int level = 0;
    int solve(TreeNode* root, int lvl){
        level = max(lvl, level);
        if(!root)
            return lvl;
        int left = solve(root -> left, lvl + 1);
        int right = solve(root -> right, lvl + 1);
        if(left == level && right == level)
            ans = root;
        return max(left, right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};