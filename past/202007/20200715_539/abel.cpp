//给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：timePoints = ["23:59","00:00"]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：timePoints = ["00:00","23:59","00:00"]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 2 <= timePoints <= 2 * 104 
// timePoints[i] 格式为 "HH:MM" 
// 
// Related Topics 字符串 
// 👍 76 👎 0

// 把每个时间转化成分钟数，加一天，把整个数组长度翻倍，排序，计算相邻


//leetcode submit region begin(Prohibit modification and deletion)
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

using namespace std;
using VI = vector<int>;
using VS = vector<string>;

class Solution {
public:
    int get_minute(string s) {
        int res = 0, hour = 0, minute = 0;
        hour = (s[0] - '0') * 10 + (s[1] - '0');
        minute = (s[3] - '0') * 10 + (s[4] - '0');
        res = hour * 60 + minute;
        return res;
    }

    int findMinDifference(vector <string> &timePoints) {
        int day = 24 * 60;
        VI minutes(2 * timePoints.size(), 0);
        int len = timePoints.size();
        for (int i = 0; i < len; i++) {
            int tmp = get_minute(timePoints[i]);
            minutes[i] = tmp;
            minutes[i + len] = tmp + day;
        }
        sort(minutes.begin(), minutes.end());
        int res = day - 1;
        for (int i = 1; i < len * 2; i++) {
            res = min(res, minutes[i] - minutes[i - 1]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
