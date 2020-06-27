/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.05%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    41.4K
 * Total Submissions: 64.5K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
      string temp;
      vector<string> ans;
      dfs(root, temp, ans);
      return ans;
    }

    void dfs(TreeNode* root, string temp, vector<string>& ans){
      if(root != nullptr){
        if(root->left == nullptr && root->right == nullptr){
          temp += to_string(root->val);
          ans.push_back(temp);
        }
        else{
          temp += to_string(root->val) + "->";
          dfs(root->left, temp, ans);
          dfs(root->right, temp, ans);
        }
      }
    }
};
// @lc code=end

