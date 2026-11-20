class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n-1;
        int maxl = height[l], maxr = height[r], ans = 0;

        while(r > l){
            if(height[l] <= height[r]){
                if(height[l] >= maxl){
                    maxl = height[l];
                }
                else{
                    ans += maxl - height[l];
                }
                l++;
            }
            else{
                if(height[r] >= maxr){
                    maxr = height[r];
                }
                else{
                    ans += maxr - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
