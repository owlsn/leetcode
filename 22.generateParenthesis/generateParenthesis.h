#include <vector>
#include <string>

class Solution {
public:
  Solution();
  ~Solution();
  std::vector<std::string> generateParenthesis(int n);
  void parenthesis(int a, int b, std::string& str, std::vector<std::string>& ret);
};