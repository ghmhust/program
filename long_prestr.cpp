#include <iostream>
#include <string>
#include <vector>
using namespace std;

string compare(string& s1,string& s2){
    int len = min(s1.size(),s2.size());
    int i;
    for(i = 0;i<len;++i){
        if(s1[i] != s2[i]) break;
    }
    return s1.substr(0,i);
}

string longestCommonPrefix(vector<string>& strs) {
    int len = strs.size();
    if(len == 0) return "";
    if(len == 1) return strs[0];
    string res = strs[0];
    for(int i = 1;i<len;++i){
        res = compare(res,strs[i]);
    }
    return res;
}

int main() {
    vector<string>vec;
    vec.push_back("abrqwr");
    vec.push_back("abcgrg");
    vec.push_back("abcvrsvsr");
    vec.push_back("abccsace");
    string temp = longestCommonPrefix(vec);
    cout<<temp<<endl;
    return 0;
}