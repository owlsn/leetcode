/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 *
 * https://leetcode-cn.com/problems/heaters/description/
 *
 * algorithms
 * Easy (30.15%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 37.5K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 * 
 * 现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
 * 
 * 所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
 * 
 * 说明:
 * 
 * 
 * 给出的房屋和供暖器的数目是非负数且不会超过 25000。
 * 给出的房屋和供暖器的位置均是非负数且不会超过10^9。
 * 只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
 * 所有供暖器都遵循你的半径标准，加热的半径也一样。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3],[2]
 * 输出: 1
 * 解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,3,4],[1,4]
 * 输出: 1
 * 解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      sort(houses.begin(), houses.end());
      sort(heaters.begin(), heaters.end());
      int right = 0, res = 0;
      for(int house : houses){
        while(right + 1 < heaters.size() && house > heaters[right]){
          right ++;
        }
        if(right == 0){
          res = std::max(res, abs(heaters[right] - house));
        }
        else{
          res = std::max(res, std::min(abs(heaters[right - 1] - house), abs(heaters[right] - house)));
        }
      }
      return res;
    }
};
// @lc code=end

