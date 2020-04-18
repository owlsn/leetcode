// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

// 说明:
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

// 示例 1:
// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。

// 示例 2:
// 输入:
// s = "aa"
// p = "a*"
// 输出: true
// 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

// 示例 3:
// 输入:
// s = "ab"
// p = ".*"
// 输出: true
// 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

// 示例 4:
// 输入:
// s = "aab"
// p = "c*a*b"
// 输出: true
// 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

// 示例 5:
// 输入:
// s = "mississippi"
// p = "mis*is*p*."
// 输出: false

// 动态规划

#include "isMatch.h"
#include <vector>
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

bool Solution::isMatch(std::string s, std::string p){
  if(!p.length()){
    return !s.length();
  }
  std::vector<std::vector<int> > index(s.length() + 1, std::vector<int>(p.length() + 1, 0));
  std::vector<std::vector<int> > memo(s.length() + 1, std::vector<int>(p.length() + 1, 0));

  return Solution::dp(s, p, 0, 0, index, memo);
}

bool Solution::dp(const std::string s, const std::string p, int i, int j, std::vector<std::vector<int> >& index, std::vector<std::vector<int> >& memo){
  if(index[i][j]){
    return memo[i][j];
  }
  if(j == p.length()){
    return i == s.length();
  }
  // std::cout << "s:" << s << ",p:" << p << std::endl; 
  bool first = i < s.length() && (s[i] == p[j] || p[j] == '.');
  bool ret = false;
  if(j + 1 < p.length() && p[j + 1] == '*'){
    //dp(s, p, i, j + 2, index, memo)表示匹配0个
    //(first && dp(s, p, i + 1, j, index, memo))表示匹配1次，多次是多个1次
    ret =  dp(s, p, i, j + 2, index, memo) || (first && dp(s, p, i + 1, j, index, memo));
  }
  else{
    ret = first && dp(s, p, i + 1, j + 1, index, memo);
  }
  memo[i][j] = ret;
  index[i][j] = 1;
  return ret;
}







