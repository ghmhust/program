#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    if(len == 1) return nums[0];
    int var = INT_MIN;
    int temp = INT_MIN;
    for(int i = 0;i<len;++i){
        if(var<0){
            var = 0;
        }
        var += nums[i];
        if(temp<var) temp = var;
    }
    return temp;
}

int main() {
    int n = 0;
    while(cin>>n){
        vector<int> vec(n);
        for(int i = 0;i<n;++i)  cin>>vec[i];
        int res = maxSubArray(vec);
        cout<<res<<endl;
    }
    return 0;
}