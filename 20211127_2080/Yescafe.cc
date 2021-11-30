class RangeFreqQuery {
public:
	unordered_map<int,vector<int>> mp;
	RangeFreqQuery(vector<int>& arr) {
		for(int i=0;i<arr.size();i++){
			if(mp.find(arr[i])==mp.end())
				 mp[arr[i]]={i};
			else
				mp[arr[i]].push_back(i);
		}
	}

int query(int left, int right, int value) {
    //case : when element is not there in original array and map
     if(mp.find(value) == mp.end()){
        return 0;
    }
    else{
        auto lowerIt = lower_bound(mp[value].begin(), mp[value].end(), left);
        auto upperIt = upper_bound(mp[value].begin(), mp[value].end(), right);
        return upperIt-lowerIt;
    }
    
}
