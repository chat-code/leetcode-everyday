#include <vector>
#include <queue>
class Solution
{
    bool searched[513];

public:
    int trans(int value, int x, int y, int m, int n)
    {
        value ^= (1 << (n * x + y));
        if (x - 1 >= 0)
            value ^= (1 << (y + (x - 1) * n));
        if (x + 1 < m)
            value ^= (1 << (y + (x + 1) * n));
        if (y - 1 >= 0)
            value ^= (1 << (n * x + y - 1));
        if (y + 1 < n)
            value ^= (1 << (n * x + y + 1));
        return value;
    }
    int minFlips(::std::vector<::std::vector<int>> &mat)
    {
        memset(searched, false, sizeof(searched));
        ::std::queue<int> state, step;
        auto value = 0, in = 1;
        for (const auto &i : mat)
            for (const auto j : i)
            {
                if (j)
                    value += in;
                in <<= 1;
            }
        if (value == 0)
            return 0;
        state.push(value);
        step.push(0);
        searched[value] = true;
        while (!state.empty())
        {
            value = state.front();
            state.pop();
            auto astep = step.front();
            step.pop();
            for (auto i = 0; i != mat.size(); ++i)
                for (auto j = 0; j != mat[0].size(); ++j)
                {
                    auto newvalue = trans(value, i, j, mat.size(), mat[0].size());
                    if (newvalue == 0)
                        return astep + 1;
                    else if (!searched[newvalue])
                    {
                        state.push(newvalue);
                        step.push(astep + 1);
                        searched[newvalue] = true;
                    }
                }
        }
        return -1;
    }
};