#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
/*
 * 去哪儿 2017.10.11
 * 给定n个城市，m个航班
 * 输入m个航班可来回飞，
 * 任意两个点可来回
 * 看最短乘机次数。
 * */
vector<int>vec;
void findpath(multimap<string,string> &mymp,map<string,bool> &visited,string begin,string end,int &res){
    if(begin == end){
        vec.push_back(res);
        return;
    }
    if(res > mymp.size()/2){
        return;
    }
    res++;
    visited[begin] = true;
    typedef multimap<string,string>::iterator iterTest;
    iterTest p = mymp.lower_bound(begin);
    iterTest q = mymp.upper_bound(begin);
    while(p != q)
    {   if(visited[p->second] == false) {
            findpath(mymp, visited, p->second, end, res);
            visited[p->second] = false;
            --res;
        }
        ++p;
    }
}

int main() {
    int n,m;
    string begin,end;
    while(cin>>n>>m>>begin>>end){
        multimap<string,string> mymp;
        map<string,bool> visited;
        for(int i = 0;i<m;++i){
            string temp1,temp2;
            cin>>temp1>>temp2;
            if(visited.find(temp1) == visited.end()) visited.insert(make_pair(temp1,false));
            if(visited.find(temp2) == visited.end()) visited.insert(make_pair(temp2,false));
            mymp.insert(make_pair(temp1,temp2));
            mymp.insert(make_pair(temp2,temp1));
        }
        int res = 0;
        findpath(mymp,visited,begin,end,res);
        if(vec.size() == 0){
            cout<<"DISCONNECTED"<<endl;
        }
        else {
            int minn = vec[0];
            for(int i = 0;i<vec.size();++i){
                if(vec[i]<minn) minn = vec[i];
            }
            cout<<minn<<endl;
        }
        vec.clear();
    }
    return 0;
}
