#include <iostream>
#include <string>
#include <string.h>
/*
 *  最长重复子串
 *  前缀数组
 * */
using namespace std;

int mycmp(const void* s1,const void* s2){
    //return strcmp(*(const char* const*)s1,*(const char* const*)s2);
    return strcmp(*(const char**)s1,*(const char**)s2);
}

int maxlen(char* s1,char* s2){
    int res = 0;
    while(s1&&s2){
        if(*s1 == *s2){
            res++;
            s1++;
            s2++;
        }
        else break;
    }
    return res;
}

int lengthOfLongestSubstring(string s) {
    int len = s.size();
    char var[len];
    for(int i = 0;i<len;++i) var[i] = s[i];
    char ** temp = new char*[len];
    for(int i = 0;i<len;++i) {
        temp[i] = var+i;
    }
    qsort(temp,len,sizeof(char*),mycmp);
    int out = INT_MIN;
    for(int i = 0;i<len-1;++i){
        int len = maxlen(temp[i],temp[i+1]);
        if(len>out) out = len;
    }
    return out;
}

int main() {
    string s;
    while(cin>>s){
        int res = lengthOfLongestSubstring(s);
        cout<<res<<endl;
    }
    return 0;
}