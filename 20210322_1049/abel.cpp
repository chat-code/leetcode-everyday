#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 30010;
int d[N];

class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int sum = 0;
        for (auto &x : a) sum += x;

        int V = sum / 2, n = a.size();
        
        memset(d, 0, sizeof d);
        for (int i = 0; i < n; ++i) {
            for (int v = V; v >= a[i]; --v) {
                d[v] = max(d[v], d[v - a[i]] + a[i]);
            }
        }

        return abs(d[V] - (sum - d[V]));
    }
};
