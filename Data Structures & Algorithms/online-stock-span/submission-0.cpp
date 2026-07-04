class StockSpanner {
   private:
    vector<int> prices;

   public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        for(int i = prices.size()-1; i >= 0; i--){
            if(prices[i] <= price){
                span +=1;
            }else{
                break;
            }
        }
        prices.push_back(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */