#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0;
        sort(pairs.begin(), pairs.end());

        int n = int(pairs.size());
        vector<int> d(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1])
                    d[i] = max(d[i], d[j] + 1);
                res = max(res, d[i]);
            }
        }
        
        return res;
    }
};
