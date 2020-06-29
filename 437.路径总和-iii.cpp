/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (55.15%)
 * Likes:    466
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 71.3K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
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
    int pathSum(TreeNode* root, int sum) {
      int pre = 0, count = 0;
      std::unordered_map<int, int> mp;
      mp[0] = 1;
      count = prePathSum(root, pre, sum, mp);
      return count;
    }

    int prePathSum(TreeNode* root, int pre, int sum, std::unordered_map<int, int> mp){
      int count = 0;
      if(root != nullptr){
        pre += root->val;
        if(mp.find(pre - sum) != mp.end()){
          count += mp[pre - sum];
        }
        mp[pre] ++;
        count += prePathSum(root->left, pre, sum, mp);
        count += prePathSum(root->right, pre, sum, mp);
      }
      return count;
    }
};
// @lc code=end

