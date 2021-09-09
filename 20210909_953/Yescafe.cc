class Solution {
	public:
		bool isAlienSorted(vector<string>& words, string order) {
			int o[128] = { 0 };
			for (int i = 0; i < order.length(); ++i) {
				o[order[i]] = i;
			}
			return is_sorted(words.begin(), words.end(), [&](const string& a, const string& b) {
				const int la = a.length(), lb = b.length();
				int i = 0, j = 0;
				while (i != la && j != lb) {
					int diff = o[a[i]] - o[b[j]];
					if (diff > 0) {
						return false;
					} else if (diff < 0) {
						return true;
					}
					++i;
					++j;
				}
				if (j != lb)
					return true;
				return false;
			});
		}
};
