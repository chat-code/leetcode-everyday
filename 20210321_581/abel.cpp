#include <vector>
#include <algorithm>

using namespace std;

const int N = 10010;
int stk[N];

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size(), left = n + 1, right = -1, tt = 0;
        bool flag = false;

        for (int i = 0; i < n; ++i) {
            while (tt && a[stk[tt]] > a[i]) {
                flag = true;
                left = min(left, stk[tt]);
                --tt;
            }
            stk[++tt] = i;
        }

        if (!flag) return 0;

        tt = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (tt && a[stk[tt]] < a[i]) {
                right = max(right, stk[tt]);
                --tt;
            }
            stk[++tt] = i;
        }

        return right - left + 1;
    }
};