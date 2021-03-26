#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto &x : nums) {
            res = res ^ x;
        }
        return res;
    }
};