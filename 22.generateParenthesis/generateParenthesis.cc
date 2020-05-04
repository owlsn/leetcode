// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// 对于n和n+1的情况，可以有以下的递推
// n+1:对n的每一种情况，每一个字符位置插入一个左右括号，然后去重
// 这个方法效率比较低，但是理解起来比较直观

#include "generateParenthesis.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

std::vector<std::string> Solution::generateParenthesis(int n){
  std::vector<std::string> ret;
  std::string str;
  Solution::parenthesis(n, n, str, ret);
  return ret;
}

void Solution::parenthesis(int a, int b, std::string& str, std::vector<std::string>& ret){
  // std::cout << "a:" << a << ",b:" << b << std::endl;
  if(a == 0 && b == 0){
    ret.push_back(str);
    return ;
  }
  if(a > 0){
    str.push_back('(');
    Solution::parenthesis(a - 1, b, str, ret);
    str.pop_back();
  }
  if(b > a){
    str.push_back(')');
    Solution::parenthesis(a, b - 1, str, ret);
    str.pop_back();
  }
}