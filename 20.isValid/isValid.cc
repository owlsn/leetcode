// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:
// 输入: "()"
// 输出: true

// 示例 2:
// 输入: "()[]{}"
// 输出: true

// 示例 3:
// 输入: "(]"
// 输出: false

// 示例 4:
// 输入: "([)]"
// 输出: false

// 示例 5:
// 输入: "{[]}"
// 输出: true

#include "isValid.h"
#include <stack>
#include <unordered_map>
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

bool Solution::isValid(std::string s){
  std::stack<char> st;
  std::unordered_map<char, char> m{
    {')', '('}, {']', '['}, {'}', '{'}
  };
  bool ret = true;
  for(int i = 0; i < s.length(); i ++){
    // std::cout << s[i] << std::endl;
    if(st.empty() || (s[i] == '{' || s[i] == '(' || s[i] == '[')){
      // std::cout << "push " << s[i] << std::endl;
      st.push(s[i]);
    }
    else if(!st.empty() && m.find(s[i]) != m.end() && st.top() == m[s[i]]){
      // std::cout << "pop " << st.top() << std::endl;
      st.pop();
    }
    else{
      // std::cout << "break" << std::endl;
      ret = false;
      break;
    }
  }
  if(!st.empty()){
    ret = false;
  }
  return ret;
}