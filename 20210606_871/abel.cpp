class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
	stations.push_back({target, 0});

	int sum = startFuel, res = 0, n = stations.size();
	priority_queue<int> p;
	for (auto &x : stations) {
		int y1 = x[0], y2 = x[1];

		while (sum < y1 && !p.empty()) {
			sum += p.top();
			p.pop();
			++res;
		}

		if (sum < y1) return -1;
		p.push(y2);
	}

	return res;
    }
};
