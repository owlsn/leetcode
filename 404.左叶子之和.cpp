/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (54.75%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    27.7K
 * Total Submissions: 50.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
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
    int sumOfLeftLeaves(TreeNode* root) {
      int count = 0;
      count += sumOfLeft(root, false);
      return count;
    }

    int sumOfLeft(TreeNode* root, bool isLeft){
      int count = 0;
      if(root != nullptr){
        if(isLeft && root->left == nullptr && root->right == nullptr){
          count += root->val;
        }
        count += sumOfLeft(root->left, true);
        count += sumOfLeft(root->right, false);
      }
      return count;
    }
};
// @lc code=end

