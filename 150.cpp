#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> numbers;
    for (const string &str : tokens)
    {
      if (str.size() > 1 || isdigit(str[0]))
      {
        numbers.push(stoi(str));
        continue;
      }
      else
      {
        int number2 = numbers.top();
        numbers.pop();
        int number1 = numbers.top();
        numbers.pop();

        int temp;
        if (str == "+")
        {
          temp = number1 + number2;
        }
        else if (str == "-")
        {
          temp = number1 - number2;
        }
        else if (str == "*")
        {
          temp = number1 * number2;
        }
        else if (str == "/")
        {
          temp = number1 / number2;
        }
        numbers.push(temp);
      }
    }
    return numbers.top();
  }
};