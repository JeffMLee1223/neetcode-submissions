class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        set<int> s; //we use set to store our numbers in
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        // sort(s.begin(), s.end()); ->bug;  set cannot be sorted,

        set<int>::iterator it;
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
