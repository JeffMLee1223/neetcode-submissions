class Solution {
   public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> count1(101, 0);
        vector<int> count2(101, 0);

        for (int i = 0; i < nums1.size(); i++) {
            count1[nums1[i]]++;
            count2[nums2[i]]++;
        }

        int left = 1;
        int right = 100;
        int sum = 0;

        while (left <= 100 && right >= 1) {
            if (count1[left] == 0) {
                left++;
                continue;
            }

            if (count2[right] == 0) {
                right--;
                continue;
            }

            int pairs = min(count1[left], count2[right]);

            sum += left * right * pairs;


            count1[left] -= pairs;
            count2[right] -= pairs;

        }

        return sum;
    }
};
