class Solution {
public:
	int findGCD(vector<int>& nums) {
		auto [maxi, mini] = minmax_element(nums.begin(), nums.end());
		int maxx = *maxi, minn = *mini;
		return gcd(maxx, minn);
	}
};
