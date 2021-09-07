class Solution {
	public:
		int numberOfWeakCharacters(vector<vector<int>>& p) {
			sort(p.begin(), p.end(), [](const vector<int>& l, const vector<int>& r) {
				if (l[0] != r[0]) {
					return l[0] < r[0];
				} else {
					return l[1] > r[1];
				}
			});

			int cnt = 0;
			int maxx = -1;
			
			for (int i = p.size() - 1; i >= 0; --i) {
				if (p[i][1] < maxx)
					++cnt;
				else
					maxx = p[i][1];
			}

			return cnt;
		}
};