#include <string>
#include <vector>
#include <utility>
class Solution
{
public:
    constexpr static ::std::pair<int, int> alphabat[] = {
        {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {5, 0}};
    void DU(int num, ::std::string &str, int &index)
    {
        if (num > 0)
            while (num--)
                str[index++] = 'D';
        else
            while (num++)
                str[index++] = 'U';
    }
    void RL(int num, ::std::string &str, int &index)
    {
        if (num > 0)
            while (num--)
                str[index++] = 'R';
        else
            while (num++)
                str[index++] = 'L';
    }
    ::std::string alphabetBoardPath(::std::string target)
    {
        ::std::pair<int, int> bp{0, 0};
        ::std::vector<::std::pair<int, int>> path{target.size()};
        auto sum = target.size();
        for (auto i = 0; i != target.size(); ++i)
        {
            auto tp = alphabat[target[i] - 'a'];
            sum += abs(tp.first - bp.first) + abs(tp.second - bp.second);
            path[i] = ::std::pair<int, int>{tp.first - bp.first, tp.second - bp.second};
            bp = tp;
        }
        ::std::string ans(sum, '\0');
        auto index = 0;
        auto t = 0;
        for (auto i = 0; i != target.size(); ++i)
        {
            if (target[i] != 'z')
            {
                DU(path[i].first, ans, index);
                RL(path[i].second, ans, index);
            }
            else
            {
                RL(path[i].second, ans, index);
                DU(path[i].first, ans, index);
            }
            ans[index++] = '!';
        }
        return ans;
    }
};