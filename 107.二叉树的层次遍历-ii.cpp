/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (65.74%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    63.9K
 * Total Submissions: 97.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其自底向上的层次遍历为：
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int depth = maxDepth(root);
    vector<vector<int>> ans(depth, vector<int>{});
    bfs(root, 0, depth, ans);
    return ans;
  }
  void bfs(TreeNode* root, int depth, int n, vector<vector<int>>& ans) {
    if (root == nullptr) {
      return;
    }
    ans[n - depth - 1].push_back(root->val);
    bfs(root->left, depth + 1, n, ans);
    bfs(root->right, depth + 1, n, ans);
  }

  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    } else {
      return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
  }
};
// @lc code=end
