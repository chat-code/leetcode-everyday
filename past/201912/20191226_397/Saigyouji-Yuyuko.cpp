#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    static constexpr int MultiplyDeBruijnBitPosition[32] =
        {
            0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
            31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9};
    int shift(unsigned int v)
    {
        return MultiplyDeBruijnBitPosition[(((v & -v) * 0x077CB531U)) >> 27];
    }
    int integerReplacement(int n)
    {
        ::std::unordered_map<unsigned int, int> mmp{{1, 0}, {2, 1}};
        return help(n, mmp);
    }
    int help(unsigned int n, ::std::unordered_map<unsigned int, int> &mmp)
    {
        if (auto ans = mmp.find(n); ans != mmp.end())
            return ans->second;
        auto ww = shift(n);
        if (ww > 0)
            ww += help(n >> ww, mmp);
        else
            ww = 1 + ::std::min(help((n + 1), mmp), help((n - 1), mmp));
        mmp[n] = ww;
        return ww;
    }
};