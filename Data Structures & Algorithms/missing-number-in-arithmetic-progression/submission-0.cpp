class Solution {
   public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int diff = (arr.back() - arr.front()) / n;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return arr[i - 1] + diff;
            }
        }

        return arr[0];
    }
};
