#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

// 找到最简单的实现方式

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int> rev(nums.begin(), nums.end());
        reverse(rev.begin(), rev.end());
        vector<int> pre_sum(nums.size(), 0), post_sum(nums.size(), 0);

        int len = int(nums.size());
        int len1 = -1, len2 = -1;
        int i;
        for ( i = 0; i < len; ++i) {
            if (i == 0) pre_sum[i] = nums[i];
            else 
                pre_sum[i] = pre_sum[i-1] + nums[i];
            if (pre_sum[i] > x) {
                len1 = i-1; break;
            } else len1++;
        }
        if (i == len) len1--;
        for ( i = 0; i < len; ++i) {
            if (i == 0) post_sum[i] = rev[i];
            else post_sum[i] = post_sum[i-1] + rev[i];

            if (post_sum[i] > x) {
                len2 = i-1; break;
            } else len2++;
        }
        if (i == len) len2--;

        if (len1 == -1 && len2 == -1) return -1;

        int res = INT_MAX;
        unordered_map<int, int> pos1, pos2;
        // left
        for (int i = 0; i <= len1; ++i) {
            pos1[pre_sum[i]] = i;
            if (pre_sum[i] == x) res = min(res, i+1);
        }
        // right
        for (int i = 0; i <= len2; ++i) {
            pos2[post_sum[i]] = i;
            if (post_sum[i] == x) res = min(res, i+1);
        }
        // left+right
        for (int i = 0; i <= len1; ++i) {
            int tar = x - pre_sum[i];
            if (pos2.find(tar) != pos2.end()) {
                res = min(res, pos2[tar]+i+2);
            }
        }
        return (res == INT_MAX) ? -1 : res;
    }
};