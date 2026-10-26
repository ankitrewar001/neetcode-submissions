class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, best = 0;
        while (l < r) {
            int h = min(heights[l], heights[r]);
            best = max(best, h * (r - l));
            while (l < r && heights[l] <= h) l++;
            while (l < r && heights[r] <= h) r--;
        }
        return best;
    }
};