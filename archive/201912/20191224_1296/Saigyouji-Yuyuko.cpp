#include <vector>
#include <map>
class Solution
{
public:
    bool isPossibleDivide(::std::vector<int> &nums, int k)
    {
        if (nums.size() % k != 0)
            return false;
        ::std::map<int, int> count;
        for (const auto i : nums)
            ++count[i];
        for (; count.size() > 0;)
        {
            auto [number, c] = *count.begin();
            if (c > 0)
            {
                auto flag = true;
                for (auto i = number + 1; i != number + k; ++i)
                {
                    if (count.count(i) > 0)
                    {
                        if (count[i] < c)
                            return false;
                        else if (count[i] > c)
                        {
                            if (flag)
                                flag = false;
                        }
                        else if (!flag)
                            return false;
                    }
                    else
                        return false;
                    count[i] -= c;
                }
            }
            count.erase(number);
        }
        return true;
    }
};