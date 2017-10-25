#include <iostream>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int temp[256];
    for(int i = 0;i<256;++i) temp[i] = -1;
    int len = s.size();
    int maxnum = 0;
    int pre = 0;
    for(int i = 0;i<len;++i){
        int d1 = INT_MAX;
        if(temp[s[i]] != -1){
            d1 = i-temp[s[i]];
        }
        int d2 = pre+1;
        temp[s[i]] = i;
        pre = min(d1,d2);
        if(pre>maxnum){
            maxnum = pre;
        }
    }
    return maxnum;
}
int main() {
    string s;
    while(cin>>s){
        int res = lengthOfLongestSubstring(s);
        cout<<res<<endl;
    }
    return 0;
}