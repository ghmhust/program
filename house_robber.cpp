#include <iostream>
#include <vector>
/*
 * leetcode 2017.10.30
 * house robber 1 2
 * DP
 * */
using namespace std;

int rob(vector<int>& nums) {
    int len = nums.size();
    if(len == 0) return 0;
    if(len == 1) return nums[0];
    if(len == 2) return max(nums[0],nums[1]);
    int sum[len];
    for(int i = 0;i<len;++i) sum[i] = 0;
    sum[0] = nums[0];
    sum[1] = max(nums[0],nums[1]);
    for(int i = 2;i<len;++i){
        sum[i] = max(sum[i-1],sum[i-2]+nums[i]);
    }
    return sum[len-1];
}
/*
 * 第一个房子到倒数第二个房子
 * 第二个房子到倒数第一个房子
 * */
int rob2(vector<int>& nums){
    int len = nums.size();
    if(len == 0) return 0;
    if(len == 1) return nums[0];
    if(len == 2) return max(nums[0],nums[1]);
    int sum[len-1];
    int sum_no[len-1];
    for(int i = 0;i<len-1;++i){
        sum[i] = 0;
        sum_no[i] = 0;
    }
    sum[0] = nums[0];
    sum[1] = max(nums[0],nums[1]);
    sum_no[0] = nums[1];
    sum_no[1] = max(nums[1],nums[2]);
    for(int i = 2;i<len-1;++i){
        sum_no[i] = max(sum_no[i-1],sum_no[i-2]+nums[i+1]);
    }
    for(int i = 2;i<len-1;++i){
        sum[i] = max(sum[i-1],sum[i-2]+nums[i]);
    }
    return max(sum[len-2],sum_no[len-2]);
}

int main() {
    int n;
    while(cin>>n){
        vector<int> temp(n);
        for(int i = 0;i<n;++i){
            cin>>temp[i];
        }
        int res = rob2(temp);
        cout<<res<<endl;
    }
    return 0;
}