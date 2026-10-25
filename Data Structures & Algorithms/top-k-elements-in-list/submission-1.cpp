class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for (auto n : nums) {
            mpp[n]++;
        }

        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
