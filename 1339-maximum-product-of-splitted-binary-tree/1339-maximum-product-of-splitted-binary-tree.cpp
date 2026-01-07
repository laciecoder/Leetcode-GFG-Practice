/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int mod = 1e9 + 7;
    long long getSum(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        return root->val + getSum(root->left) + getSum(root->right);
    }
    long long solve(TreeNode* root, long long& sum, long long& maxProduct) {
        if (!root)
            return 0;
        int val = root->val;
        if (!root->left && !root->right) {
            maxProduct = max({maxProduct, val * (sum - val)});
            return val;
        }
        int leftSum = solve(root->left, sum, maxProduct);
        int rightSum = solve(root->right, sum, maxProduct);

        maxProduct = max({maxProduct,
                          (rightSum) * (sum - rightSum),
                          (leftSum) * (sum  - leftSum)
                          });

        return val + leftSum + rightSum;
    }
    int maxProduct(TreeNode* root) {
        long long sum = getSum(root);
        long long maxProduct = 0;
        solve(root, sum, maxProduct);
        return maxProduct % mod;
    }
};