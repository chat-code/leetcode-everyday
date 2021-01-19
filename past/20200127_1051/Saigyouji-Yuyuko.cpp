#include <vector>
#include <algorithm>
class Solution
{
public:
    int heightChecker(::std::vector<int> &heights)
    {
        auto tmp{heights};
        ::std::sort(tmp.begin(), tmp.end());
        auto count = 0;
        for (auto i = 0; i != tmp.size(); ++i)
            if (heights[i] != tmp[i])
                ++count;
        return count;
    }
};