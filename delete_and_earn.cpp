#include <iostream>
#include <vector>
/*
 * 2017.12.14 leetcode
 * delete and earn
 * 转换为house robber问题
 * */
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    vector<int> res(10001,0);
    int len = nums.size();
    for(int i = 0;i<len;++i){
        res[nums[i]] += nums[i];
    }
    vector<int> dp(10001,0);
    dp[1] = res[1];
    for(int i = 2;i<10001;++i){
        dp[i] = max(dp[i-1],dp[i-2]+res[i]);
    }
    return dp[10000];
}
int main() {
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i = 0;i<n;++i){
            cin>>nums[i];
        }
        int res = deleteAndEarn(nums);
        cout<<res<<endl;
    }
    return 0;
}