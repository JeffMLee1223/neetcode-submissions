class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet;

        for (int i = 0; i < allowed.size(); i++) {
            allowedSet.insert(allowed[i]);
        }

        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            bool valid = true;
            for (int j = 0; j < words[i].size(); j++) {
                if (allowedSet.find(words[i][j]) == allowedSet.end()) {
                    valid = false;
                    break;
                }
            }
            if(valid){
                count++;
            }
        }

        return count;
    }
};