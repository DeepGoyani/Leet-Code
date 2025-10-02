class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.empty())return 0;
      int minprice=INT_MAX;
      int maxprofit=0;
      for(int price:prices){
        if(price<minprice){
            minprice=price;
        }
        else{
            maxprofit=max(maxprofit,price-minprice);
        }
      }
      return maxprofit;
    }
};
