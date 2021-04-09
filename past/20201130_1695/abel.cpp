#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
		map<int, int> m;
		int n = a.size();
		ll cur = 0, res = 0;
		
		for (int i = 0, j = 0; j < n; ++j) {
			m[a[j]]++;
			cur += a[j];
			while (m[a[j]] > 1) {
				m[a[i]]--;
				cur -= a[i];
				++i;
			}
			res = max(res, cur);
		}
		return res;
    }
};
