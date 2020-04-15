// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
// 请你实现这个将字符串进行指定行数变换的函数：
// string convert(string s, int numRows);

//计算机按行输出
//那么就要找每行字符的规律
//第0行字符，索引为k * (numRows * 2 - 2);
//第numRows行的字符，索引为 k * (numRows * 2 - 2) + numRows - 1;
//中间行的字符，索引有两个，为 k * (numRows * 2 - 2) + i和  k * (numRows * 2 - 2) + (numRows - 1) * 2 - i即(k + 1) * (numRows * 2 - 2) - i
//则循环按行，将对应的位置的字符存储在新的字符中
//另外可将字符分为v字形的分组，即每numRows *2 - 2 为一组
#include "zconvert.h"

Solution::Solution() {}

Solution::~Solution() {}

std::string Solution::convert(std::string s, int numRows){
  if(numRows <= 1){
    return s;
  }
  std::string str;
  int k = 2 * numRows - 2;
  for(int i = 0; i < numRows; i ++){
    for(int j = 0; j + i < s.length(); j += k){
      str += s[i + j];
      if(i != 0 && i != numRows - 1 && j + k - i < s.length()){
        str += s[j + k - i];
      }
    }
  }
  return str;
}