#include <string>
#include <algorithm>
class Solution
{
public:
    int lengthOfLongestSubstring(::std::string s)
    {
        int mmp[300];
        memset(mmp, -1, sizeof(mmp));
        auto begin = 0;
        auto maxx = 0;
        for (auto i = 0; i != s.size(); ++i)
        {
            begin = ::std::max(begin, mmp[s[i]] + 1);
            mmp[s[i]] = i;
            maxx = ::std::max(maxx, i - begin + 1);
        }
        return maxx;
    }
};