#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            char letter = tolower(s[i]);
            if (letter < 97 || letter > 122)
            {
                s.erase(i, 1);
                length = s.length();
                i = -1;
            }
            else if (letter != tolower(s[length - i - 1]))
                return false;
        }
        return true;
    }
};