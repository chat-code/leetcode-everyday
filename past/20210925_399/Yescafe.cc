class Solution {
	struct Mul {
		string key;
		double mul;
		Mul(const string& key, double mul) : key(key), mul(mul) {}
	};
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		for (int i = 0; i < equations.size(); ++i) {
			mp[equations[i][0]].push_back({equations[i][1], values[i]});
			mp[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
			vis[equations[i][0]] = vis[equations[i][1]] = false;
		}

		vector<double> ret;
		ret.reserve(queries.size());

		for (auto& l : queries) {
			for (auto& [_, v] : vis) {
				v = false;
			}
			auto& s = l[0];
			auto& t = l[1];
			ret.push_back(dfs(s, t, 1.));
		}

		return ret;
	}

private:
	double dfs(const string& s, const string& t, double rate) {
		if (mp.find(s) == mp.end()) return -1.;
		if (s == t)
			return rate;

		double r = -1.;
		for (auto& n : mp[s]) {
			if (vis[n.key]) continue;
			vis[n.key] = true;
			r = dfs(n.key, t, rate * n.mul);
			if (r != -1.) break;
			vis[n.key] = false;
		}

		return r == -1. ? -1. : r;
	}

	map<string, vector<Mul>> mp;
	map<string, bool> vis;
};
