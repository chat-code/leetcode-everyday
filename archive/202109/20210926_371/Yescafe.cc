class Solution {
public:
	int getSum(int a, int b) {
		int carry = 0;
		int ans = 0;
		for (int i = 0; i < 8 * sizeof(a); ++i) {
			int a_bit = (a >> i) & 1;
			int b_bit = (b >> i) & 1;

			int ans_bit = a_bit ^ b_bit ^ carry;
			carry = (a_bit & b_bit) | (a_bit & carry) | (b_bit & carry);
			ans |= ans_bit << i;
		}

		return ans;
	}
};
