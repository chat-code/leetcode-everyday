class Solution {
public:
	int findNumbers(vector<int>& nums) {
		return count_if(nums.begin(), nums.end(), [](int n) {
			int bc = 0;
			if (n == 0) return false;
			while (n) {
				n /= 10;
				++bc;
			}
			return bc % 2 == 0;
		});
	}
};
