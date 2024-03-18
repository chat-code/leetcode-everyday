#include <vector>
#include <algorithm>
class Solution
{
public:
    int countSquares(::std::vector<::std::vector<int>> &matrix)
    {
        auto summ = 0;
        for (auto i = 0; i != matrix.size(); ++i)
            for (auto j = 0; j != matrix[0].size(); ++j)
                if (matrix[i][j] == 1)
                {
                    if (i > 0 && j > 0)
                        matrix[i][j] += ::std::min({matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]});
                    summ += matrix[i][j];
                }
        return summ;
    }
};
