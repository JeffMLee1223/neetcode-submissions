class Solution {
   public:
    string largestGoodInteger(string num) {
        vector<string> good;
        for (int i = 0; i < num.size(); i++) {
            if (i + 2 < num.size() && num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string goodNum = num.substr(i, 3);
                good.push_back(goodNum);
            }
        }
        if (good.empty()) {
            return "";
        }

        int largestIndex = 0;

        for (int i = 1; i < good.size(); i++) {
            if ((good[i]) > (good[largestIndex])) {
                largestIndex = i;
            }
        }

        return good[largestIndex];
    }
};