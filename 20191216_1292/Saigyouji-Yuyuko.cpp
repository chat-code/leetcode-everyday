#include <vector>
#include <algorithm>
class Solution
{
public:
    inline int help(::std::vector<::std::vector<int>> &mat, int a, int b, int len)
    {
        if (a && b)
            return mat[a + len][b + len] - mat[a - 1][b + len] - mat[a + len][b - 1] + mat[a - 1][b - 1];
        else if (a)
            return mat[a + len][b + len] - mat[a - 1][b + len];
        else if (b)
            return mat[a + len][b + len] - mat[a + len][b - 1];
        else
            return mat[a + len][b + len];
    }
    int maxSideLength(::std::vector<::std::vector<int>> &mat, int threshold)
    {
        for (auto i = 0; i != mat.size(); ++i)
            for (auto j = 0; j != mat[0].size(); ++j)
                if (i && j)
                    mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
                else if (i)
                    mat[i][j] += mat[i - 1][j];
                else if (j)
                    mat[i][j] += mat[i][j - 1];
        auto maxx = 0;
        for (auto i = 0; i < mat.size() - maxx; ++i)
            for (auto j = 0; j < mat[0].size() - maxx; ++j)
                for (auto k = maxx + 1; k <= ::std::min(mat.size() - i, mat[0].size() - j); ++k)
                    if (help(mat, i, j, k - 1) <= threshold)
                        maxx = k;
                    else
                        break;
        return maxx;
    }
};