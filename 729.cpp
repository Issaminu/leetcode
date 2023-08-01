#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		int size = temperatures.size();
		stack<pair<int, int>> stack;
		vector<int> result(size);

		for (int i = 0; i < size; i++)
		{
			int currentDay = i;
			int currentTemp = temperatures[i];
			while (!stack.empty() && currentTemp > stack.top().second)
			{
				int prevDay = stack.top().first;
				stack.pop();
				result[prevDay] = currentDay - prevDay;
			}
			stack.push({currentDay, currentTemp});
		}
		return result;
	}
};