class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
                [](vector<int> &v1, vector<int> &v2){ return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0]; });

        int i = 0, n = 1, count = 1;;
        while (i + n < intervals.size()) {
            if (intervals[i][1] >= intervals[i+n][1]) {
                n += 1;
            } else {
                count += 1;
                i += n;
                n = 1;
            }
        }

        return count;
    }
};

