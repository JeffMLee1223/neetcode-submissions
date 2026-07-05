class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temps;  //{temp, index}
        vector<int> day(temperatures.size(),0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!temps.empty() && temps.top().first < temperatures[i]) {
                int oldIndex = temps.top().second;
                day[oldIndex] = i - oldIndex;
                temps.pop();
            }
            temps.push({temperatures[i],i});
        }
        return day;
    }
};

