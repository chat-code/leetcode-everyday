#include <string>
class Solution
{
public:
    int balancedStringSplit(::std::string s)
    {
        auto balance = 0;
        auto ans = 0;
        for (const auto i : s)
        {
            if (i == 'R')
                ++balance;
            else
                --balance;
            if (balance == 0)
                ++ans;
        }
        return ans;
    }
};