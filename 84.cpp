#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int result = 1, resultHeight = 1, temp = 0;
    for (int i = 0; i < heights.size(); i++)
    {
      if (heights[i] > result)
      {
        temp = heights[i];
        result = heights[i];
        resultHeight = heights[i];
      }
      else
      {
        result += resultHeight;
      }
    }
    return result;
  }
};