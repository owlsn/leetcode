// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"

// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""

// 解释: 输入不存在公共前缀。
// 说明:
// 所有输入只包含小写字母 a-z 。


// 将strs排序，比较第一个和最后一个的公共子序列

#include "longestCommonPrefix.h"

Solution::Solution() {}

Solution::~Solution() {}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs){
  if(strs.size() == 0){
    return "";
  }
  std::sort(strs.begin(), strs.end());
  int len = strs.size();
  for(int i = 0; i < std::min(strs[0].length(), strs[len - 1].length()); i ++){
    if(strs[0][i] != strs[len - 1][i]){
      return strs[0].substr(0, i);
    }
  }
  return strs[0].length() > strs[len - 1].length() ?strs[len - 1]: strs[0];
}


