#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int i = 0;
    int j = height.size() - 1;
    int maxLeft = height[i];
    int maxRight = height[j];
    int rainTrapped = 0;
    while (i < j)
    {
      if (maxLeft <= maxRight)
      {
        i++;
        maxLeft = max(maxLeft, height[i]);
        rainTrapped += maxLeft - height[i];
      }
      else
      {
        j--;
        maxRight = max(maxRight, height[j]);
        rainTrapped += maxRight - height[j];
      }
    }
    return rainTrapped;
  }
};