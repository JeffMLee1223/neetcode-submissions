class Solution {
   public:
    int maxDifference(string s) {
        int freq[26] = {};

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        int maxOdd = 1;
        int minEven = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if(freq[i] == 0){
                continue;
            }
            if(freq[i] % 2 == 0){
                minEven = min(minEven, freq[i]);
            }else{
                maxOdd = max(maxOdd, freq[i]);
            }            
        }
        return maxOdd - minEven;
    }
};