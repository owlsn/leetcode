// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

// 示例 1:
// 输入: 123
// 输出: 321

//  示例 2:
// 输入: -123
// 输出: -321

// 示例 3:
// 输入: 120
// 输出: 21

// 注意:
// 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

//循环除以10取余
// 判断溢出在最后一位的时候判断
#include "intreverse.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

int Solution::reverse(int x){
  int bit = 0, left = x;
  int res = 0;
  do{
    bit = left % 10;
    left /= 10;
    // std::cout << "left:" << left << std::endl;
    if(res > INT_MAX / 10 || (res == INT_MAX / 10 && bit > INT_MAX % 10)){
      return 0;
    }
    else if(res < INT_MIN / 10 || (res == INT_MIN / 10 && bit < INT_MIN % 10)){
      return 0;
    }
    res = res * 10 + bit;
    // std::cout << "res:" << res << std::endl;
  }
  while(left);
  return res;
}