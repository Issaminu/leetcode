#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.find(complement) != map.end())
            {
                result.push_back(i);
                result.push_back(map[complement]);
                break;
            }
            else
            {
                map.insert({nums[i], i});
            }
        }
        return result;
    }
};
