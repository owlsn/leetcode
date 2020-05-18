// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
// 说明：

// num1 和 num2 的长度小于110。
// num1 和 num2 只包含数字 0-9。
// num1 和 num2 均不以零开头，除非是数字 0 本身。
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
#include "multiply.h"
#include <vector>

Solution::Solution() {}

Solution::~Solution() {}

std::string Solution::multiply(std::string num1, std::string num2){
  std::string ret;
  if(!num1.length() || !num2.length() || num1 == "0" || num2 == "0"){
    return "0";
  }
  std::vector<int> ans(num1.length() + num2.length() + 1);
  for(int i = 0; i < num1.length() ; ++ i){
    for(int j = 0; j < num2.length(); ++ j){
      ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
    }
  }

  for(int i = ans.size() - 1; i > 0; -- i){
    if(ans[i] >= 10){
      ans[i - 1] += ans[i] / 10;
      ans[i] %= 10;
    }
  }

  bool zero = true;
  for(int i = 0; i < ans.size() - 1; ++ i){
    if(zero && ans[i] == 0){
      continue;
    }
    zero = false;
    ret.push_back(ans[i] + '0');
  }
  return ret;
}