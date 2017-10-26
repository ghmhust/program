#include <iostream>
#include <vector>
/*
 * leetcode 2017.10.27
 * 有一个A，复制粘贴操作，要得到n个A，需要多少步
 */

using namespace std;
int minSteps(int n) {
    /*
    if(n==1) return 0;
    int res = n;
    for(int i = n;i>1;--i){
        if(n%i == 0)
        res = min(res,minSteps(n / i) + i);
    }
    return res;*/
    vector<int> dp(n+1,0);
    for(int i = 2;i<=n;++i){
        dp[i] = i;
        for(int j = i-1;j>=1;--j){
        if(i%j==0) dp[i] = min(dp[i],dp[i/j]+j);
        }
    }
    return dp[n];
}
int main() {
    int n;
    while(cin>>n){
        int res = minSteps(n);
        cout<<res<<endl;
    }
    return 0;
}