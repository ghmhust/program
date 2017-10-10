#include <iostream>
#include <string>
/*
 * leetcode 38 2017.10.10
 * 读字符串数字符串
 * */
using namespace std;

string helper(string& res){
    int len = res.size();
    string s = "";
    if(len == 1){
        return "11";
    }
    int cnt = 1;
    for(int i = 0;i<len-1;++i) {
        if (res[i] == res[i + 1]) {
            cnt++;
            continue;
        }
        else {
            s += to_string(cnt);
            s += res[i];
            cnt = 1;
        }
    }
    if(cnt != 1){
        s += to_string(cnt);
        s += res[len - 1];
    }
    if(res[len-1] != res[len-2]){
        cnt = 1;
        s += to_string(cnt);
        s += res[len - 1];
    }
    return s;
}

string countAndSay(int n) {
    string res = "1";
    for(int i = 1;i<n;++i){
        res = helper(res);
    }
    return res;
}

int main() {
    int n = 0;
    while(cin>>n){
        string s = countAndSay(n);
        cout<<s<<endl;
    }
    return 0;
}