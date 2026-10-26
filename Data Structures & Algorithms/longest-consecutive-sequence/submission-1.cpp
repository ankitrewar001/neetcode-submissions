class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st;

        for(auto x : nums) st.insert(x);

        int ans = 1;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            if(st.find(nums[i]-1) == st.end()){
                int num = nums[i]+1;
                while(st.find(num++) != st.end()) cnt++;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};
