#include <iostream>
#include <vector>
/*
 * leetcode 2017.12.16
 * Best Time to Buy and Sell Stock with Transaction Fee
 * 手上只可持有一股 可交易多次
 * */
using namespace std;
int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if(len<=1) return 0;
    vector<int> buy(len,0);
    vector<int> sell(len,0);
    buy[0] = 0 - prices[0];
    for(int i = 1;i<len;++i){
        buy[i] = max(sell[i-1]-prices[i],buy[i-1]);
        //每一天的买入最大收益为：
        //（昨天卖了的最大收益）加上今天买入的花费 和 昨天没卖 比较
        sell[i] = max(buy[i-1]+prices[i]-fee,sell[i-1]);
        //每一天的卖出最大收益为：
        //昨天持有的最大收益加上今天卖掉的收入 和 昨天卖掉的最大收益 比较
    }
    return sell[len-1];
}
int main() {
    int n;
    int fee;
    while(cin>>n>>fee){
        vector<int> prices(n);
        for(int i = 0;i<n;++i){
            cin>>prices[i];
        }
        int res = maxProfit(prices,fee);
        cout<<res<<endl;
    }
    return 0;
}