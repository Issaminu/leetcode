#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefix = 1, postfix = 1;
        for (int i = 0; i < n; i++)
        {
            result[i] = result[i] * prefix;
            prefix = prefix * nums[i];
            result[n - i - 1] = result[n - i - 1] * postfix;
            postfix = postfix * nums[n - i - 1];
        }
        return result;
    }
};