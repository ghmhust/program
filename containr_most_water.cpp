#include <iostream>
#include <vector>
/*
 * 2017.12.13 leetcode
 * container water
 * */
using namespace std;
int maxArea(vector<int>& height) {
    int len = height.size();
    int i = 0;
    int j = len-1;
    int res = 0;
    while(i<j){
        res = max(res,min(height[i],height[j])*(j-i));
        if(height[i]<height[j]){
            int p = i;
            while(p<j&&height[p]<=height[i]) ++p;
            i = p;
        }
        else{
            int q = j;
            while(q>i&&height[q]<=height[j]) --q;
            j = q;
        }
    }
    return res;
}
int main() {
    int n;
    while(cin>>n){
        vector<int> height(n);
        for(int i = 0;i<n;++i){
            cin>>height[i];
        }
        int res = maxArea(height);
        cout<<res<<endl;
    }
    return 0;
}