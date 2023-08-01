#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int size = nums.size();
    if (size < 2 || nums[0] < nums[size - 1])
    {
      return nums[0];
    }
    int startingPosition = find_starting_position(nums, 0, size - 1);

    return binary_search(nums, target, startingPosition, size - 1);
  }
  int find_starting_position(vector<int> &nums, int left, int right)
  {
    if (left > right)
    {
      return -1;
    }
    int current = (left + right) / 2;
    if (current > 0 && nums[current] < nums[current - 1])
    {
      return nums[current];
    }
    int leftTry = find_starting_position(nums, left, current - 1);
    if (leftTry != -1)
    {
      return leftTry;
    }
    int rightTry = find_starting_position(nums, current + 1, right);
    return rightTry;
  }
  int binary_search(vector<int> &nums, int target, int start, int end)
  {
  }
};