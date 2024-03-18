#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution
{
public:
    ::std::unordered_multimap<int, int> mmp;
    ::std::vector<int> flag, dfsn, low;
    int index;
    ::std::vector<::std::vector<int>> criticalConnections(int n, ::std::vector<::std::vector<int>> &connections)
    {
        mmp.reserve(connections.size() * 2);
        flag.resize(n, -1);
        dfsn.resize(n, 0);
        low.resize(n, 0);
        for (auto &i : connections)
        {
            mmp.insert({i[0], i[1]});
            mmp.insert({i[1], i[0]});
        }
        index = 0;
        flag[0] = 0;
        tarjan(0);
        ::std::vector<::std::vector<int>> ans;
        for (auto &&i : connections)
            if (low[i[0]] > dfsn[i[1]] || low[i[1]] > dfsn[i[0]])
                ans.emplace_back(move(i));
        return ans;
    }
    void tarjan(int n)
    {
        dfsn[n] = index++;
        low[n] = dfsn[n];
        auto [begin, end] = mmp.equal_range(n);
        for (auto i = begin; i != end; ++i)
        {
            if (flag[i->second] == -1)
            {
                flag[i->second] = n;
                tarjan(i->second);
                low[n] = ::std::min(low[n], low[i->second]);
            }
            else if (i->second != flag[n])
            {
                low[n] = ::std::min(low[n], dfsn[i->second]);
            }
        }
    }
};