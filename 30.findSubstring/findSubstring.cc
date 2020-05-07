//给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
//注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

//示例 1：
//输入：
//s = "barfoothefoobarman",
//words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。

//示例 2：
//输入：
//s = "wordgoodgoodgoodbestword",
//words = ["word","good","best","word"]
//输出：[]

// "wordgoodgoodgoodbestword"
// ["word","good","best","good"]

//根据words数组中的字符串的长度，分为[0,,,word.length]组
//每一组都按照word.length进行移动，
//使用两个hashmap来判断子字符串中是否是符合要求的字串，先将words数组中的字符串都存在wordsmap中，有多个的值记录为个数
//existmap记录比较过程中的子字符，然后比较两个map中对应的key的数量，如果小于等于，则说明符合要求，如果不存在key或者existmap中的值大雨wordsmap，
//则说明该字串已经不符合要求的，就移动窗口从下一个开始查找
#include "findSubstring.h"
#include <unordered_map>
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

std::vector<int> Solution::findSubstring(std::string s, std::vector<std::string>& words){
  std::vector<int> ret;
  if(!words.size()){
    return ret;
  }
  std::unordered_map<std::string, int> exist, hashMap;
  for(auto& value : words){
    hashMap[value] ++;
  }
  std::string str;
  int left, right, cnt = 0;
  int len = words[0].length();
  for(int i = 0; i < len; i ++){
    left = i, right = i, cnt = 0;
    exist.clear();
    while(left + words.size() * len <= s.length()){
      while(cnt < words.size()){
        str = s.substr(right, len);
        if(hashMap.find(str) == hashMap.end() || exist[str] >= hashMap[str]){
          break;
        }
        exist[str] ++;
        right += len;
        cnt ++ ;
      }

      if(exist == hashMap){
        ret.push_back(left);
      }

      if(exist.find(str) != exist.end()){
        exist[s.substr(left, len)] --;
        cnt --;
        left += len;
      }
      else{
        right += len;
        left = right;
        cnt = 0;
        exist.clear();
      }
    }
  }
  return ret;
}