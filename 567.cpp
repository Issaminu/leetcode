#include <string>
#include <unordered_map>

using namespace std;
class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s2.size() < s1.size())
    {
      return false;
    }
    unordered_map<char, int> s1bucket;
    unordered_map<char, int> s2bucket;
    for (char c : s1)
    {
      s1bucket[c]++;
    }

    int leftBound = 0;
    for (int i = 0; i < s2.size(); i++)
    {
      s2bucket[s2[i]]++;
      if (s2bucket.size() == s1.size())
      {
        if (s2bucket == s1bucket)
        {
          return true;
        }
        s2bucket[s2[leftBound]]--;
        if (s2bucket[s2[leftBound]] == 0)
        {
          s2bucket.erase(s2[leftBound]);
        }
        leftBound++;
      }
    }
    return false;
  }
};