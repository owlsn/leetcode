#include <vector>
#include <string>

class Solution {
 private:
 public:
  Solution();
  ~Solution();
  std::vector<std::string> letterCombinations(std::string digits);
  void func(std::string& digits, int i, std::string str, std::vector<std::string>& ret, const std::vector<std::string>& digitMap);
};