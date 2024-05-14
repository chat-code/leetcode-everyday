/*
 * @lc app=leetcode.cn id=963 lang=cpp
 *
 * [963] 最小面积矩形 II
 * 
 * 枚舉3個點，找出第4個點是否存在
 * 判斷兩個向量是否垂直，使用向量點積
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
#include <tuple>
#include <utility>

#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using VI = vector<int>;
using VS = vector<string>;
using PII = pair<int, int>;


class Solution {
public:
    set<PII> nm;

    int dot(const PII&a, const PII& b) {
        return a.first * b.first + a.second * b.second;
    }

    PII vec(const PII& a, const PII& b) {
        return make_pair(b.first-a.first, b.second-a.second);
    }

    double dist(const PII& a, const PII& b) {
        double dx = b.first - a.first, dy = b.second - a.second;
        return sqrt(dx*dx + dy*dy);
    }

    double area(const PII& a, const PII& b, const PII& c) {
        double w = dist(a, c), h = dist(b, c);
        return w*h;
    }

    double minAreaFreeRect(vector<VI>& points) {
        int len = points.size();
        double res = 0x3f3f3f3f;
        vector<PII> a(len);
        for (int i = 0; i < len; ++i) {
            PII p = make_pair(points[i][0], points[i][1]);
            a[i] = p;
            nm.insert(p);
        }
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (j == i) continue;
                PII p0 = a[i], p1 = a[j];

                for (int k = 0; k < len; ++k) {
                    if (k == i || k == j) continue;

                    PII t0 = a[k];
                    PII t1 = make_pair(p0.first+p1.first-t0.first, 
                                       p0.second+p1.second-t0.second);

                    if (nm.find(t1) != nm.end()) {
                        PII v1 = vec(t1, p0);
                        PII v0 = vec(t1, p1);

                        if (dot(v1, v0) == 0) {
                            double a = area(p0, p1, t0);
                            res = min(res, a);
                        }
                    }
                }
            }
        }
        if (res == 0x3f3f3f3f) return 0;
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution a;
    vector<VI> v{{0, 3}, {1, 2}, {3, 1}, {1, 3}, {2, 1}};
    cout << a.minAreaFreeRect(v) << endl;
    return 0;
}
