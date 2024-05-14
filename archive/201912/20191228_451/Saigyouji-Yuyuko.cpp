#include <string>
#include <cstring>
#include <algorithm>
class Solution
{
public:
    ::std::string frequencySort(::std::string s)
    {
        int mmp[128];
        memset(mmp, 0, sizeof(mmp));
        for (auto i : s)
            ++mmp[i];
        ::std::sort(s.begin(), s.end(), [&](const char a, const char b) {
            return (mmp[a] != mmp[b]) ? mmp[a] > mmp[b] : a > b;
        });
        return s;
    }
};