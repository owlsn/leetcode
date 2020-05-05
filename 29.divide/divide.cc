//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//返回被除数 dividend 除以除数 divisor 得到的商。
//示例 1:
//输入: dividend = 10, divisor = 3
//输出: 3

//示例 2:
//输入: dividend = 7, divisor = -3
//输出: -2
//说明:
//被除数和除数均为 32 位有符号整数。
//除数不为 0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

//题目用java实现在边界条件判断的时候很容以溢出，就是在-(2^31)这里，
//如果不在边界条件的情况下，使用正常的移位相减代替除法
//被除数为边界条件的时候，改成移位相加

#include "divide.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

int Solution::divide(int dividend, int divisor){
  if(dividend == 0){
    return 0;
  }
  if(divisor == 1){
    return dividend;
  }
  if(divisor == -1){
    return dividend > INT_MIN ? - dividend: INT_MAX;
  }

  long a = dividend;
  long b = divisor;

  int sign = 1;
  if((a > 0 && b < 0) || (a < 0 && b > 0)){
    sign = -1;
  }
  a = a > 0 ? a: - a;
  b = b > 0? b: - b;
  long ret = div(a, b);
  // std::cout << "ret:" << ret << ",sign:" << sign << std::endl;
  return sign == 1? (ret > INT_MAX? INT_MAX: ret): - ret;
}

int Solution::div(long dividend, long divisor){
  if(dividend < divisor){
    return 0;
  }
  long count = 1, b = divisor;
  while(dividend >= (b + b)){
    b += b;
    count += count;
  }
  return count + div(dividend - b, divisor);
}