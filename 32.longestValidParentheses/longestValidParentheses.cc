// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

// 示例 1:
// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"

// 示例 2:
// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

//第一种方法使用栈，括号匹配，匹配的长度就为最长有效括号的长度
//但是可能两个有效字串中间会有不符合要求的串，这个时候就要重新开始计数
//判断是否是不符合要求的串的时候，需要在入栈的时候判断，如果是连续的入栈不能确定是不符合要求的串，
//只有当入栈的时候，而且是)括号才能判断是符合要求

//第二种是不使用栈存储，直接用left和right标识来记录左右括号的匹配
//从左至右，当left记录左括号，right记录右括号，当left=right时，记录左右括号长度，当right>left时，清空重新计数
//分别从左至右，从右至左都来一遍，结果就是最长的记录

#include "longestValidParentheses.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

int Solution::longestValidParentheses(std::string s){
  int len = s.length(), left = 0, right = 0, lmax = 0, rmax = 0;
  for(int i = 0; i < len; i ++){
    if(s[i] == '('){
      left ++;
    }
    if(s[i] == ')'){
      right ++;
    }
    if(left < right){
      left = 0;
      right = 0;
    }
    if(left == right){
      lmax = std::max(lmax, right + left);
    }
  }
  left = 0;
  right = 0;
  for(int i = len; i >= 0; i --){
    if(s[i] == '('){
      left ++;
    }
    if(s[i] == ')'){
      right ++;
    }
    if(left > right){
      left = 0;
      right = 0;
    }
    if(left == right){

      rmax = std::max(rmax, left + right);
    }
  }

  return std::max(lmax, rmax);
}