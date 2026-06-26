class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int spend = prices[0] + prices[1];
        if(spend > money){
            return money;
        }
        return {money - spend};
    }
};