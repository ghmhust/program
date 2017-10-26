#include <iostream>
#include <string>
/*
 * leetcode 2017.10.26
 * 最长回文子串 dp
 * */
using namespace std;

string longestPalindrome(string s) {
    int len = s.size();
    if(len == 1) return s;
    int maxlen = 1;
    int begin = 0;
    int dp[1000][1000]={0};
    for(int i = 0;i<len;++i){
        dp[i][i] = 1;
        if(i+1<len && s[i] == s[i+1]) {
            dp[i][i + 1] = 1;
            maxlen = 2;
            begin = i;
        }
    }
    for(int lenth = 3;lenth<=len;++lenth){
        for(int i = 0;i<len-lenth+1;++i){
            int j = i+lenth-1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                begin = i;
                maxlen = lenth;
            }
        }
    }
    return s.substr(begin,maxlen);
}

int main() {
    string s;
    while(cin>>s){
        string res = longestPalindrome(s);
        cout<<res<<endl;
    }
    return 0;
}