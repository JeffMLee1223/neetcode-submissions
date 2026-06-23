class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans = arr;
        for (int i = 0; i < arr.size() - 1; i++) {
            int maxRight = arr[i + 1];
            for (int j = i + 1; j < arr.size(); j++) {
                maxRight = max(maxRight, arr[j]);
            }
            ans[i] = maxRight;
        }
        ans[ans.size() - 1] = -1;
        return ans;
    }
};