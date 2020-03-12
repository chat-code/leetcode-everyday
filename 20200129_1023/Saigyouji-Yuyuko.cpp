#include <vector>
#include <string>
class Solution
{
public:
    ::std::vector<bool> camelMatch(::std::vector<::std::string> &queries, ::std::string pattern)
    {
        ::std::vector<bool> match(queries.size());
        for (auto i = 0; i != queries.size(); ++i)
            match[i] = ismatch(queries[i], pattern);
        return match;
    }
    bool ismatch(const ::std::string &query, const ::std::string &pattern)
    {
        auto matchpot = 0;
        for (auto i : query)
            if (matchpot < pattern.size() && pattern[matchpot] == i)
                ++matchpot;
            else if (i <= 'Z')
                return false;
        return matchpot == pattern.size();
    }
};