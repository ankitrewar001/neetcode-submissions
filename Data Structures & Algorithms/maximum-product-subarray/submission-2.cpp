class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_min = 1, curr_max = 1;
        int res = *max_element(nums.begin(), nums.end());

        for(int n: nums){
            int temp = curr_max * n;
            curr_max = max({temp, curr_min*n, n});
            curr_min = min({temp, curr_min*n, n});

            res= max(res, curr_max);
        }
        return res;
    }
};
