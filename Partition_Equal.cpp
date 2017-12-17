#include <iostream>
#include <vector>
/*
 * leetcode 2017.12.17
 * Partition Equal Subset Sum
 * */
using namespace std;
bool canPartition(vector<int>& nums) {
    int len = nums.size();
    int sum = 0;
    for(int i = 0;i<len;++i){
        sum+=nums[i];
    }
    if(sum%2!=0) return false;
    int target = sum/2;
    vector<vector<int>> dp(len,vector<int>(target+1));
    for(int i = 0;i<len;++i){
        for(int j = 0;j<target+1;++j){
            dp[i][j] = 0;
        }
    }
    for(int j = nums[0];j<target+1;++j){
        dp[0][j] = nums[0];
    }
    for(int i = 1;i<len;++i){
        for(int j = nums[i];j<target+1;++j){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
        }
    }
    if(dp[len-1][target] == target){
        return true;
    }
    else return false;
}
int main() {
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i = 0;i<n;++i){
            cin>>nums[i];
        }
        bool res = canPartition(nums);
        if(res == true) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}