// 超时题解。阿西吧。
// class Solution {
// public:
//     int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
//         vector<pair<int, int>> ivec;
        
//         for (int i = 0; i < Profits.size(); i++) {
//             ivec.push_back(make_pair(Profits[i], Capital[i]));
//         }
//         int max = 0;
//         int maxIndex = 0;
//         int pSize = Profits.size();
//         int ivecSize = ivec.size();
//         for(int j = 0; j < k && j <pSize; j++) {
//             for (int i = 0; i < ivec.size(); i++) {
//                 if(ivec[i].first > max && ivec[i].second <= W) {
//                     max = ivec[i].first;
//                     maxIndex = i;
//                 }
//             }   
//             ivec.erase(ivec.begin() + maxIndex);
//             ivecSize = ivec.size();
//             W += max;
//             max = 0;
//         }
//         return W;
//     }
// };
// 以下为题解
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        // 优先队列，以从大到小的顺序排列。
        // 里面存放小于W的所有项目
        priority_queue<int>pq; 
        // 存放Capital数组和它的index
        vector<pair<int,int>>v; 
        // 初始化Capital
        for(int i = 0;i<Capital.size();i++){
            v.push_back({Capital[i],i});
        }
        sort(v.begin(),v.end());
        int j = 0;
        while(k){
            //push values
            // 将所有小于等于W的值，push进pq中。
            // Capital本身不会变化，所以j可以一直使用
            while(j<Capital.size() && v[j].first<=W){
                pq.push(Profits[v[j].second]);
                j++;
            }
            if(!pq.empty()){
                // 获取最大的profit
                // 更新catital
                W = W+pq.top();
                pq.pop();
               
            }
             k--;
            
        }
        return W;
    }
};