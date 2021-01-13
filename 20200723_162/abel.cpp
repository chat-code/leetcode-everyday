/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 * 
 * 線性可以做
 * 
 * 這題少給了一個條件：相鄰元素不相等。否則其實是不能用二分的。
 * 
 * 二分：如果 a[i]>a[i+1]，那麼答案在[0, i]中；
 *      如果 a[i]<a[i+1]，那麼答案在[i+1, n-1]中
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
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:

    int findPeakElement(vector<int>& a) {
        int len = a.size();
        int left = 0, right = len-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (a[mid] > a[mid+1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int findPeakElementV1(vector<int>& a) {
        int len = a.size(), res = 0;
        if (len == 1) return res;
        for (int i = 0; i < len; i++) {
            if (i == len-1) {
                if (a[i] > a[i-1]) return i;
            } else if (i == 0) {
                if (a[i] > a[i+1]) return i;
            }
            else {
                if (a[i] > a[i-1] && a[i] > a[i+1]) {
                    return i;
                }
            }
        }
        return res;
    }
};
// @lc code=end

