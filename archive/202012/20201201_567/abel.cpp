#include <string>

using namespace std;

class Solution {
public:
	bool check(int a[], int b[]) {
		for (int i = 0; i < 26; ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}

    bool checkInclusion(string s1, string s2) {
		int n = s1.size(), m = s2.size();
		int cnt1[26] {}, cnt2[26] {};
		
		for (int i = 0; i < n; ++i) cnt1[s1[i] - 'a']++;
		
		for (int i = 0, j = 0; j < m; ++j) {
			cnt2[s2[j] - 'a']++;
			if (j < n - 1) continue;
			if (check(cnt1, cnt2)) return true;
			cnt2[s2[i++] - 'a']--;
		}
		return false;
    }
};
