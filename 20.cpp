#include <string>
#include <unordered_map>
#include <stack>

using namespace std;
class Solution
{
public:
  bool isValid(string s)
  {
    if (s.size() < 2)
    {
      return false;
    }
    unordered_map<char, char> map = {
        {'}', '{'},
        {']', '['},
        {')', '('},
    };
    stack<char> stack;
    for (char c : s)
    {
      if (map.find(c) != map.end())
      {
        if (stack.empty())
        {
          return false;
        }
        if (stack.top() != map[c])
        {
          return false;
        }
        stack.pop();
      }
      else
      {
        stack.push(c);
      }
    }
    return stack.empty();
  }
};