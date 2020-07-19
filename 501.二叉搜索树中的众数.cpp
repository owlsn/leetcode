/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (44.97%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 35.4K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    vector<int> findMode(TreeNode* root) {
      std::vector<int> res;
      TreeNode* pre = nullptr;
      int count = 0, curr_count = 0, max_count = 0;
      inorder(root, res, count, pre, curr_count, max_count);
      // std::cout << count << std::endl;
      res.resize(count);
      pre = nullptr;
      count = 0;
      curr_count = 0;
      inorder(root, res, count, pre, curr_count, max_count);
      return res;
    }

    void inorder(TreeNode* root, std::vector<int>& res, int& count, TreeNode* &pre, int& curr_count, int& max_count){
      if(root == nullptr){
        return;
      }
      inorder(root->left, res, count, pre, curr_count, max_count);
      if(pre != nullptr && root->val == pre->val){
        curr_count ++;
      }
      else{
        curr_count = 1;
      }
      if(curr_count > max_count){
        max_count = curr_count;
        count = 1;
      }
      else if(curr_count == max_count){
        if(res.size()){
          res[count] = root->val;
        }
        count ++;
      }
      pre = root;
      inorder(root->right, res, count, pre, curr_count, max_count);
    }
};
// @lc code=end

