class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest = strs[0].size();
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() < shortest){
                shortest = strs[i].size();
            }
        }
        string ans = "";
        for(int i = 0; i < shortest; i++){
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    return ans;
                }else if(strs[j][i] == strs[0][i] && j == strs.size()-1){
                    ans = ans + strs[j][i];
                }
            }
        }
        return ans;
    }
};