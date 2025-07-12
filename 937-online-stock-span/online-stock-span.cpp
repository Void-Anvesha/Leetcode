class StockSpanner {
private:
vector<int> prices;
public:
    StockSpanner() {
        prices.clear();
    }
    
    int next(int price) {
        int cnt=1;
        prices.push_back(price);
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(price>=prices[i]) cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */