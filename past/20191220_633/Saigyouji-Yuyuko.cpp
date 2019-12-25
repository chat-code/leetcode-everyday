#include <cmath>
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long long i = 0; i * i <= c; ++i)
            if (long long tmp = sqrt(c - i * i); tmp * tmp + i * i == c)
                return true;
        return false;
    }
};