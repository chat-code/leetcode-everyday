#include <vector>
#include <algorithm>
class Solution
{
public:
    int maxEqualFreq(::std::vector<int> &nums)
    {
        //memset(count,0,sizeof(count));
        //memset(freq,0,sizeof(count));
        int count[100010] = {0}, freq[100010] = {0};
        auto maxx = 1;
        auto maf = 0;
        for (auto i = 0; i != nums.size(); ++i)
        {
            --freq[count[nums[i]]];
            ++freq[++count[nums[i]]];
            maf = ::std::max(maf, count[nums[i]]);
            if (maf == 1 || maf * freq[maf] == i || (maf - 1) * freq[maf - 1] + maf == i + 1)
                maxx = i + 1;
        }
        return maxx;
    }
};