class Solution {
   public:
    int countElements(vector<int>& arr) {
        unordered_set<int> seen(arr.begin(), arr.end());

        int count = 0;
        for (int num : arr) {
            if (seen.count(num + 1)) {
                count++;
            }
        }
        return count;
    }
};
