class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int shortter = min(word1.size(), word2.size());
        string ans = "";

        for(int i = 0; i < shortter; i++){
            ans = ans + word1[i] + word2[i];
        }


        if(word1.size() < word2.size()){
            ans = ans + word2.substr(shortter);
        }
        if(word2.size() < word1.size()){
            ans = ans + word1.substr(shortter);
        }

        return ans;
    }
};