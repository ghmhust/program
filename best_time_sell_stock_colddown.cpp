#include <iostream>
#include <vector>
/*
 * leetcode 2017.12.16
 * best time buy stock with colddown
 * */
using namespace std;
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len<=1) return 0;
    vector<int>buy(len,0);
    vector<int>sell(len,0);
    buy[0] = 0 - prices[0];
    for(int i = 1;i<len;++i) {
        buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
        sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
    }
    return sell[len-1];
}
int main() {
    int n;
    while(cin>>n){
        vector<int> prices(n);
        for(int i = 0;i<n;++i){
            cin>> prices[i];
        }
        int res = maxProfit(prices);
        cout<<res<<endl;
    }
    return 0;
}