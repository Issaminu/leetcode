#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int size = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
      map[nums[i]]++;
    }
    vector<vector<int>> bucket(size + 1);
    vector<int> result;
    for (auto it = map.begin(); it != map.end(); it++)
    {
      bucket[it->second].push_back(it->first);
    }
    for (int i = size; i >= 0; i--)
    {
      if (!bucket[i].empty())
      {
        for (int j = 0; j < bucket[i].size(); j++)
        {
          result.push_back(bucket[i][j]);
          if (result.size() >= k)
            return result;
        }
      }
    }
    return result;
  }
};
