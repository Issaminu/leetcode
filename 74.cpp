#include <vector>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int size = matrix[0].size();
    for (vector<int> &row : matrix)
    {
      if (row[size - 1] == target)
      {
        return true;
      }
      else if (row[size - 1] > target)
      {
        return binary_search(row, target, 0, size - 1);
      }
    }
    return false;
  }
  bool binary_search(vector<int> &nums, int target, int start, int finish)
  {
    if (finish - start < 2)
    {
      if (nums[start] == target)
      {
        return true;
      }
      else if (nums[finish] == target)
      {
        return true;
      }
      return false;
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