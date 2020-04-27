// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//2->abc,3->def,...,7->pqrs,8->tuv,9->wxyz
// 示例:
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

// 递归表示

#include "letterCombinations.h"

Solution::Solution() {}

Solution::~Solution() {}

std::vector<std::string> Solution::letterCombinations(std::string digits){
  std::vector<std::string> ret;
  std::vector<std::string> digitMap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  func(digits, 0, "", ret, digitMap);
  return ret;
}

void Solution::func(std::string& digits, int i, std::string str, std::vector<std::string>& ret,const std::vector<std::string>& digitMap){
  if(i == digits.length()){
    if(str.length() > 0){
      ret.push_back(str);
    }
  }
  else{
    std::string s = digitMap[digits[i] - '2'];
    for(int j = 0; j < s.length(); j ++){
      str.push_back(s[j]);
      func(digits, i + 1, str, ret, digitMap);
      str.pop_back();
    }
  }
}
