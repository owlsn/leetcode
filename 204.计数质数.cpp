/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (34.03%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    61.8K
 * Total Submissions: 181.5K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
      if(n < 3){
        return 0;
      }
      vector<bool> nPrimes(n, false);
      int ans = n / 2;
      for(int i = 3; i * i < n; i += 2){
        if(nPrimes[i]){
          continue;
        }
        for(int j = i * i; j < n; j += 2 * i){
          if(!nPrimes[j]){
            nPrimes[j] = true;
            ans --;
          }
        }
      }
      return ans;
    }
};
// @lc code=end

