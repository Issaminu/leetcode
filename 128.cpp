#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string encodedStrs = "";
        for (int i = 0; i < strs.size(); i++)
        {
            encodedStrs.append(strs[i]);
            encodedStrs.push_back('¦');
        }
        return encodedStrs;
    }

    vector<string> decode(string &str)
    {
        vector<string> decodedStrs;
        string temp = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '¦')
            {
                temp.push_back(str[i]);
            }
            else
            {
                decodedStrs.push_back(temp);
                temp = "";
            }
        }
        return decodedStrs;
    }
};