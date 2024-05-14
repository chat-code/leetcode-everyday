#include <stack>
#include <string>
class Solution
{
public:
    ::std::string smallestSubsequence(::std::string text)
    {
        int alb[26];
        bool in[26];
        memset(alb, 0, sizeof(alb));
        memset(in, false, sizeof(in));
        for (auto i = 0; i != text.size(); ++i)
            alb[text[i] - 'a'] = i;
        ::std::stack<char> mmp;
        for (auto i = 0; i != text.size(); ++i)
            if (!in[text[i] - 'a'])
            {
                while (!mmp.empty() && mmp.top() >= text[i] && alb[mmp.top() - 'a'] > i)
                {
                    in[mmp.top() - 'a'] = false;
                    mmp.pop();
                }
                in[text[i] - 'a'] = true;
                mmp.push(text[i]);
            }
        ::std::string ans(mmp.size(), 0);
        auto index = 0;
        while (!mmp.empty())
        {
            ans[index++] = mmp.top();
            mmp.pop();
        }
        ::std::reverse(ans.begin(), ans.end());
        return ans;
    }
};