#include <iostream>
#include <string>
#include <vector>
/*
 * leetcode 2017.11.30
 * zigzag
 * */
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) return s;
    int len = s.size();
    string res = "";
    if(numRows == 2){
        for(int i = 0;i<len;i = i+2){
            res+=s[i];
        }
        for(int j = 1;j<len;j = j+2){
            res+=s[j];
        }
        return res;
    }
    vector<vector<char> > temp(numRows,vector<char>(len));
    for(int i = 0;i<numRows;++i){
        for(int j = 0;j<len;++j){
            temp[i][j] = ' ';
        }
    }
    int cnt = 0;
    for(int j = 0;j<len;++j){
        if(j%2 == 0) {
            for (int i = 0; i < numRows; ++i) {
                if (cnt == len) break;
                temp[i][j] = s[cnt];
                ++cnt;
            }
        }
        else{
            for(int i = numRows-1;i>0;--i){
                if (cnt == len) break;
                if (i == 0 || i == numRows - 1) {
                    continue;
                }
                temp[i][j] = s[cnt];
                ++cnt;
            }
        }
        if (cnt == len) break;
    }
    for(int i = 0;i<numRows;++i){
        for(int j = 0;j<len;++j){
            if(temp[i][j]!=' ') res += temp[i][j];
        }
    }
    return res;
}

int main() {
    string s;
    int n;
    while(cin>>s>>n){
        string res = convert(s,n);
        cout<<res<<endl;
    }
    return 0;
}