class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        // sor(s.begin(), s.end()); set cannot be sorted

        unordered_set<int>::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            // it is a pointer, must dereference so we can use it
            int num = *it;
            if (!s.count(num - 1)) {
                int length = 1;
                int current = num;
                while (s.count(num + 1)) {
                    length++;
                    num++;
                }
                result = max(result, length);
            }
        }

        return result;
    }
};
