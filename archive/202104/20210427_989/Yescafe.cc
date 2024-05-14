// Runtime: 24 ms, faster than 76.74% of C++ online submissions for Add to Array-Form of Integer.
// Memory Usage: 27.4 MB, less than 63.23% of C++ online submissions for Add to Array-Form of Integer.

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    reverse(num.begin(), num.end());
    
    int carry = 0;
    
    for (int i = 0; i < num.size(); ++i) {
      auto ans = num[i] + k % 10 + carry;
      num[i] = ans % 10;
      carry = ans / 10;
      k /= 10;
    }
    while (carry || k) {
      auto ans = k % 10 + carry;
      num.push_back(ans % 10);
      carry = ans / 10;
      k /= 10;
    }
    
    reverse(num.begin(), num.end());
    return num;
  }
};

