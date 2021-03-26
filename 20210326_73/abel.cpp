#include <vector>

using namespace std;
using VI = vector<int>;

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        if (!n) return;
        int m = a[0].size();
        if (!m) return;

        bool x {}, y {};
        for (int i = 0; i < n; ++i) if (!a[i][0]) y = true;
        for (int j = 0; j < m; ++j) if (!a[0][j]) x = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (!a[i][j]) {
                    a[0][j] = a[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            if (!a[i][0]) {
                for (int j = 1; j < m; ++j) { a[i][j] = 0; }
            }
        }
        for (int j = 1; j < m; ++j) {
            if (!a[0][j]) {
                for (int i = 1; i < n; ++i) { a[i][j] = 0; }
            }
        }

        if (!a[0][0]) {
            for (int i = 1; i < n; ++i) { a[i][0] = 0; }
            for (int j = 1; j < m; ++j) { a[0][j] = 0; }
        }
        if (x)
            for (int j = 0; j < m; ++j) { a[0][j] = 0; }
        if (y)
            for (int i = 0; i < n; ++i) { a[i][0] = 0; }
    }
};
