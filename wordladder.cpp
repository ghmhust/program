#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
/*
 * leetcode 2017.10.26
 * BSF Word Ladder
 * */
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(beginWord.size() != endWord.size()) return 0;
    if(beginWord.empty() || endWord.empty()) return 0;
    unordered_set<string> myset;
    vector<string> ::iterator it;
    myset.insert(beginWord);
    for(it = wordList.begin();it!=wordList.end();++it){
        myset.insert(*it);
    }
    queue<string> qu;
    int level = 1;
    int cnt = 1;
    qu.push(beginWord);
    myset.erase(beginWord);
    while(myset.size()>0 && !qu.empty()){
        string top = qu.front();
        qu.pop();
        cnt--;
        for(int i = 0;i<top.size();++i){
            string temp = top;
            for(char j = 'a';j<='z';++j){
                if(temp[i] == j) continue;
                temp[i] = j;
                if(temp == endWord) return level+1;
                if(myset.find(temp) != myset.end()){
                    qu.push(temp);
                    myset.erase(temp);
                }
            }
        }
        //这里 66666 换层
        if(cnt == 0){
            level++;
            cnt = qu.size();
        }
    }
    return 0;
}

int main() {
    string beginword,endword;
    vector<string> wordlist = {"hot","dot","dog","lot","log","cog"};
    while(cin>>beginword>>endword){
        int res = ladderLength(beginword,endword,wordlist);
        cout<<res<<endl;
    }
    return 0;
}