#include <iostream>
#include <vector>
using namespace std;
/*
 * leetcode 2017.10.28
 * 全排列
 * */

/*
 * DFS
 * */
void helper(vector<int>& nums,vector<int>& var,vector<int>& visited,vector<vector<int>>& res){
    if(var.size() == nums.size()){
        res.push_back(var);
        return;
    }
    for(int i = 0;i<nums.size();++i){
        if(visited[i] == 0){
            visited[i] = 1;
            var.push_back(nums[i]);
            helper(nums,var,visited,res);
            visited[i] = 0;
            var.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> res;
    if(n == 0) return res;
    vector<int> visited(n,0);
    vector<int> var;
    helper(nums,var,visited,res);
    return res;
}
/*
 * 递归
 * */
void helper1(vector<int>& nums,vector<vector<int>>& res,int index){
    if(index == nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i = index;i<nums.size();++i){
        swap(nums[i],nums[index]);
        helper1(nums,res,index+1);
        swap(nums[i],nums[index]);
    }
}

vector<vector<int>> permute1(vector<int>& nums){
    vector<vector<int>> res;
    if(nums.size() == 0) return res;
    int index = 0;
    helper1(nums,res,index);
    return res;
}

int main() {
    int n;
    while(cin>>n){
        vector<int> temp(n);
        for(int i = 0;i<n;++i) cin>>temp[i];
        vector<vector<int>> res = permute1(temp);
        for(int i = 0;i<res.size();++i){
            for(int j = 0;j<n;++j){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}