class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int right = heights.size() - 1;
        int left = 0;

        while (left < right) {
            int h = min(heights[right], heights[left]);
            int width = right - left;
            int area = h * width;
            if (area > max) {
                max = area;
            }
            if (heights[right] < heights[left]) {
                right--;
            } else {
                left++;
            }
        }
        return max;
    }
};
