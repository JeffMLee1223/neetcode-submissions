class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0; i < details.size(); i++ ){
            int ten = details[i][11] - '0';
            int one = details[i][12] - '0';
            int age = ten * 10 + one;
            if(age > 60){
                ans++;
            }
        }
        return ans;
    }
};