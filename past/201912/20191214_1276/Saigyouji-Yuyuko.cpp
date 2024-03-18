#include<vector>
class Solution
{
public:
    ::std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        if (tomatoSlices & 1 == 1 || tomatoSlices < cheeseSlices << 1 || tomatoSlices > cheeseSlices << 2)
            return ::std::vector<int>{};
        return ::std::vector<int>{((tomatoSlices - (cheeseSlices << 1)) >> 1), cheeseSlices - ((tomatoSlices - (cheeseSlices << 1)) >> 1)};
    }
};