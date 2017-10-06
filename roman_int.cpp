#include <iostream>
#include <string>
#include <map>
using namespace std;
int helper(string& s){
    map<char,int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int len = s.size();
    int temp = 0;
    for(int i = 0;i<len-1;++i){
        if(mp[s[i]]>=mp[s[i+1]]){
            temp += mp[s[i]];
        }
        else temp -= mp[s[i]];
    }
    temp += mp[s[len-1]];
    return temp;
}
int main() {
    string str;
    while(cin>>str){
        int res = helper(str);
        cout<<res<<endl;
    }
    return 0;
}