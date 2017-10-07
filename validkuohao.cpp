#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool isValid(string s) {
    int len = s.size();
    if(len%2 == 1) return false;
    vector<char> vec = {'{','[','(','}',']',')'};
    stack<char> st;
    for(int i = 0;i<len;++i){
        int j;
        for(j = 0;j<6;++j){
            if(s[i] == vec[j]) break;
        }
        if(j<3) st.push(s[i]);
        else{
            if(!st.empty()) {
                char temp = st.top();
                if (temp != vec[j - 3]) return false;
                st.pop();
            }
            else return false;
        }
    }
    if(st.empty()) return true;
    return false;
}

int main() {
    string s;
    while(cin>>s){
        bool res = isValid(s);
        if(res) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}