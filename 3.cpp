#include <string>
#include <unordered_set>

using namespace std;
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() < 2)
    {
      return s.size();
    }
    int longestSubstring = 0;
    int currentSubstring = 0;
    unordered_set<char> set;

    int left = 0; // Keep track of the left boundary of the substring.

    for (int i = 0; i < s.size(); i++)
    {
      while (set.count(s[i])) // We'll only go through here if we find a repeated character, set.count() is pretty much an is_exists() function
      {
        set.erase(s[left]);
        left++;
      }
      set.insert(s[i]);
      longestSubstring = max(longestSubstring, (int)set.size());
    }
    return longestSubstring;
  }
};