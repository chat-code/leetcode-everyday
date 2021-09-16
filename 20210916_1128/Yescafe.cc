class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		map<pair<int, int>, int> cnts;
		for (auto& d : dominoes) {
			if (d[0] < d[1]) {
				++cnts[make_pair(d[0], d[1])];
			} else {
				++cnts[make_pair(d[1], d[0])];
			}
		}

		int cnt = 0;
		for (auto& [_, c] : cnts) {
			cnt += (c * (c - 1)) / 2;
		}
		return cnt;
	}
};
