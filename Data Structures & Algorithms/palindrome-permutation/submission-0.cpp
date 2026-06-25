class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int>freq;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]] +=1;
        }
        unordered_map<char, int>::iterator it;

        int oddCount = 0;
        for(it = freq.begin(); it != freq.end(); it++){
            if((it->second) % 2){
                oddCount += 1;
            }
        }
        if(oddCount > 1){
            return false;
        }else{
            return true;
        }

    }
};
