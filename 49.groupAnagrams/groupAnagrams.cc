// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

#include "groupAnagrams.h"
#include <unordered_map>
#include <iostream>

std::vector<std::vector<std::string> > Solution::groupAnagrams(std::vector<std::string>& strs){
  std::vector<std::vector<std::string> > res;
  std::unordered_map<std::string, int> str_map;
  std::string str;
  for(auto s : strs){
    str = s;
    sort(str.begin(), str.end());
    auto iter = str_map.find(str);
    if(iter == str_map.end()){
      str_map.insert({str, str_map.size()});
      res.push_back(std::vector<std::string>(1, s));
    }
    else{
      res[iter->second].push_back(s);
    }
  }
  return res;
}