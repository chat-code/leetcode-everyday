/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 * 
 * 記錄 b 中每一個數字的位置即可
 */

// @lc code=start

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        map<int, int> poses;
        int lenb = b.size(), lena = a.size();
        for (int i = 0; i < lenb; ++i) {
            poses[b[i]] = i;
        }
        VI result(lena, 0);
        for (int i = 0; i < lena; ++i) {
            int pos = poses[a[i]];
            bool flag = false;
            for (int j = pos+1; j < lenb; j++) {
                if (b[j] > a[i]) {
                    result[i] = b[j];
                    flag = true;
                    break;
                }
            }
            if (!flag) result[i] = -1;
        }
        return result;
    }
};
// @lc code=end

