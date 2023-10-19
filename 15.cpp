#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int length = nums.size();
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < length - 2; i++)
    {
      int j = i + 1;
      int k = length - 1;
      if (nums[i] > 0)
      {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }
      while (j < k)
      {
        int curr = nums[i] + nums[j] + nums[k];
        if (curr < 0)
        {
          j++;
        }
        else if (curr > 0)
        {
          k--;
        }
        else
        {
          result.push_back({nums[i], nums[j], nums[k]});
          while (j < k && nums[j] == nums[j + 1])
          {
            j++;
          }
          j++;
          while (j < k && nums[k] == nums[k - 1])
          {
            k--;
          }
          k--;
        }
      }
    }
    return result;
  }
};