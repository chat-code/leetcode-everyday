#include <vector>
class Solution
{
public:
    int next(int index, ::std::vector<int> &nums)
    {
        return (index + nums.size() + nums[index]) % nums.size();
    }
    bool circularArrayLoop(::std::vector<int> &nums)
    {
        for (auto i = 0; i != nums.size(); ++i)
            if (nums[i] != 0)
            {
                auto past = i;
                auto fast = next(i, nums);
                while (nums[fast] * nums[i] > 0 && nums[next(fast, nums)] * nums[i] > 0)
                {
                    if (past == fast)
                        if (past == next(past, nums))
                            break;
                        else
                            return true;
                    past = next(past, nums);
                    fast = next(next(fast, nums), nums);
                }
                past = i;
                fast = nums[i];
                while (nums[past] * fast > 0)
                {
                    auto n = next(past, nums);
                    nums[past] = 0;
                    past = n;
                }
            }
        return false;
    }
};