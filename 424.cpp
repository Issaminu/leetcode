#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int result = 0;
    int largestElementInVector = 0;
    vector<int> vec(26);
    int i = 0, j = 0;
    while (j < s.size())
    {
      vec[s[j] - 'A']++;
      largestElementInVector = max(largestElementInVector, vec[s[j] - 'A']);
      if ((j - i + 1) - largestElementInVector > k)
      {
        vec[s[i] - 'A']--;
        i++;
      }
      result = max(result, j - i + 1);
      j++;
    }
    return result;
  }
};
