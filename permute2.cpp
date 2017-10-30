#include <iostream>
#include <vector>
#include <set>
using namespace std;

void helper(set<vector<int>>& myset,vector<int>& nums,vector<int>& var,vector<int>& visited){
    if(var.size() == nums.size()){
        myset.insert(var);
        return;
    }
    for(int i = 0;i<nums.size();++i){
        if(visited[i] == 0){
            visited[i] = 1;
            var.push_back(nums[i]);
            helper(myset,nums,var,visited);
            var.pop_back();
            visited[i] = 0;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    vector<int> var;
    vector<int> visited(n,0);
    set<vector<int>> myset;
    helper(myset,nums,var,visited);
    set<vector<int>>::iterator it;
    for(it = myset.begin();it!=myset.end();++it){
        res.push_back(*it);
    }
    return res;
}

int main() {
    int n;
    while(cin>>n){
        vector<int> temp(n);
        for(int i = 0;i<n;++i){
            cin>>temp[i];
        }
        vector<vector<int>> res = permuteUnique(temp);
        for(int i = 0;i<res.size();++i){
            for(int j = 0;j<n;++j){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}