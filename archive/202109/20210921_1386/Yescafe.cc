class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
		map<int, vector<int>> m;
		for (auto& v : rs) {
			m[v[0]].push_back(v[1]);
		}

		int cnts = 2 * (n - m.size());
		for (auto& [i, s] : m) {
			vector<int> occ(11);
			for (auto& a : s) {
				occ[a] = true;
			}
			bool canMid = true;
			if (!occ[2] && !occ[3] && !occ[4] && !occ[5]) {
				++cnts;
				canMid = false;
			}
			if (!occ[6] && !occ[7] && !occ[8] && !occ[9]) {
				++cnts;
				canMid = false;
			}
			if (canMid) {
				if (!occ[4] && !occ[5] && !occ[6] && !occ[7])
				++cnts;
			}
		}

		return cnts;
	}
};
