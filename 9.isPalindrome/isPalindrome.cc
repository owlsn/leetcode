// 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

// 示例 1:
// 输入: 121
// 输出: true

// 示例 2:
// 输入: -121
// 输出: false
// 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

// 示例 3:
// 输入: 10
// 输出: false
// 解释: 从右向左读, 为 01 。因此它不是一个回文数。

//数字逆转一半然后判断是否相等
//负号直接判断不相等
//

#include "isPalindrome.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

bool Solution::isPalindrome(int x){
  if(x < 0 || (x % 10 == 0 && x != 0)){
    return false;
  }
  int ans = 0;
  int left = x;
  int reverse = 0;
  do{
    ans = left % 10;
    left /= 10;
    reverse = reverse * 10 + ans;
  }
  while(left > reverse);

  return reverse / 10 == left || reverse == left ? true: false;
}