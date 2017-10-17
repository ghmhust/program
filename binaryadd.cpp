#include <iostream>
#include <string>
/*
 * leetcode 10。17
 * 实现二进制的加法
 * */
using namespace std;

string helper(char a, char b,int& temp){
    if(a == '0' && b == '0'){
        string var = to_string(temp);
        temp = 0;
        return var;
    }
    else if((a == '0' && b == '1')||(a == '1' && b == '0')){
        if(temp == 0) return "1";
        else{
            temp = 1;
            return "0";
        }
    }
    else{
        if(temp == 0){
            temp = 1;
            return "0";
        }
        else{
            return "1";
        }
    }
}
string addBinary(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    int temp = 0;
    int minn = len1<len2?len1:len2;
    string res = "";
    for(int i = 0;i<minn;++i){
        res = helper(a[len1-1-i],b[len2-1-i],temp)+res;
    }
    if(len1>len2){
        for(int i = 0;i<len1-len2;++i){
            res = helper(a[len1-len2-1-i],'0',temp)+res;
        }
    }
    else if(len1<len2){
        for(int i = 0;i<len2-len1;++i){
            res = helper('0',b[len2-len1-1-i],temp)+res;
        }
    }
    if(temp == 0) return res;
    else return "1"+res;
}
int main() {
    string a,b;
    while(cin>>a>>b){
        string res = addBinary(a,b);
        cout<<res<<endl;
    }
    return 0;
}