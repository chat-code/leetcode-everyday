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
    bool canWinNim(int n)
    {
        return n & 3;
    }
};