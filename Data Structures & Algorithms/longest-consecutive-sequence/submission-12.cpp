class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> s;  // we use set to store our numbers in
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        // sort(s.begin(), s.end()); ->bug;  set cannot be sorted,
        // while set is sort automatically, but it needs more runtime

        unordered_set<int>::iterator it;
        for (it = s.begin(); it != s.end(); it++) {
            // **** it is a pointer, must dereference so we can use it
            int num = *it;
            if (!s.count(num - 1)) {
                // if there's no number exactly 1 smaller than
                // the current one, that means it's a potential to be a head, and
                // might be the longest consecutive sequence

                int length = 1;  // we start counting the length

                while (s.count(num + 1)) {
                    // if there's number behind it, that means we find the head
                    // so the length+1 and we continue check if there's more number behind it

                    length++;
                    num++;
                }
                result = max(result, length);  // we keep updating the the max length
            }
        }  // the reason that we use iterator to traverse the whole set is because we have to check
           // every number is the head or not we cannot skip a number just because it's not the
           // previous number's following, itself can also have a chance to be head of the
           // consecutive sequence

        return result;
    }
};
