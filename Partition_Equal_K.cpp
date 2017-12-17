#include <iostream>
#include <vector>
/*
 * leetcode 2017.12.17
 * Partition Equal K Subset Sum
 * */
using namespace std;
bool helper(vector<int>& nums, vector<bool>& visited, int k,int start,int curSum,int target){
    if(k == 1) return true;
    if(curSum == target){
        return helper(nums,visited,k-1,0,0,target);
    }
    for(int i = start;i<nums.size();++i){
        if(visited[i] == true) continue;
        visited[i] = true;
        if(helper(nums,visited,k,i+1,curSum+nums[i],target)) return true;
        visited[i] = false;
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int len = nums.size();
    int sum = 0;
    for(int i = 0;i<len;++i){
        sum += nums[i];
    }
    if(sum%k != 0) return false;
    vector<bool> visited(len,false);
    return helper(nums,visited,k,0,0,sum/k);
}
int main() {
    int n,k;
    while(cin>>n>>k){
        vector<int> nums(n);
        for(int i = 0;i<n;++i){
            cin>>nums[i];
        }
        bool res = canPartitionKSubsets(nums,k);
        if(res) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}