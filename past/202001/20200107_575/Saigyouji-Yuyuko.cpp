#include <string>
#include <array>
#include <vector>
// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")
// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution
{
public:
    int tmp[200009];
    int distributeCandies(::std::vector<int> &candies)
    {
        int count = 0;
        for (auto i : candies)
            if (++tmp[i + 100000] == 1)
                ++count;
        return ::std::min(count, int(candies.size()) / 2);
    }
};