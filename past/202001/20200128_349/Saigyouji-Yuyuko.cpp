#include <vector>
#include <unordered_map>
class Solution
{
public:
    ::std::vector<int> intersection(::std::vector<int> &nums1, ::std::vector<int> &nums2)
    {
        ::std::unordered_map<int, bool> mmp;
        for (auto i : nums1)
            mmp[i] = false;
        auto count = 0;
        for (auto i : nums2)
            if (mmp.count(i) > 0 && !mmp[i])
            {
                ++count;
                mmp[i] = true;
            }
        ::std::vector<int> t;
        t.reserve(count);
        for (auto iter : mmp)
            if (iter.second)
                t.push_back(iter.first);
        return t;
    }
};