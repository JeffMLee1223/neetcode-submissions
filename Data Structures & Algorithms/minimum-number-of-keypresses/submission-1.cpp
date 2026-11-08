class Solution {
   public:
    int minimumKeypresses(string s) {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        for(int i = 0; i < (int)freq.size(); i++){
            if(i < 9){
                ans += freq[i] * 1;
            }else if(i < 18){
                ans += freq[i] * 2;
            }else{
                ans += freq[i] * 3;
            }
        }
        

        return ans;
    }
};
