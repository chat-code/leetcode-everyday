#include <vector>
class Solution
{
public:
    ::std::vector<int> spiralOrder(::std::vector<::std::vector<int>> &matrix)
    {
        ::std::vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        ans.reserve(matrix.size() * matrix[0].size());
        help(matrix, ans, 0);
        return ans;
    }

    void help(::std::vector<::std::vector<int>> &matrix, ::std::vector<int> &ans, int row)
    {
        if (row == matrix[0].size() - row - 1 && matrix.size() == matrix[0].size())
            ans.push_back(matrix[row][row]);
        // m[row][row] --> m[row][m[0].size()-row -1]
        for (auto i = row; i < matrix[0].size() - row - 1; ++i)
            if (ans.size() < matrix.size() * matrix[0].size())
                ans.push_back(matrix[row][i]);

        //m[row][m[0].size()-row-1] --> m[m.size()-row-1][m[0].size()-row-1]
        for (auto i = row; i < matrix.size() - row - 1; ++i)
            if (ans.size() < matrix.size() * matrix[0].size())
                ans.push_back(matrix[i][matrix[0].size() - row - 1]);

        //m[m.size()-row-1][m[0].size()-row-1] --> m[m.size()-row -1][row]
        for (int i = matrix[0].size() - row - 1; i > row; --i)
            if (ans.size() < matrix.size() * matrix[0].size())
                ans.push_back(matrix[matrix.size() - 1 - row][i]);

        //m[m.size()-row-1][row]  --> m[row][row]
        for (int i = matrix.size() - row - 1; i > row; --i)
            if (ans.size() < matrix.size() * matrix[0].size())
                ans.push_back(matrix[i][row]);

        if (ans.size() < matrix.size() * matrix[0].size())
            help(matrix, ans, row + 1);
    }
};