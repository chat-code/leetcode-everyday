#include <vector>
#include <cstring>
#include <algorithm>
class Solution
{
public:
    int tt[80001];
    int minIncrementForUnique(::std::vector<int> &A)
    {
        if (A.size() == 0)
            return 0;
        memset(tt, 0, sizeof(tt));
        auto count = 0;
        for (auto i : A)
            ++tt[i];
        auto minin = *::std::min_element(A.begin(), A.end());
        auto taken = 0;
        int p = A.size();
        for (auto i = minin; p > 0 || taken > 0; ++i)
        {
            count += taken;
            p -= tt[i];
            if (tt[i] > 1)
                taken += tt[i] - 1;
            else if (tt[i] == 0 && taken > 0)
                --taken;
        }
        return count;
    }
};