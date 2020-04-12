// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

// 示例 1:

// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

//滑动窗口
//采用队列，字符依次入队，当不满足要求的时候，将左边的字符剔除，然后继续遍历，窗口逐渐向右滑动，直到遍历完成
//在遍历过程中不断记录窗口中的最大的元素的个数，最终的最大值即为所求
//在判断窗口start位置和end位置时要注意
#include "lengthOfLongestSubstring.h"
#include <map>

Solution::Solution() {}

Solution::~Solution() {}

int Solution::lengthOfLongestSubstring(std::string s){
  if(s.length() <= 1){
    return s.length();
  }
  int res = 0;
  int start = 0;
  std::map<char, int> exist;
  for(int i = 0; i < s.length(); i ++){
    if(exist.find(s[i]) != exist.end()){
      start = std::max(exist[s[i]], start);
    }
    res = std::max(i - start + 1, res);
    exist[s[i]] = i + 1;
  }
  return res;
}


