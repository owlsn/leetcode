#include <string>

class Solution {
public:
  Solution();
  ~Solution();
  int strStr(std::string haystack, std::string needle);
  void getNext(std::string needle, std::vector<int>& next);
};