#include <vector>
#include <algorithm>
class Solution
{
public:
    int removeCoveredIntervals(::std::vector<::std::vector<int>> &intervals)
    {
        ::std::sort(intervals.begin(), intervals.end(), [](const ::std::vector<int> &a, const ::std::vector<int> &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        auto ans = intervals.size();
        auto b = -1;
        for (const auto &i : intervals)
            if (i[1] <= b)
                --ans;
            else
                b = i[1];
        return ans;
    }
};