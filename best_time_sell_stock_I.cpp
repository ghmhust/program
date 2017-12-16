#include <iostream>
#include <vector>
/*
 * leetcode 2017.12.16
 * Best Time to Buy and Sell Stock
 * 持一股，买卖一次
 * */
using namespace std;
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len<=1) return 0;
    int local = 0;
    int global = 0;
    for(int i = 1;i<len;++i){
        local = max(local+prices[i]-prices[i-1],0);
        global = max(local,global);
    }
    return global;
}
int main() {
    int n;
    while(cin>>n){
        vector<int>prices(n);
        for(int i = 0;i<n;++i){
            cin>>prices[i];
        }
        int res = maxProfit(prices);
        cout<<res<<endl;
    }
    return 0;
}