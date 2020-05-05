// 实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2

// 示例 2:
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1

// 说明:
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

// KMP算法
// 1.前缀和后缀
// 2.求next数组，即求每个位置i之前的子串的前缀和后缀的公共部分
// 3.根据next数组得到不匹配时的回退部分

#include "strStr.h"
#include <vector>
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

int Solution::strStr(std::string haystack, std::string needle){
  int len = needle.length();
  if(!len){
    return 0;
  }
  std::vector<int> next(len + 1);
  Solution::getNext(needle, next);
  // for(auto value : next){
  //   std::cout << value << " ";
  // }
  // std::cout << std::endl;
  int hLen = haystack.length();
  int i = 0, j = 0;
  while (i < len && j < hLen)
  {
    if(i == -1 || needle[i] == haystack[j]){
      ++ i;
      ++ j;
    }
    else{
      i = next[i];
    }
  }
  if(i == len){
    return j - i;
  }
  else{
    return -1;
  }
}

void Solution::getNext(std::string needle, std::vector<int>& next){
  int i = -1, j = 0;
  next[0] = -1;
  while(j < needle.length() - 1){
    if(i == -1 || needle[i] == needle[j]){
      ++ i;
      ++ j;
      if(needle[i] == needle[j]){
        next[j] = next[i];
      }
      else{
        next[j] = i;
      }
    }
    else{
      i = next[i];
    }
  }
}