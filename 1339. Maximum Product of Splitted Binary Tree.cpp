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
    int maxProduct(TreeNode* root) {
        long long sum = dfs(root);
        return mx(root, sum).first%1000000007;
    }
    long long dfs(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        return root->val + dfs(root->left) + dfs(root->right);
    }
    pair<long long, long long> mx(TreeNode* root, long long sum) {
        if(root==NULL) {
            return {0, 0};
        }
        auto l = mx(root->left, sum);
        auto r = mx(root->right, sum);
        auto sm = root->val + l.second + r.second;
        return {max(max((sum-sm)*sm, l.first), r.first), sm};
    }
};
