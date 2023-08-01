#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int> &nums, int target)
{
  int maxLength = 0;
  vector<int> temp;
  temp.push_back(nums[0]);
  sort(nums.begin(), nums.end());
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] - temp.front() <= target)
    {
      temp.push_back(nums[i]);
    }
    else
    {
      int tempSize = temp.size();
      maxLength = max(maxLength, tempSize);
      temp.clear();
    }
  }
  return maxLength;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 2;
  int result = maxSubArray(nums, target);
  cout << result << endl;
  return 0;
}