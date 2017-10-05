#include <iostream>
#include <stack>
#include <string>
using namespace std;

int reverse(int& num){
    if(num>INT_MAX || num<INT_MIN) return 0;
    string str = to_string(num);
    stack<char> st;
    int len = str.size();
    string res = "";
    if(str[0] != '-'){
        for(int i = 0;i<len;++i){
            st.push(str[i]);
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
    }
    else{
        for(int i = 1;i<len;++i){
            st.push(str[i]);
        }
        res += '-';
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
    }
    long temp = stol(res);
    if(temp>INT_MAX || temp<INT_MIN) return 0;
    int resout = stoi(res);
    return resout;
}

int main() {
    int num = 0;
    while(cin>>num){
        int res = reverse(num);
        cout<<res<<endl;
    }
    return 0;
}