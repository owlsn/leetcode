/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (54.12%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 18.4K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
      int max = INT_MIN;
      for(int num : nums){
        if(num > max){
          max = num;
        }
      }
      vector<int> ranknum(max + 1, -1);
      for(int i = 0; i < nums.size(); i ++){
        // std::cout << nums[i] << " " << i <<  std::endl;
        ranknum[nums[i]] = i;
      }
      int rank = 1;
      vector<string> ret(nums.size());
      for(int i = max; i >= 0; i --){
        if(ranknum[i] >= 0){
          // std::cout << ranknum[i] << std::endl;
          if(rank == 1){
            ret[ranknum[i]] = "Gold Medal";
          }
          else if(rank == 2){
            ret[ranknum[i]] = "Silver Medal";
          }
          else if(rank == 3){
            ret[ranknum[i]] = "Bronze Medal";
          }
          else{
            ret[ranknum[i]] = std::to_string(rank);
          }
          rank ++;
        }
      }
      return ret;
    }
};
// @lc code=end

