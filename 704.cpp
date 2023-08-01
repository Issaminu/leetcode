#include <vector>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    return binary_search(nums, target, 0, nums.size() - 1);
  }

  int binary_search(vector<int> &nums, int target, int start, int finish)
  {
    if (finish - start < 2)
    {
      if (nums[start] == target)
      {
        return start;
      }
      else if (nums[finish] == target)
      {
        return finish;
      }
      return -1;
    }
    int middle = (int)(finish + start) / 2;
    if (nums[middle] == target)
    {
      return middle;
    }
    else if (nums[middle] > target)
    {
      return binary_search(nums, target, start, middle);
    }
    else
    {
      return binary_search(nums, target, middle + 1, finish);
    }
  }
};