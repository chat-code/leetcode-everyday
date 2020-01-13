#include <vector>
#include <algorithm>
class Solution
{
public:
    int minSwap(::std::vector<int> &A, ::std::vector<int> &B)
    {
        int count[2] = {0, 1};
        for (auto i = 1; i < A.size(); ++i)
        {
            int newcount[2] = {INT_MAX, INT_MAX};
            if (A[i] > A[i - 1] && B[i] > B[i - 1])
            {
                newcount[0] = ::std::min(count[0], newcount[0]);
                newcount[1] = ::std::min(count[1] + 1, newcount[1]);
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1])
                newcount[0] = ::std::min(count[1], newcount[0]);
            if (B[i] > A[i - 1] && A[i] > B[i - 1])
                newcount[1] = ::std::min(count[0] + 1, newcount[1]);
            count[0] = newcount[0];
            count[1] = newcount[1];
        }
        return ::std::min(count[0], count[1]);
    }
};