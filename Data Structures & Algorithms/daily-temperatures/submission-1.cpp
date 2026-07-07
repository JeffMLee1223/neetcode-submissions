class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temps;  //{temp, index}
        vector<int> result(temperatures.size(),0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!temps.empty() && temps.top().first < temperatures[i]) {
                result[temps.top().second] = (i - temps.top().second);
                temps.pop();
            }
            temps.push({temperatures[i], i});
        }

        return result;
    }
};
