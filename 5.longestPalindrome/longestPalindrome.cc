// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。

// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

//Manacher算法
//i表示回文子串的中心位置，len表示回文子串的半径，则回文子串左边界为i-len,右边界为i+len
//使用一个数组arr[i]记录每个点i的最大回文串的长度,而arr[i]=
//遍历字符串时，根据i的中心位置得到最大的回文串长度，右边界为i+len，左边界为i-len
//而在求解len的过程中，由对称性，可以由左边的点的值arr[j]求出len,

//另外对于奇数和偶数个字符的字符串，先将字符串处理后再进行遍历，插入特殊字符

#include "longestPalindrome.h"
#include <vector>

Solution::Solution() {}

Solution::~Solution() {}



// 动态规划法

// std::string Solution::longestPalindrome(std::string s){
//   if(s.length() < 2){
//     return s;
//   }
//   int len = s.length();
//   std::vector<std::vector<int> > dp (len, std::vector<int>(len) );
//   for(int i = 0; i < dp.size(); i ++){
//     dp[i][i] = 1;
//   }
//   int maxLen = 1, curLen = 0;
//   int start = 0;
//   for(int j = 1; j < len; j ++){
//     for(int i = 0; i < j; i++){
//       if(s[i] == s[j]){
//         if(j - i < 3){
//           dp[i][j] = 1;
//         }
//         else{
//           dp[i][j] = dp[i + 1][j - 1];
//         }
//       }

//       if(dp[i][j]){
//         curLen = j - i + 1;
//         if(curLen > maxLen){
//           maxLen = curLen;
//           start = i;
//         }
//       }
//     }
//   }
//   return s.substr(start, maxLen);
// }


// Manacher 算法
std::string Solution::longestPalindrome(std::string s){
  if(s.length() < 2){
    return s;
  }
  int len = s.length();
  std::string str = "#";
  for(int i = 0; i < len; i ++){
    str = str + s[i] + "#";
  }
  int strSize = 2 * len + 1;
  std::vector<int> p (strSize, 0);

  int start = 0;
  int maxLen = 1;

  int maxRight = 0;
  int center = 0;

  int mirror = 0;

  int left = 0, right = 0;

  for(int i = 0; i < strSize; i ++){
    if(i < maxRight){
      mirror = 2 * center - i;
      p[i] = std::min(p[mirror], maxRight - i);
    }

    // i扩散到maxRight后
    left = i - (1 + p[i]);
    right = i + (1 + p[i]);

    while(left >= 0 && right < strSize && str[left] == str[right]){
      p[i] ++ ;
      left --;
      right ++;
    }

    if(i + p[i] > maxRight){
      // 更新center和maxRight
      center = i;
      maxRight = i + p[i];
    }

    if(p[i] > maxLen){
      maxLen = p[i];
      start = (i - maxLen) / 2;
    }

  }
  return s.substr(start, maxLen);
}