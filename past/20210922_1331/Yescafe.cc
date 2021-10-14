class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> ranks;
		const int n = arr.size();
		ranks.reserve(n);
		auto arr2 = arr;
		sort(arr2.begin(), arr2.end(), greater<int>{});
		arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
		map<int, int> rank_m;
		for (int i = 0, r = arr2.size(); i < arr2.size(); ++i, --r) {
			rank_m[arr2[i]] = r;
		}
		for (auto& a : arr) {
			ranks.push_back(rank_m[a]);
		}
		return ranks;
	}
};
