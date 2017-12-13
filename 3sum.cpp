#include <iostream>
#include <vector>
#include <algorithm>
/*
 * 2017.12.13 leetcode
 * 3sum
 * */
using namespace std;

void helper(vector<vector<int>>& res,vector<int>& nums,int l,int r, int temp){
    int var = 0-temp;
    while(l<r){
        if(nums[l]+nums[r]<var){
            ++l;
        }
        else if(nums[l]+nums[r]>var) --r;
        else{
            vector<int> res1;
            res1.push_back(temp);
            res1.push_back(nums[l]);
            res1.push_back(nums[r]);
            res.push_back(res1);
            while(l<r&&nums[l]==nums[l+1]) l++;
            while(l<r&&nums[r]==nums[r-1]) r--;
            l++;
            r--;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    int len = nums.size();
    if(len<=2) return res;
    for(int i = 0;i<len-2;++i){
        int temp = nums[i];
        int l = i+1;
        int r = len-1;
        if(i>0 && nums[i] == nums[i-1]) continue;
        helper(res,nums,l,r,temp);
    }
    return res;
}

int main() {
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i = 0;i<n;++i){
            cin>>nums[i];
        }
        vector<vector<int>> res = threeSum(nums);
        for(int i = 0;i<res.size();++i){
            for(int j = 0;j<3;++j){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}