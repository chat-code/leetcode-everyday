#include <cmath>
#include <cstdint>
class Solution
{
public:
    int reachNumber(int target)
    {
        auto ans = int64_t(ceil((sqrt(int64_t(abs(target)) * 8 + 1) - 1) / 2));
        if ((ans * (ans + 1) / 2 - target) % 2 == 0)
            return ans;
        else if (((ans + 1) * (ans + 2) / 2 - target) % 2 == 0)
            return ans + 1;
        return ans + 2;
    }
};
