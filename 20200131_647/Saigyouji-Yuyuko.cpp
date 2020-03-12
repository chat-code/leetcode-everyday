#include <string>
class Solution
{
public:
    int countSubstrings(::std::string s)
    {
        auto sum = s.size();
        for (auto i = 0; i != s.size(); ++i)
        {
            for (auto j = 1; j + i != s.size() && i - j >= 0 && s[i + j] == s[i - j]; ++j)
                ++sum;
            for (auto j = 1; j + i != s.size() && i - j + 1 >= 0 && s[i + j] == s[i - j + 1]; ++j)
                ++sum;
        }
        return sum;
    }
};