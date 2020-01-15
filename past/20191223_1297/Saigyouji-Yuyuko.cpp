#include <string>
#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    int maxFreq(::std::string s, int maxLetters, int minSize, int maxSize)
    {
        ::std::unordered_map<::std::string, int> mmp;
        int ab[26];
        memset(ab, 0, sizeof(ab));
        auto count = 0;
        auto maxx = 0;
        auto begin = 0;
        for (auto end = 0; end < s.size();)
        {
            if (++ab[s[end++] - 'a'] == 1)
                ++count;
            while (count > maxLetters || end - begin > minSize)
                if (--ab[s[begin++] - 'a'] == 0)
                    --count;
            if (end - begin == minSize)
                maxx = ::std::max(maxx, ++mmp[s.substr(begin, minSize)]);
        }
        return maxx;
    }
};